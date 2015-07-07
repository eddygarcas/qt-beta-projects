/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   PrinterInformationAtlas.h
 *  @author Eduard Garcia Castello
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  PrinterInformation (Atlas) definition file.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef PRINTERINFORMATIONATLAS_H_
#define PRINTERINFORMATIONATLAS_H_

#include <list>

#include "PrinterInformation/IPrinterInformation.h"
#include "UsageCounters/IUsageCounters.h"
#include "SpitServices/ISpitServices.h"
#include "IComponent.h"
#include "Cds/ICds.h"
/**
 * Atlas printer information definition. All values obtained from this implementation comes from engine, 
 * and establishes relationship to metagod by means of IComponent interface.
 */
class PrinterInformationAtlas : public IPrinterInformation, public IComponent
{
public:
  
  /**
   * Constructor.
   * InstanceName value passed through parameter indicates the IComponent instance name.
   * @param std::string
   */  
  PrinterInformationAtlas(std::string instanceName);

  /** @name IPrinterInformation required functions.
   *  @{
   */

  /**
   * Return a product model name.
   * 
   * @return std::string
   */
  std::string getProductModel();

  /**
   * Return a product description.
   * 
   * @return std::string
   */
  std::string getProductDescription();

  /**
   * Return a product number (named Part number in CDS).
   * 
   * @return std::string
   */
  std::string getProductNumber();

  /**
   * Return a manufacturer name.
   * 
   * @return std::string
   */
  std::string getManufacturer();

  /**
   * Return a serial number.
   * 
   * @return std::string
   */
  std::string getSerialNumber();

  /**
   * Return a service id.
   * 
   * @return uint32_t
   */
  uint32_t getServiceId();

  /**
   * Returns the current firmware version as given by the PackageManager. 
   * If asked for the first time, it caches the firmware version, so the next time will not ask the PackageManager.
   * 
   * @return a String corresponding to the current firware version
   */
  std::string getCurrentVersion();

  /**
   * Returns the current date and caches the information.
   * 
   * @return the current firmware package Date or null if an error occurs.
   */
  std::string getVersionDate();

  /**
   * Return system current time.
   * 
   * @return std::string
   */
  std::string getSystemClock();

  /**
   * Return a system locale language std::string from locale instance.
   * 
   * @return std::string Language in standard format.
   */
  std::string getLanguage();

  /**
   * Return the total disks size, this size will be returned with bytes.
   * 
   * @return uint32_t
   */
  uint64_t getDiskSize();

  /**
   * Return the Ram capacity in bytes.
   * 
   * @return uint32_t
   */
  ulong_t getRamCapacity();

  /**
   * Return a standard list with all PDL values.
   * 
   * @return ViewsPdlCollection
   * @see IPdl
   */
  ViewsPdlCollection getPdlIterator();

  /**
   * Return a standard list with all Sensor values.
   * 
   * @return ViewsSensorCollection
   * @see ISensor
   */
  ViewsSensorCollection getSensorIterator();

  /**
   * Return a standard list with all Preventive maintenance kit values.
   * 
   * @return ViewsPrevMaintenanceKitCollection
   * @see IPreventiveMaintenanceKit
   */
  ViewsPrevMaintenanceKitCollection getPreventiveMaintenanceKitIterator();

  /**
   * Method returning a reference to the Components instance
   * 
   * @return a pointer to the Components object
   * @see IComponents
   */
  IComponents* getComponents();

  /**
   * Method returning a reference to the Spittoons instance
   * 
   * @return a pointer to the Spittoons object
   * @see ISpittoons
   */
  ISpittoons* getSpittoons();

  /**
   * @}
   */

  /** @name IObservable required public functions.
   *  @{
   */

  /** Method to register an observer for this views pen.
   *  @param observer object to be registered. Later will be notified.
   */
  void registerObserver(IObserver &observer);

  /** Method to unregister an observer for this views pen.
   *  @param observer object to be unregistered. No more notifications will be received.
   */
  void unregisterObserver(IObserver &observer);

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

  /**Class destructor
   */
  virtual ~PrinterInformationAtlas();

protected:

  /** @name IObservable required protected functions.
   *  @{
   */

  /** This method should be called by the observable to notify all the attached observers of this views pen.
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

  /**
   * Obtains generic printer information from Sku catalog.
   * 
   * @return Result
   */
  Result obtainGenericInformation(); 
  
  /**
   * Sets parameter value with disk capacity in bytes.
   * 
   * @return Result
   */
  Result obtainDiskCapacity();

  /**
   * With disk path passed trough parameter, obtains disk capacity and set it to diskCapacity parameter. 
   * 
   * @param const char*
   * @return Result
   */
  Result obtainDiskCapacity(const char* _diskPath);
  
  /**
   * Obtains PDL objects from engine.
   * 
   * @return Result
   */
  Result obtainPdl();
 
  /**
   *Obtains preventive maintenance kits from CDS 
   */
  Result obtainPreventiveMaintenanceKits();
  
  /**
   * Obtains a Random Access Memory size in bytes, and sets the result in _ramSize parameter.
   * 
   * @return Result
   */
  Result obtainRamSize();

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
  std::string buildCdsKey(const char* _component, int16_t _index,
      const char* _element);
  
  /** This list will keep the list of observers for this printer information.
   */
  std::list <IObserver *> onChangeList_;
  /**Product model*/
  std::string productModel;
  /**Product description*/
  std::string productDescription;
  /**Serial number*/
  std::string productNumber;
  /**Manufacturer name*/
  std::string manufacturer;
  /**Printer serial number*/
  std::string serialNumber;
  uint32_t serviceId;
  /**Firmware version*/
  std::string currentVersion;
  /**Firmware version date*/
  std::string versionDate;
  /**In time system clock*/
  std::string systemClock;
  /**Language defined in machine*/
  std::string language;
  /**It indicates disk size in bytes*/
  uint64_t diskSize_;
  /**Its value is true if printer has disk and false in otherwise.*/
  bool hasDisk_;
  /**It indicates RAM capacity in kilo bytes.*/
  ulong_t ramCapacity_;
  /**List which holds sensor instances*/
  ViewsSensorCollection sensors_;
  /**List which holds sensor instances*/
  ViewsPrevMaintenanceKitCollection preventiveMaintenanceKit_;
  /**List which holds Pdl instances*/
  ViewsPdlCollection pdlList_;
  /**Cds interface instance class.*/
  ICds* cds_;
  /**Cds internal class object*/
  Cds::CdsObject* cdsInternalObj_;
  /**
   * To guarantee mutual exclusion when accessing onChangeList_
   */
  tRedOSMonitor monitor_;
  /**
   * To write logs in the system
   */
  Logging* log_;
  
  /**
   * Reference to the Components instance
   */
  IComponents* components_;
    
  /**
   * Reference to the Spittoons instance
   */
  ISpittoons* spittoons_;
  
  /**
   * UsageCounters interface instance class.
   */
  IUsageCounters* usageCounters_;

  /**
   * SpitServices interface instance class.
   */
  ISpitServices* spit_;

};

#endif /*PRINTERINFORMATIONATLAS_H_*/
