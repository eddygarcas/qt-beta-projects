/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IPreventiveMaintenanceKit.h
 *  @author Eduard Garcia Castello
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  IPreventiveMaintenanceKit inteface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef IVIEWSPREVENTIVEMAINTENANCEKIT_H_
#define IVIEWSPREVENTIVEMAINTENANCEKIT_H_

#include <string>
#include "atlas_types.h"
#include "PrinterInformation/IPrinterResource.h"
#include "IObservable.h"

/**
 * Preventive maintenance kit interface definition.
 * Must be a observable object because printer information class must know its state.
 */
class IViewsPreventiveMaintenanceKit : public IPrinterResource
{

public:

  /**
   * It returns preventive maintenance kit percent used.
   * 
   * @return uint16_t
   */
  virtual uint16_t getPercentUsed() = 0;

  /**
   * Return part number.
   * 
   * @return std::string
   */
  virtual std::string getPartNumber() = 0;

};
#endif /*IPREVENTIVEMAINTENANCEKIT_H_*/
