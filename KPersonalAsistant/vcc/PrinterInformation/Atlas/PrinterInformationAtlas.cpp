/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   PrinterInformationAtlas.cpp
 *  @author Eduard Garcia Castello
 *  @date   Fri Feb 15 11:28:18 CET 2008
 *  @brief  Printer Information implementation file
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#include "views_types.h"
#include "PrinterInformationAtlas.h"

#include "RedOS_pub_api.h"
#include "PackageManager.h"
#include "engine_interface.h"
#include "SKU/SkuCatalog.h"

#include "Pdl.h"
#include "Sensor.h"
#include "Components.h"
#include "Spittoons.h"
#include "ViewsPreventiveMaintenanceKit.h"

#include <fstream>
#include <cctype>
#include <sstream>

/** create a not fake instance of a PrinterInformationAtlas.
 *  @param name instance name.
 *  @return a pointer to the instance.
 */
IComponent* getPrinterInformationAtlas(std::string name)
{
  PrinterInformationAtlas * it;
  it = new PrinterInformationAtlas (name);
  assert_removable(it);
  return it;
}

PrinterInformationAtlas::PrinterInformationAtlas(std::string _instanceName) :
  IComponent(_instanceName, "PrinterInformationAtlas")
{
  log_ = new Logging(componentName(), 3);
  log_->prefix("VCC");
  log_->set(LOG_INFO);
  log_->set(LOG_WARNING);
  log_->set(LOG_ERROR);

  diskSize_ = 0;
  ramCapacity_ = 0;

  monitor_ = RedOSMonitorCreate();
  assert(monitor_ != 0);
}

/**
 * Object destructor
 */
PrinterInformationAtlas::~PrinterInformationAtlas()
{
  delete log_;
}

std::string PrinterInformationAtlas::getProductModel()
{
  return productModel;
}

std::string PrinterInformationAtlas::getProductDescription()
{
  return productDescription;
}

std::string PrinterInformationAtlas::getProductNumber()
{
  return productNumber;
}

std::string PrinterInformationAtlas::getManufacturer()
{
  return manufacturer;
}

std::string PrinterInformationAtlas::getSerialNumber()
{
  return serialNumber;
}

uint32_t PrinterInformationAtlas::getServiceId()
{
  return serviceId;
}

std::string PrinterInformationAtlas::getCurrentVersion()
{
  return currentVersion;
}

std::string PrinterInformationAtlas::getVersionDate()
{
  return versionDate;
}

std::string PrinterInformationAtlas::getSystemClock()
{
  return systemClock;
}

std::string PrinterInformationAtlas::getLanguage()
{
  return language;
}

uint64_t PrinterInformationAtlas::getDiskSize()
{
  return diskSize_;
}

ulong_t PrinterInformationAtlas::getRamCapacity()
{
  return ramCapacity_;
}

ViewsPdlCollection PrinterInformationAtlas::getPdlIterator()
{
  return pdlList_;
}

ViewsSensorCollection PrinterInformationAtlas::getSensorIterator()
{
  return sensors_;
}

ViewsPrevMaintenanceKitCollection PrinterInformationAtlas::getPreventiveMaintenanceKitIterator()
{
  return preventiveMaintenanceKit_;
}

/**
 * Method returning a reference to the Components instance
 * 
 * @return a pointer to the Components object
 * @see IComponents
 */
IComponents* PrinterInformationAtlas::getComponents()
{
  return components_;
}

/**
 * Method returning a reference to the Spittoons instance
 * 
 * @return a pointer to the Spittoons object
 * @see ISpittoons
 */
ISpittoons* PrinterInformationAtlas::getSpittoons()
{
  return spittoons_;
}

/** initialize the component.
 *  @note at initialization time components must ask for all the memory and
 *  Operating System services that they are suposed to use. No other component or
 *  hardware access is allowed.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result PrinterInformationAtlas::initialize(void)
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
Result PrinterInformationAtlas::start(void)
{
  obtainGenericInformation();
  obtainPreventiveMaintenanceKits();
  obtainPdl();
  //TODO: Check if next processes works.
  obtainDiskCapacity();
  obtainRamSize();

  //TODO: Check the package manager values. Actually, these functions call gives back a error.
  PackageManager* packageManager_ = PackageManager::instance();
  if (packageManager_ != NULL)
  {
    /*    currentVersion  = packageManager_->getCurrentVersion();
     versionDate     = packageManager_->getPackageVersion();
     systemClock     = packageManager_->getCurrentDate();*/
  }

  ViewsPdlIterator pdlIt;
  for (pdlIt = pdlList_.begin(); pdlIt!=pdlList_.end(); pdlIt++)
  {
    IPdl* aux = static_cast<IPdl*>(*pdlIt);
    log_->log(LOG_INFO, "Pdl values, %s %s\n", aux->getDescription().data(), aux->getLangLevel().data());
  }

  log_->log(LOG_INFO, "RAM capacity: %u\n", getRamCapacity());

  log_->log(LOG_INFO, "Product model: %s\n", getProductModel().c_str());

  log_->log(LOG_INFO, "Product description: %s\n", getProductDescription().c_str());

  log_->log(LOG_INFO, "Product number: %s\n", getProductNumber().c_str());

  log_->log(LOG_INFO, "Manufacturer: %s\n", getManufacturer().c_str());

  log_->log(LOG_INFO, "Serial number: %s\n", getSerialNumber().c_str());

  //creating the Components instance
  components_ = new Components(usageCounters_);

  //creating the Spittoons instance
  spittoons_ = new Spittoons(spit_,usageCounters_);

  return RESULT_OK;
}

