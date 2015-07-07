/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Spittoons.cpp
 *  @author Xavier Santotomas
 *  @date   Thu Feb 14 13:50:07 CET 2008
 *  @brief  Spittoons abstract implementation file
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#include "Spittoons.h"

/** public constructor.
 *   @param componentDescription is a brief description of this item
 *   @param ei is a pointer to the IUsageCounters interface
 */
Spittoons::Spittoons(ISpitServices* spit, IUsageCounters *usage)
{
  spit_ = spit;
  usage_ = usage;
}

/** public destructor.
 */
Spittoons::~Spittoons()
{
}

/**
 * Return a printer resource description. These objects are dynamic, is possible that this
 * @return an string containing the description
 */
std::string Spittoons::getDescription()
{
  return "Spittoons";
}

/**
 * Method returning the left spittoon usage
 * @return the Ink spit in right spittoon (in milliliters)
 */
double Spittoons::getLeftSpittoonUsage()
{
  Volume vol;

  //
  // Right spittoon is service station.
  //
  vol = spit_->getSpittoonInkAmount(ISpitServices::SERVICE_STATION_SPITTOON);

  return ((double) vol.getCc() + ((double) vol.getPl() * (double)1.0e-9));
}

/**
 * Method returning the right spittoon usage
 * @return Ink spit in left spittoon (in milliliters)
 */
double Spittoons::getRightSpittoonUsage()
{
  Volume vol;

  //
  // Left spittoon is "secondary".
  //
  vol = spit_->getSpittoonInkAmount(ISpitServices::SECONDARY_SPITTOON);

  return ((double) vol.getCc() + ((double) vol.getPl() * (double)1.0e-9));
}

/**
 * Method returning the Aeorosol Fan usage
 * @return the aerosol extraction working time (in hours)
 */
unsigned int Spittoons::getAerosolFanUsage()
{
  uint32_t value=0;

  UC_STATUS status;
  COUNTER_ID id;

  status = usage_->getId("SRV-AEROSOL-EXTRACTION-FAN-WORKING-TIME", id);
  if (status == UC_OK)
  {
    status = usage_->getCounter(id, value);
    assert (status == UC_OK);
  }

  return value;
}

/**
 * Method returning the counter of the length of paper printed using full bleed
 * @return the value of the counter (meters)
 */
unsigned int Spittoons::getFullBleedFoams()
{
  uint32_t value=0;

  UC_STATUS status;
  COUNTER_ID id;

  status = usage_->getId("SRV-FULL-BLEED-LENGTH-PRINTED", id);
  if (status == UC_OK)
  {
    status = usage_->getCounter(id, value);
    assert (status == UC_OK);
  }

  return value;
}

