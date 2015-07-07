/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IComponents.h
 *  @author Xavier Santotomas
 *  @date   Wed Feb 13 14:53:20 CET 2008
 *  @brief  IComponents interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef ICOMPONENTS_H_
#define ICOMPONENTS_H_

#include "PrinterInformation/IPrinterResource.h"

/** This class describes the abstraction interface for getting the usage of some printer components 
 (as Belts, Motors, Cutters, Trailing cables....).
 */
class IComponents : public IPrinterResource
{
public:

  /**
   * Method returning the belt usage
   * @return the number of (belt) cycles
   */
  virtual unsigned int getBeltUsage() = 0;

  /**
   * Method returning the trailing cable usage
   * @return the number of (trailing cable) cycles
   */
  virtual unsigned int getTrailingCableUsage() = 0;

  /**
   * Method returning the motor usage
   * @return the number of (motor) cycles
   */
  virtual unsigned int getMotorUsage() = 0;

  /**
   * Method returning the cutter usage
   * @return the number of (cutter) cycles
   */
  virtual unsigned int getCutterUsage() = 0;

  /**
   * Method returning the tube ISS usage
   * @return the number of (tube ISS) cycles 
   */
  virtual unsigned int getTubeISSUsage() = 0;

  /**
   * Method returning the tube primer usage
   * @return the number of cc (cubic centimeters) used 
   */
  virtual unsigned int getTubePrimerUsage() = 0;

};

#endif /*ICOMPONENTS_H_*/