/** perform an emergency shutdown.
 *  @note only the indispensable actions should be performed.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result PrinterInformationAtlas::emergencyShutdown(void)
{
  return RESULT_OK;
}

/** shutdown the component.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result PrinterInformationAtlas::shutdown(void)
{
  ViewsPdlIterator pdlIt;
  for (pdlIt = pdlList_.begin(); pdlIt!=pdlList_.end(); pdlIt++)
  {
    IPdl* aux = static_cast<IPdl*>(*pdlIt);
    delete aux;
    aux = 0;
  }
  
  ViewsPrevMaintenanceKitIterator kitIt;
  for (kitIt = preventiveMaintenanceKit_.begin(); kitIt!=preventiveMaintenanceKit_.end(); kitIt++)
  {
    IViewsPreventiveMaintenanceKit* aux = static_cast<IViewsPreventiveMaintenanceKit*>(*kitIt);
    delete aux;
    aux = 0;

  }
  delete components_;
  delete spittoons_;

  return RESULT_OK;
}

/** enter sleep mode.
 *  @note most likely this would mean doing some power saving activities on it.
 * 
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result PrinterInformationAtlas::enterSleepMode(void)
{
  return RESULT_OK;
}

/** abandon the sleep mode.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result PrinterInformationAtlas::exitSleepMode(void)
{
  return RESULT_OK;
}

/** provide a pointer of a named interface.
 * 
 *  @param instanceName the name of the component instance providing the interface.
 *  @param interfaceName the name of the provided interface.
 *  @param interface a pointer to the provided interface.
 */
