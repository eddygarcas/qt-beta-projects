/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   SettingsManagerAtlas.cpp
 *  @author Jesus Barahona
 *  @date   Mon Jan 07 17:29:11 CEST 2007
 *  @brief  Settings Manager Atlas Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 */
////////////////////////////////////////////////////////////////////////////// 

#include "views_types.h"
#include "SettingsManagerAtlas.h"
#include "Logging.h"
#include "../SettingsStaticInformation.h"

#include "CdsInt32ContinuousSetting.h"
#include "CdsInt16ContinuousSetting.h"
#include "CdsInt8ContinuousSetting.h"
#include "CdsRangeContinuousSetting.h"

#include "CdsInt32DiscreteSetting.h"
#include "CdsInt16DiscreteSetting.h"
#include "CdsInt8DiscreteSetting.h"
#include "CdsBoolDiscreteSetting.h"

#include "CdsStringSetting.h"

/** create an Atlas instance of a SettingsManager.
 @param name instance name.
 @return a pointer to the instance.
 */
IComponent * getSettingsManagerAtlas(std::string name)
{
  SettingsManagerAtlas * it;
  it = new SettingsManagerAtlas (name);
  assert (it);
  return it;
}

/** public constructor.
 @param instanceName instance name.
 */
SettingsManagerAtlas::SettingsManagerAtlas(std::string instanceName) :
  IComponent(instanceName, "SettingsManagerAtlas")
{
  //
  // Mutual exclusion semaphore.
  //
  monitor_ = RedOSMonitorCreate();
  assert(monitor_ != 0);

  /* This class a Singleton (only one instance is created in the Metagod graph). 
   If we had to create more than one instance, then the log_ should be static.
   */
  log_ = new Logging(componentName(),3);
  log_->prefix("VCC");
  log_->set(LOG_INFO);
  log_->set(LOG_WARNING);
  log_->set(LOG_ERROR);
}

/** public destructor.
 */
SettingsManagerAtlas::~SettingsManagerAtlas()
{
  SettingsIterator it;
  IViewsSetting *del_aux;
  for (it = settings.begin();it != settings.end();it++)
  {
    del_aux = static_cast<IViewsSetting*>(*it);
    delete del_aux;
    del_aux = 0;
  }
}

/** Method to get an IViewsSetting
 @return the IViewsSetting that corresponds with the id.
 */
IViewsSetting* SettingsManagerAtlas::getSetting(int32_t id)
{
  return (id >= ViewsSetting::min_setting_range_ && id
      <=ViewsSetting::max_setting_range_) ? settings[id] : NULL;
}

/** initialize the component.
 *  @note at initialization time components must ask for all the memory and
 *  Operating System services that they are suposed to use. No other component or
 *  hardware access is allowed.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result SettingsManagerAtlas::initialize(void)
{
  return RESULT_OK;
}

/** start the component. 
 *  @note components should perform the hardware related actions
 *  to turn into an operative status either through drivers or other
 *  components.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result SettingsManagerAtlas::start(void)
{
  log_->log(LOG_INFO, "Starting Settings Manager\n");
  
  lock();
  createSettings();
  unlock();
  
  return RESULT_OK;
}

/** perform an emergency shutdown.
 *  @note only the indispensable actions should be performed.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result SettingsManagerAtlas::emergencyShutdown(void)
{
  // nothing indispensable to do...
  return RESULT_OK;
}

/** shutdown the component.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result SettingsManagerAtlas::shutdown(void)
{
  return RESULT_OK;
}

/** enter sleep mode.
 *  @note most likely this would mean doing some power saving activities on it.
 * 
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result SettingsManagerAtlas::enterSleepMode(void)
{
  return RESULT_OK;
}

/** abandon the sleep mode.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result SettingsManagerAtlas::exitSleepMode(void)
{
  return RESULT_OK;
}

/** provide a pointer of a named interface.
 * 
 *  @param instanceName the name of the component instance providing the interface.
 *  @param interfaceName the name of the provided interface.
 *  @param interface a pointer to the provided interface.
 */
void SettingsManagerAtlas::setInterface(std::string instanceName,
    std::string interfaceName, void *interface)
{
  if (interfaceName == "ICds")
  {
    cds_ = static_cast<ICds*>(interface);
  } else
  {
    assert_removable(0);
  }
}

/** query for an an interface that you implement.
 * 
 *  @param interfaceName the name of the interface that other is asking you to provide.
 *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
 */
void SettingsManagerAtlas::getInterface(std::string interfaceName,
    void **interface)
{
  assert (interfaceName == "ISettingsManager");
  *interface = static_cast<void*>(static_cast<ISettingsManager*>(this));
}

/** This method should be called to lock access to a resource needing mutex access.
 */
