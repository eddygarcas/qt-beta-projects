/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ISpittoons.h
 *  @author Xavier Santotomas
 *  @date   Wed Feb 13 14:53:20 CET 2008
 *  @brief  ISpittoons interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef ISPITTOONS_H_
#define ISPITTOONS_H_

#include "PrinterInformation/IPrinterResource.h"

/** This class describes the abstraction interface for getting the spittoons usage (and related usage counters)
 */
class ISpittoons : public IPrinterResource
{
public:

  /**
   * Method returning the left spittoon usage
   * @return the Ink spit in right spittoon (in milliliters)
   */
  virtual double getLeftSpittoonUsage() = 0;

  /**
   * Method returning the right spittoon usage
   * @return Ink spit in left spittoon (in milliliters)
   */
  virtual double getRightSpittoonUsage() = 0;

  /**
   * Method returning the Aeorosol Fan usage
   * @return the aerosol extraction working time (in hours)
   */
  virtual unsigned int getAerosolFanUsage() = 0;

  /**
   * Method returning the counter of the length of paper printed using full bleed
   * @return the value of the counter (meters)
   */
  virtual unsigned int getFullBleedFoams() = 0;

};

#endif /*ISPITTOONS_H_*/
