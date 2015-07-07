/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   SettingsManagerAtlas.h
 *  @author Jesus Barahona
 *  @date   Mon Jan 07 17:29:11 CEST 2007
 *  @brief  Settings Manager Atlas Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2003.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef SETTINGSMANAGERATLAS_H_
#define SETTINGSMANAGERATLAS_H_

#include "ISettingsManager.h"
#include "Cds/ICds.h"
#include "IComponent.h"
#include "IViewsSetting.h"
#include "RedOS_pub_api.h"
#include <vector>
#include <string>
#include <map>

/**
 * A Collection of discrete setting options
 */
typedef std::vector<IViewsSetting*> SettingsCollection;

/**
 * To iterate a DiscreteOptionsCollection.
 */
typedef SettingsCollection::iterator SettingsIterator;


/** This class provides an "Atlas" implementation of the Settings Manager interface.
 */
class SettingsManagerAtlas : public ISettingsManager, public IComponent {
public:

  /**
   * Public constructor.
   * 
   * @param instanceName instance name.
   */
  SettingsManagerAtlas(std::string instanceName);

  /** public destructor.
   */
  virtual ~SettingsManagerAtlas();

  /*
   * These method initialize all vectors which take part in ViewsSettings process.
   * Is implemented in SettingStaticInformation.h file which is generated in build time.
   */

  /**
   * Adds label array option in internal vector.
   * 
   * @param std::string
   * @param _arrl[]
   * @param size
   */
  void addLabelOption(std::string _objectName, int32_t _arrl[], int32_t size);

  /**
   * Adds value array option in internal vector.
   * 
   * @param std::string
   * @param _arrv[]
   * @param size
   */
  void addValueOption(std::string _objectName, int32_t _arrv[], int32_t size);

  /**
   * Adds value array option in internal vector.
   * 
   * @param int[]
   */
  void
      addAllowedCharsOption(std::string _objectName, char _arrc[], int32_t size);

  /** @name SettingsManager required methods.
   @{
   */
  /** Method to get an IViewsSetting
   @return the IViewsSetting that corresponds with the id.
   */
  IViewsSetting* getSetting(int32_t id);

  /** @}
   */

  /** @name IComponent required functions.
   *  @{
   */

  /** initialize the component.
   *  @note at initialization time components must ask for all the memory and
   *  Operating System services that they are suposed to use. No other component or
   *  hardware access is allowed.
   * 
   *  @return RESULT_OK if successful, the failure code otherwise.
   */
  Result initialize(void);

  /** start the component. 
   *  @note components should perform the hardware related actions
   *  to turn into an operative status either through drivers or other
   *  components.
   * 
   *  @return RESULT_OK if successful, the failure code otherwise.
   */
  Result start(void);

  /** perform an emergency shutdown.
   *  @note only the indispensable actions should be performed.
   *
   *  @return  RESULT_OK if successful, the failure code otherwise.
   */
  Result emergencyShutdown(void);

  /** shutdown the component.
   * 
   *  @return RESULT_OK if successful, the failure code otherwise.
   */
  Result shutdown(void);

  /** enter sleep mode.
   *  @note most likely this would mean doing some power saving activities on it.
   * 
   *  @return  RESULT_OK if successful, the failure code otherwise.
   */
  Result enterSleepMode(void);

  /** abandon the sleep mode.
   *
   *  @return  RESULT_OK if successful, the failure code otherwise.
   */
  Result exitSleepMode(void);

  /** provide a pointer of a named interface.
   * 
   *  @param instanceName the name of the component instance providing the interface.
   *  @param interfaceName the name of the provided interface.
   *  @param interface a pointer to the provided interface.
   */
  void setInterface(std::string instanceName, std::string interfaceName,
      void *interface);

  /** query for an an interface that you implement.
   * 
   *  @param interfaceName the name of the interface that other is asking you to provide.
   *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
   */
  void getInterface(std::string interfaceName, void **interface);

  /** @}
   */

protected:

  /** @name SettingsManagerAtlas protected methods.
   @{
   */

  /** This method should be called by the observable to notify all the attached observers of this views carriage.
   *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
   */
  void notify(uint32_t reason);

  /** @}
   */

private:

  /** This method should be called to lock access to a resource needing mutex access.
   */
  void lock();

  /** This method should be called to unlock access to a resource needing mutex access.
   */
  void unlock();

  /* Method to create an array with all the settings of the system.
   * 
   *  @return RESULT_OK if successful, RESULT_ERROR otherwise.
   */
  Result createSettings();

  /**
   * With this method we want to perform a transformation of integer array to standard vector.
   * 
   * @param arr[]
   * @param size
   * @return std::vector<int>
   */
  std::vector<int32_t> arrayToVector(int32_t arr[], int32_t size);

  /**
   * With this method we want to perform a transformation of character array to standard vector.
   * 
   * @param arr[]
   * @param size
   * @return std::vector<int>
   */
  std::vector<char> arrayToVector(char arr[], int32_t size);

  /** The pointer to the engine CDS instance. It allows access to his interface.
   */
  ICds *cds_;

  /**
   * To guarantee mutual exclusion when accessing onChangeList_.
   */
  tRedOSMonitor monitor_;

  /**
   * To write logs in the system
   */
  Logging* log_;

  /** Array where are stored all the Views Settings of the System.*/
  SettingsCollection settings;

  /**Vector which contains all option label key*/
  std::map<std::string,std::vector<int32_t> > optionLabels_;

  /**Vector which contaion all values of option*/
  std::map<std::string,std::vector<int32_t> > optionValues_;

  /**Vector which contaion all values of option*/
  std::map<std::string,std::vector<char> > allowedChars_;

};

#endif
