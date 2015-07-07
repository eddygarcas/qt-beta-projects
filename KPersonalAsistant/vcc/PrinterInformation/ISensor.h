/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ISensor.h
 *  @author Eduard Garcia Castello
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  ISensor interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef ISENSOR_H_
#define ISENSOR_H_

#include <string>

#include "PrinterInformation/IPrinterResource.h"
#include "IObservable.h"

/**
 * This printer sensor interface definition provides all necessary methods for obtaining the state,
 * value and unit type of a physical sensor.
 * Must be a observable object because printer information class must know its state.
 */
class ISensor : public IPrinterResource
{

public:

  /**
   * Return a sensor measurament type. Can be analogic or digital.
   * these constans are defined in Sensor class definition.
   * 
   * @return uint32_t
   * @see Sensor.h
   */
  virtual uint32_t getMeasurament() = 0;

  /**
   * Return a sensor unit value. The constans definitions are in
   * Sensor class definition.
   * 
   * @return uint32_t
   * @see Sensor.h 
   */
  virtual uint32_t getUnits() = 0;

  /**
   * Retuns a sensor value.
   * If sensor is digital it can be returned 1(true) or 0(false).
   * In analog sensor this method will return a value between -9999 to 9999. 
   * 
   * @return uint32_t 
   */
  virtual uint32_t getSensorValue() = 0;

  /**
   * Return a value type. Ex. integrer, boolean, etc...
   * 
   * @return std::string
   */
  virtual uint32_t getValueType() = 0;

};

#endif /*ISENSOR_*/
