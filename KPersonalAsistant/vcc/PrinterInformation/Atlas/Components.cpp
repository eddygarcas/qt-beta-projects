/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Components.cpp
 *  @author Xavier Santotomas
 *  @date   Thu Feb 14 13:46:59 CET 2008
 *  @brief  Components abstract implementation file
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#include "Components.h"

/** public constructor.
 *   @param componentDescription is a brief description of this item
 *   @param ei is a pointer to the IUsageCounters interface
 */
Components::Components(IUsageCounters *usage)
{
  usage_ = usage;
}

/** public destructor.
 */
Components::~Components()
{
}

/**
 * Return a printer resource description. These objects are dynamic, is possible that this
 * @return an string containing the description
 */
std::string Components::getDescription()
{
  //TODO: should be localized
  return "Components";
}

/**
 * Method returning the belt usage
 * @return the number of (belt) cycles
 */
unsigned int Components::getBeltUsage()
{
  uint32_t value=0;

  UC_STATUS status;
  COUNTER_ID id;

  status = usage_->getId("SRV-BELT-NUMBER-OF-SCAN-AXIS-CYCLES", id);
  if (status == UC_OK)
  {
    status = usage_->getCounter(id, value);
    assert (status == UC_OK);
  }

  return value;
}

/**
 * Method returning the trailing cable usage
 * @return the number of (trailing cable) cycles
 */
unsigned int Components::getTrailingCableUsage()
{
  uint32_t value=0;

  UC_STATUS status;
  COUNTER_ID id;

  status = usage_->getId("SRV-CABLE-NUMBER-OF-SCAN-AXIS-CYCLES", id);
  if (status == UC_OK)
  {
    status = usage_->getCounter(id, value);
    assert (status == UC_OK);
  }

  return value;
}

/**
 * Method returning the motor usage
 * @return the number of (motor) cycles
 */
unsigned int Components::getMotorUsage()
{
  uint32_t value=0;

  UC_STATUS status;
  COUNTER_ID id;

  status = usage_->getId("SRV-MOTOR-NUMBER-OF-SCAN-AXIS-CYCLES", id);
  if (status == UC_OK)
  {
    status = usage_->getCounter(id, value);
    assert (status == UC_OK);
  }

  return value;
}

/**
 * Method returning the cutter usage
 * @return the number of (cutter) cycles
 */
unsigned int Components::getCutterUsage()
{
  uint32_t value=0;

  UC_STATUS status;
  COUNTER_ID id;

  status = usage_->getId(
      "SRV-CUTTER-AND-LINEAR-BLADE-NUMBER-OF-SCAN-AXIS-CYCLES", id);
  if (status == UC_OK)
  {
    status = usage_->getCounter(id, value);
    assert (status == UC_OK);
  }

  return value;
}

/**
 * Method returning the tube ISS usage
 * @return the number of (tube ISS) cycles 
 */
unsigned int Components::getTubeISSUsage()
{
  uint32_t value=0;

  UC_STATUS status;
  COUNTER_ID id;

  status = usage_->getId("SRV-TUBES-NUMBER-OF-SCAN-AXIS-CYCLES", id);
  if (status == UC_OK)
  {
    status = usage_->getCounter(id, value);
    assert (status == UC_OK);
  }

  return value;
}

/**
 * Method returning the tube primer usage
 * @return the number of cc (cubic centimeters) used 
 */
unsigned int Components::getTubePrimerUsage()
{
  uint32_t value=0;

  UC_STATUS status;
  COUNTER_ID id;

  status = usage_->getId("SRV-PRIMER-INK-VOLUME", id);
  if (status == UC_OK)
  {
    status = usage_->getCounter(id, value);
    assert (status == UC_OK);
  }

  return value;
}