void SettingsManagerAtlas::lock()
{
  tRedResult result;

  result = RedOSMonitorLock(monitor_, RED_WAIT_FOREVER);
  assert(result == RED_SUCCESS);
}

/** This method should be called to unlock access to a resource needing mutex access.
 */
void SettingsManagerAtlas::unlock()
{
  RedOSMonitorUnlock(monitor_);
}

/** 
 * Method to create an array with all the settings of the system.
 * 
 * @return RESULT_OK if successful, RESULT_ERROR otherwise.
 */
Result SettingsManagerAtlas::createSettings()
{

  SettingUtils::initialize(*(static_cast<SettingsManagerAtlas*>(this)));

  IViewsSetting* aux;

  for (unsigned int i = 0; i < ( sizeof(ViewsSetting::settingsType) / sizeof (*ViewsSetting::settingsType) ); i++)
  {
    switch (ViewsSetting::settingsType[i])
    {
      case ViewsSetting::CDSINT8CONTINUOUS:
      aux = new CdsInt8ContinuousSetting(i, cds_);
      break;
      case ViewsSetting::CDSINT16CONTINUOUS:
      aux = new CdsInt16ContinuousSetting(i, cds_);
      break;
      case ViewsSetting::CDSINT32CONTINUOUS:
      aux = new CdsInt32ContinuousSetting(i, cds_);
      break;
      case ViewsSetting::CDSINT8DISCRETE:
      aux = new CdsInt8DiscreteSetting(i, cds_,optionLabels_[ViewsSetting::cdsObjNames[i]],optionValues_[ViewsSetting::cdsObjNames[i]]);
      break;
      case ViewsSetting::CDSINT16DISCRETE:
      aux = new CdsInt16DiscreteSetting(i, cds_,optionLabels_[ViewsSetting::cdsObjNames[i]],optionValues_[ViewsSetting::cdsObjNames[i]]);
      break;
      case ViewsSetting::CDSINT32DISCRETE:
      aux = new CdsInt32DiscreteSetting(i, cds_,optionLabels_[ViewsSetting::cdsObjNames[i]],optionValues_[ViewsSetting::cdsObjNames[i]]);
      break;
      case ViewsSetting::CDSBOOLDISCRETE:
      aux = new CdsBoolDiscreteSetting(i, cds_,optionLabels_[ViewsSetting::cdsObjNames[i]],optionValues_[ViewsSetting::cdsObjNames[i]]);
      break;
      case ViewsSetting::CDSSTRING:
      aux = new CdsStringSetting(i, cds_,allowedChars_[ViewsSetting::cdsObjNames[i]]);
      break;
      case ViewsSetting::CDSRANGECONTINUOUS:
      aux = new CdsRangeContinuousSetting(i,cds_);
      default:
      assert_removable(0);
    }
    settings.push_back(aux);
  }
  return RESULT_OK;
}

/**
 * By means of this function we wil be able to transform a array to standard vector.
 * You should pass throug parameter the array and its size.
 * 
 * @param _arr[]
 * @param _size
 * @return std::vector<int>
 */
std::vector<int32_t> SettingsManagerAtlas::arrayToVector(int32_t _arr[], int32_t _size)
{
  int32_t index;
  std::vector<int32_t> aux;
  for (index = 0; index < _size; index++)
  {
    aux.push_back(_arr[index]);
  }
  return aux;
}

std::vector<char> SettingsManagerAtlas::arrayToVector(char _arr[], int32_t _size)
{
  unsigned int index;
  std::vector<char> aux;
  for (index = 0; index < _size; index++)
  {
    aux.push_back(_arr[index]);
  }
  return aux;
}

/**
 * Adds label array option in internal vector.
 * 
 * @param _arrl[]
 * @param _size
 */
void SettingsManagerAtlas::addLabelOption(std::string cdsObject_, int32_t _arrl[],
    int32_t _size)
{
  optionLabels_.insert(make_pair(cdsObject_, arrayToVector(_arrl, _size)));
}

/**
 * Adds value array option in internal vector.
 * 
 * @param _arrv[]
 * @param _size 
 */
void SettingsManagerAtlas::addValueOption(std::string cdsObject_, int32_t _arrv[],
    int32_t _size)
{
  optionValues_.insert(make_pair(cdsObject_, arrayToVector(_arrv, _size)));
}

/**
 * Adds value array option in internal vector.
 * 
 * @param _arrv[]
 * @param _size 
 */
void SettingsManagerAtlas::addAllowedCharsOption(std::string cdsObject_,
    char _arrc[], int32_t _size)
{
  allowedChars_.insert(make_pair(cdsObject_, arrayToVector(_arrc, _size)));
}
