/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Components.h
 *  @author Xavier Santotomas
 *  @date   Wed Feb 13 17:41:49 CET 2008
 *  @brief  Components abstract header file
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef COMPONENTS_H_
#define COMPONENTS_H_

#include "UsageCounters/IUsageCounters.h"
#include "PrinterInformation/IComponents.h"

/** This class describes the abstraction for getting the usage of some printer components 
 (as Belts, Motors, Cutters, Trailing cables....).
 */
class Components : public IComponents
{
public:

  /** public constructor.
   *   @param componentDescription is a brief description of this item
   *   @param ei is a pointer to the IUsageCounters interface
   */
  Components(IUsageCounters *usage);

  /** public destructor.
   */
  virtual ~Components();

  /** @name IPrinterResource required functions.
   *  @{
   */
  /**
   * Return a printer resource description. These objects are dynamic, is possible that this
   * @return an string containing the description
   */
  std::string getDescription();

  /** @}
   */

  /** @name IComponents required functions.
   *  @{
   */
  /**
   * Method returning the belt usage
   * @return the number of (belt) cycles
   */
  unsigned int getBeltUsage();

  /**
   * Method returning the trailing cable usage
   * @return the number of (trailing cable) cycles
   */
  unsigned int getTrailingCableUsage();

  /**
   * Method returning the motor usage
   * @return the number of (motor) cycles
   */
  unsigned int getMotorUsage();

  /**
   * Method returning the cutter usage
   * @return the number of (cutter) cycles
   */
  unsigned int getCutterUsage();

  /**
   * Method returning the tube ISS usage
   * @return the number of (tube ISS) cycles 
   */
  unsigned int getTubeISSUsage();

  /**
   * Method returning the tube primer usage
   * @return the number of cc (cubic centimeters) used 
   */
  unsigned int getTubePrimerUsage();

  /** @}
   */

private:

  /** Pointer to the usage counters. It allows access to his interface.
   */
  IUsageCounters *usage_;

};

#endif /*COMPONENTS_H_*/
