#include "Sensor.h"

Sensor::Sensor(uint32_t _measure, uint32_t _type, char* _descr, uint32_t _unit) :
  units(_unit)
{
  measuramentType = _measure;
  valueType = _type;
  description = _descr;
}

Sensor::Sensor(char const* instanceName_, IAnalogSensor* analogSensor_)
{
  analogSensor_->getValue(sensorValue);
  description = instanceName_;
  measuramentType = Sensor::ANALOG;
  units = Sensor::MVOLTS;
  valueType = Sensor::INTEGER;
}

Sensor::Sensor(char const* instanceName_, IDigitalSensor* digitalSensor_)
{
  bool digitalValue_;
  digitalSensor_->getValue(digitalValue_);
  sensorValue = static_cast<int>(digitalValue_);
  description = instanceName_;
  measuramentType = Sensor::DIGITAL;
  valueType = Sensor::BOOLEAN;
}

uint32_t Sensor::getMeasurament()
{
  return measuramentType;
}

uint32_t Sensor::getUnits()
{
  return units;
}

uint32_t Sensor::getSensorValue()
{
  return sensorValue;
}

uint32_t Sensor::getValueType()
{
  return valueType;
}

std::string Sensor::getDescription()
{
  return description;
}

Sensor::~Sensor()
{

}
