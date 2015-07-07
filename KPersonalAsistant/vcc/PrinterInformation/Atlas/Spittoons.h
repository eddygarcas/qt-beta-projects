/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Spittoons.h
 *  @author Xavier Santotomas
 *  @date   Wed Feb 13 17:48:45 CET 2008
 *  @brief  Spittoons abstract header file
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef SPITTOONS_H_
#define SPITTOONS_H_

#include "UsageCounters/IUsageCounters.h"
#include "SpitServices/ISpitServices.h"
#include "PrinterInformation/ISpittoons.h"

/** This class describes the abstraction for getting the spittoons usage (and related usage counters)
 */
class Spittoons : public ISpittoons
{
public:

  /** public constructor.
   *   @param componentDescription is a brief description of this item
   *   @param ei is a pointer to the IUsageCounters interface
   */
  Spittoons(ISpitServices* spit, IUsageCounters *usage);

  /** public destructor.
   */
  virtual ~Spittoons();

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

  /** @name ISpittoons required functions.
   *  @{
   */
  /**
   * Method returning the left spittoon usage
   * @return the Ink spit in right spittoon (in milliliters)
   */
  double getLeftSpittoonUsage();

  /**
   * Method returning the right spittoon usage
   * @return Ink spit in left spittoon (in milliliters)
   */
  double getRightSpittoonUsage();

  /**
   * Method returning the Aeorosol Fan usage
   * @return the aerosol extraction working time (in hours)
   */
  unsigned int getAerosolFanUsage();

  /**
   * Method returning the counter of the length of paper printed using full bleed
   * @return the value of the counter (meters)
   */
  unsigned int getFullBleedFoams();

  /** @}
   */

private:

  /** Pointer to the Usage Counters. It allows access to his interface.
   */
  IUsageCounters *usage_;

  /**
   * Pointer to the spittoons. It allows access to his interface.
   */
  ISpitServices* spit_;
};

#endif /*SPITTOONS_H_*/
