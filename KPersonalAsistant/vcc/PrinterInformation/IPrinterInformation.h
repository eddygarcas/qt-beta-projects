/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IPrinterInformation.h
 *  @author Eduard Garcia Castello
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  IPrinterInformation interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef IPRINTERINFORMATION_H_
#define IPRINTERINFORMATION_H_

#include <string>

#include "atlas_types.h"
#include "IObserver.h"
#include "IObservable.h"
#include "PrinterInformation/ISensor.h"
#include "PrinterInformation/IViewsPreventiveMaintenanceKit.h"
#include "PrinterInformation/IPdl.h"
#include "PrinterInformation/ISpittoons.h"
#include "PrinterInformation/IComponents.h"

#include <string>
#include <vector>


/**
 * A Collection of discrete setting options
 */
typedef std::vector<IPdl*>    ViewsPdlCollection;
typedef std::vector<ISensor*> ViewsSensorCollection;
typedef std::vector<IViewsPreventiveMaintenanceKit*> ViewsPrevMaintenanceKitCollection;
/**
 * To iterate a DiscreteOptionsCollection.
 */
typedef ViewsPdlCollection::iterator    ViewsPdlIterator;
typedef ViewsSensorCollection::iterator ViewsSensorIterator;
typedef ViewsPrevMaintenanceKitCollection::iterator ViewsPrevMaintenanceKitIterator;

/**
 * It provide all necessary information about printer, such as model, serial number, system resources, 
 * configuration states and phisic components values. 
 * Inherits from IObserver and IObservable allows to other objects of class hierarchy acceding to its information.
 */
class IPrinterInformation : public IObservable
{
public:

  /**
   * Return a product model name.
   * 
   * @return std::string
   */
  virtual std::string getProductModel() = 0;

  /**
   * Return a product description.
   * 
   * @return std::string
   */
  virtual std::string getProductDescription() = 0;

  /**
   * Return a product number (named Part number in CDS).
   * 
   * @return std::string
   */
  virtual std::string getProductNumber() = 0;

  /**
   * Return a manufacturer name.
   * 
   * @return std::string
   */
  virtual std::string getManufacturer() = 0;

  /**
   * Return a serial number.
   * 
   * @return std::string
   */
  virtual std::string getSerialNumber() = 0;

  /**
   * Return a service id.
   * 
   * @return uint32_t
   */
  virtual uint32_t getServiceId() = 0;

  /**
   * Returns the current firmware version as given by the PackageManager. 
   * If asked for the first time, it caches the firmware version, so the next time will not ask the PackageManager.
   * 
   * @return a String corresponding to the current firware version
   */
  virtual std::string getCurrentVersion() = 0;

  /**
   * Returns the current date and caches the information.
   * 
   * @return the current firmware package Date or null if an error occurs.
   */
  virtual std::string getVersionDate() = 0;

  /**
   * Return system current time.
   * 
   * @return std::string
   */
  virtual std::string getSystemClock() = 0;

  /**
   * Return a system locale language std::string from locale instance.
   * 
   * @return std::string Language in standard format.
   */
  virtual std::string getLanguage() = 0;

  /**
   * Return the total disks size, this size will be returned with bytes.
   * 
   * @return uint32_t
   */
  virtual uint64_t getDiskSize() = 0;

  /**
   * Return the Ram capacity in bytes.
   * 
   * @return uint32_t
   */
  virtual ulong_t getRamCapacity() = 0;

  /**
   * Return a standard list with all PDL values.
   * 
   * @return std::list<IPrinterResource*>
   * @see IPdl
   */
  virtual ViewsPdlCollection getPdlIterator() = 0;

  /**
   * Return a standard list with all Sensor values.
   * 
   * @return std::list<IPrinterResource*>
   * @see ISensor
   */
  virtual ViewsSensorCollection getSensorIterator() = 0;

  /**
   * Return a standard list with all Preventive maintenance kit values.
   * 
   * @return std::list<IPrinterResource*>
   * @see IPreventiveMaintenanceKit
   */
  virtual ViewsPrevMaintenanceKitCollection
      getPreventiveMaintenanceKitIterator() = 0;

  /**
   * Method returning a reference to the Components instance
   * 
   * @return a pointer to the Components object
   * @see IComponents
   */
  virtual IComponents* getComponents() = 0;

  /**
   * Method returning a reference to the Spittoons instance
   * 
   * @return a pointer to the Spittoons object
   * @see ISpittoons
   */
  virtual ISpittoons* getSpittoons() = 0;

};

#endif /*IPRINTERINFORMATION_H_*/
