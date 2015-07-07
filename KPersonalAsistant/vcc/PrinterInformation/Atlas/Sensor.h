/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Sensor.h
 *  @author Eduard Garcia Castello
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  Sensor class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef SENSOR_H_
#define SENSOR_H_

#include <list>
#include "PrinterInformation/ISensor.h"
#include "AnalogSensor/IAnalogSensor.h"
#include "DigitalSensor/IDigitalSensor.h"
#include "ICallback.h"

/**
 * This printer sensor interface definition provides all necessary methods for obtaining the state,
 * value and unit type of a physical sensor.
 * Must be a observable object because printer information class must know its state.
 */
class Sensor : public ISensor
{

public:

  /**It enumerate available measurament type (digital,analog,etc...)*/
  enum ViewsMeasuramentType
  {
    DIGITAL = 0,
    ANALOG = 1,
    UNKNOWN = 2
  };

  /**It enumerate available sensor unit type.*/
  enum ViewsSensorUnitsValue
  {
    UNDEFINED = 0,
    BINARY = 1,
    MVOLTS = 2,
    MAMPS = 3,
    MCELSIUS = 4
  };

  /**It enumerate available sensor unit type.*/
  enum ViewsSensorValueType
  {
    INTEGER = 0,
    BOOLEAN = 1
  };

  /**
   * Makes a Sensor instance with values through by parameter.
   * The units value is optional.
   * 
   * @param _measurament
   * @param _valueType
   * @param *_description
   * @param units 
   */
  Sensor(uint32_t _measurament, uint32_t _valueType, char* _description,
      uint32_t units = 0);

  /**
   * Makes a Sensor instance with IAnalogSensor instance through by parameter.
   * The units value is optional.
   * 
   * @param *_analogSensor
   */
  Sensor(char const* _instanceName, IAnalogSensor* _analogSensor);

  /**
   * Makes a Sensor instance with IDigitalSensor instance through by parameter.
   * The units value is optional.
   * 
   * @param *_analogSensor
   */
  Sensor(char const* _intanceName, IDigitalSensor* _digitalSensor);

  /**
   * Return a sensor measurament type. Can be analogic or digital.
   * these constans are defined in Sensor class definition.
   * 
   * @return std::string*
   */
  uint32_t getMeasurament();

  /**
   * Return a sensor unit value. The constans definitions are in
   * Sensor class definition.
   * 
   * @return double
   * @see Sensor.h 
   */
  uint32_t getUnits();

  /**
   * Retuns a sensor value.
   * If sensor is digital it can be returned 1(true) or 0(false).
   * In analog sensor this method will return a value between -9999 to 9999. 
   * 
   * @return uint32_t 
   */
  uint32_t getSensorValue();

  /**
   * Return a value type. Ex. integrer, boolean, etc...
   * 
   * @return std::string*
   */
  uint32_t getValueType();

  /**
   * Return a sensor description
   * 
   * @return std::string*
   */
  std::string getDescription();

  /** @name IObservable required public functions.
   *  @{
   */

  /** Method to register an observer for this sensor.
   *  @param observer object to be registered. Later will be notified.
   */
  void registerObserver(IObserver &observer);

  /** Method to unregister an observer for this sensor.
   *  @param observer object to be unregistered. No more notifications will be received.
   */
  void unregisterObserver(IObserver &observer);

  /** @}
   */

  /** @name ICallback required functions.
   *  @{
   */

  /** Method to be called by the observable object.
   *  @param object that forced the execution of this method.
   *  @param reason reason for the callback, it has to be defined in the class using this callback.
   *  @return callback return value (callback dependant).
   */
  uint32_t callback(ICallbacker &object, uint32_t reason);

  /** @}
   */

  /**Object desctructor*/
  virtual ~Sensor();

protected:

private:

  /** This list will keep the list of observers for this printer information.
   */
  std::list <IObserver *> onChangeList_;
  uint32_t measuramentType;
  uint32_t units;
  uint32_t valueType;
  std::string description;
  uint32_t sensorValue;

};

#endif /*SENSOR_H_*/
