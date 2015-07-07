/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Pdl.h
 *  @author Eduard Garcia Castello
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  Pdl class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef PDL_H_
#define PDL_H_

#include <list>
#include "PrinterInformation/IPdl.h"
#include "Cds/ICds.h"
#include "ICallback.h"
/**
 * PDL as a Page Description Languages which describes the organization and contents of the page to be printed.
 * This class definition must be observable from other objects, in our case by Printer information.
 */
class Pdl : public IPdl
{
public:

  /**
   * Makes a Pdl instance with description and lang level values through by parameter.
   * 
   * @param _description
   * @param _langLevel
   */
  Pdl(std::string& _description, std::string& _langLevel);

  /**
   * Returna a Pdl description.
   * 
   * @return std::string*
   */
  std::string getDescription();

  /**
   * Return a lang level value
   * 
   * @return std::string*
   */
  std::string getLangLevel();

  /**Object destructor*/
  virtual ~Pdl();

protected:

private:

  /** This list will keep the list of observers for this printer information.
   */
  std::list <IObserver *> onChangeList_;
  std::string description_;
  std::string langLevel_;
};

#endif /*PDL_H_*/
