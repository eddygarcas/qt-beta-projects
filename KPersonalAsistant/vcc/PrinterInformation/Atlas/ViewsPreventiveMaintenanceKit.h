/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   PreventiveMaintenanceKit.h
 *  @author Eduard Garcia Castello
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  PreventiveMaintenanceKit class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef PREVENTIVEMAINTENANCEKIT_H_
#define PREVENTIVEMAINTENANCEKIT_H_

#include <list>
#include "PrinterInformation/IViewsPreventiveMaintenanceKit.h"
#include "ICallback.h"
#include "ICallbacker.h"
#include "IObserver.h"

/**
 * Preventive maintenance kit interface definition.
 * Must be a observable object because printer information class must know its state.
 */
class ViewsPreventiveMaintenanceKit : public IViewsPreventiveMaintenanceKit
{

public:

  /**
   * Makes a previentive maintenance kit with descrption and part number values through by parameter
   * 
   * @param *_description
   * @param *_partNumber
   */
  ViewsPreventiveMaintenanceKit(std::string& _description,
      std::string& _partNumber, uint16_t _percentUsed = 0);

  /**
   * Return a Preventive maintenance kit description. These objects are dynamic, is possible that this
   * function retun null.
   * 
   * @return std::string*
   */
  std::string getDescription();

  /**
   * Return part number.
   * 
   * @return std::string*
   */
  std::string getPartNumber();

  /**
   * It returns preventive maintenance kit percent used.
   * 
   * @return uint16_t
   */
  uint16_t getPercentUsed();

  /**Object destructor*/
  virtual ~ViewsPreventiveMaintenanceKit();

protected:

private:

  /** This list will keep the list of observers for this printer information.
   */
  std::list <IObserver *> onChangeList_;
  std::string description_;
  std::string partNumber_;
  uint16_t percentUsed_;
};

#endif /*VIEWSPREVENTIVEMAINTENANCEKIT_H_*/