void PrinterInformationAtlas::setInterface(std::string instanceName,
    std::string interfaceName, void *interface)
{
  log_->log(LOG_INFO, "Doing setInterface method %s\n", interfaceName.data());

  if (interfaceName == "IAnalogSensor")
  {
    sensors_.push_back(new Sensor(instanceName.c_str(),(IAnalogSensor*)&interface));
  } else if (interfaceName == "ICds")
  {
    /**NOTE:
     * Cds instance is necessary to obtain a PDL information.
     * Could be necessary for general printer information too.
     */
    cds_ = static_cast<ICds*>(interface);
  } else if (interfaceName == "IUsageCounters")
  {
    usageCounters_ = static_cast<IUsageCounters*>(interface);
  } else if (interfaceName == "ISpitServices")
  {
    spit_ = static_cast<ISpitServices*>(interface);
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
void PrinterInformationAtlas::getInterface(std::string interfaceName,
    void **interface)
{
  assert (interfaceName == "IPrinterInformation");
  *interface = static_cast<void*>(static_cast<IPrinterInformation*>(this));
}

/** Method to be called to register a new Observer.
 *  @param observer object to be registered. Later will be notified.
 */
void PrinterInformationAtlas::registerObserver(IObserver &observer)
{
  lock();
  onChangeList_.push_back( &observer );
  unlock();
}

/** Method to be called to unregister an existant Observer.
 *  @param observer object to be unregistered. No more notifications will be received.
 */
void PrinterInformationAtlas::unregisterObserver(IObserver &observer)
{
  lock();
  onChangeList_.remove(&observer);
  unlock();
}

/** This method should be called by the observable to notify all the attached observers.
 *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void PrinterInformationAtlas::notify(uint32_t reason)
{
  for (std::list <IObserver *>::iterator it = onChangeList_.begin() ; it
      != onChangeList_.end() ; it++)
  {
    (*it)->onChange(*(static_cast<IObservable*>(this)), reason);
  }
}

/** This method should be called to lock access to a resource needing mutex access.
 */
void PrinterInformationAtlas::lock()
{
  tRedResult result;

  result = RedOSMonitorLock(monitor_, RED_WAIT_FOREVER);
  assert(result == RED_SUCCESS);
}

/** This method should be called to unlock access to a resource needing mutex access.
 */
void PrinterInformationAtlas::unlock()
{
  RedOSMonitorUnlock(monitor_);
}

/**
 * Obtains generic printer information from Sku catalog.
 * 
 * @return Result
 */
Result PrinterInformationAtlas::obtainGenericInformation()
{
  SkuCatalog::Sku sku_ = SkuCatalog::getSku();

  productModel = sku_.modelNumber;
  productDescription = sku_.pnpName;
  productNumber = sku_.partNumber;
  manufacturer = "HP";

  if (cds_->find("DEV-SERIAL-NUMBER", &cdsInternalObj_ ) == Cds::CDS_SUCCESS)
    cdsInternalObj_->get(serialNumber);

  if (cds_->find("DEV-SERVICE-ID", &cdsInternalObj_ ) == Cds::CDS_SUCCESS)
    cdsInternalObj_->get(serviceId);

  return RESULT_OK;
}

/**
 * Sets parameter value with disk capacity in bytes.
 * 
 * @return Result
 */
Result PrinterInformationAtlas::obtainDiskCapacity()
{
  //TODO: Assure the Sku feature assignation.

  SkuCatalog::Sku sku_ = SkuCatalog::getSku();

  if (sku_.hasFeature("diskless"))
  {
    diskSize_ = 0;
    hasDisk_ = false;
    log_->log(LOG_INFO, "%s: Diskless\n", componentName().data());
  } else
  {
    log_->log(LOG_INFO, "%s: Get capacity from file\n", componentName().data());
    obtainDiskCapacity("/proc/ide/hda/capacity");
  }

  return RESULT_OK;
}

/**
 * With disk path passed trough parameter, obtains disk capacity and set it to diskCapacity parameter. 
 * 
 * @param const chat*
 * @param uint64_t
 * @return Result
 */
Result PrinterInformationAtlas::obtainDiskCapacity(const char* diskPath)
{
  std::ifstream in(diskPath);
  std::string capacity;

  if (in.good())
  {
    log_->log(LOG_INFO, "%s: File exist\n", componentName().data());
    getline(in, capacity);
  }
  in.close();

  diskSize_ = (uint64_t)static_cast<uint32_t>(atoi(capacity.c_str()))*512;

  return RESULT_OK;
}

/**
 * Obtains a Random Access Memory size in bytes, and stes the result in _ramSize parameter.
 * 
 * @return Result
 */
Result PrinterInformationAtlas::obtainRamSize()
{
  std::ifstream in("/proc/meminfo");
  std::string capacity;

  while (getline(in, capacity))
  {
    uint32_t index;
    if ((index = capacity.find("MemTotal:")) != std::string::npos)
    {
      index +=9;

      while (isspace((int)capacity.at(index)) && index!=capacity.length())
      {
        index++;
      }
      capacity = capacity.substr(index, capacity.length());
      index = capacity.find(" ");
      capacity = capacity.substr(0, index);
      break;
    }
  }
  ramCapacity_ = (ulong_t)(atol(capacity.c_str())*1024);
  log_->log(LOG_INFO, "RAM Capacity-value:%u\n", ramCapacity_);

  return RESULT_OK;
}

/**
 *Obtains preventive maintenance kits from CDS 
 */
Result PrinterInformationAtlas::obtainPreventiveMaintenanceKits()
{
  MAINT_ID mid = 0;
  std::string code;

  while (usageCounters_->getCode(mid, code) == UC_OK)
  {
    std::string name;
    int32_t lifePercentage;

    usageCounters_->getComposition(mid, name);
    usageCounters_->getMaintenanceKitUsage(mid, (int32_t&) lifePercentage);

    preventiveMaintenanceKit_.push_back(new ViewsPreventiveMaintenanceKit(name,code,(int16_t&)lifePercentage));

    mid++;
  }
  return RESULT_OK;
}

/**
 * Obtains PDL objects from engine.
 * 
 * @return Result
 */
Result PrinterInformationAtlas::obtainPdl()
{
  int16_t pdlTotalNumber_ = 0;

  /*NOTE:
   * Next, will obtain information from CDS
   * In this case we only obtain from CDS total number of PDL. 
   * It will be in getPDLs where we will get the single PDL information.
   */
  if (cds_->find("PDL-TOTAL-NUMBER", &cdsInternalObj_ ) == Cds::CDS_SUCCESS)
  {
    cdsInternalObj_->get((int16_t&)pdlTotalNumber_);
    for (int16_t i=1; i <= pdlTotalNumber_; i++)
    {
      std::string langLevel;
      std::string description;

      if (cds_->find(buildCdsKey("PDL-",i,"-LANG-VERSION").c_str(), &cdsInternalObj_ )
          == Cds::CDS_SUCCESS)
        cdsInternalObj_->get(langLevel);

      if (cds_->find(buildCdsKey("PDL-",i,"-DESCRIPTION").c_str(), &cdsInternalObj_ )
          == Cds::CDS_SUCCESS)
        cdsInternalObj_->get(description);

      pdlList_.push_back(new Pdl(description,langLevel));
    }
  }

  return RESULT_OK;
}

/**
 * Makes a CDS key value by means of parameters.
 * If _index parameter equals zero this function concate component parameter 
 * with element parameter, without index value.
 * 
 * @param const char*
 * @param int16_t
 * @param const char*
 * 
 * @return std::string
 */
std::string PrinterInformationAtlas::buildCdsKey(const char* component,
    int16_t index, const char* element)
{
  std::ostringstream cdsKey_;
  cdsKey_ << component << (int16_t) index << element;
  return cdsKey_.str();
}

