/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IPdl.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  IPdl interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef IPDL_H_
#define IPDL_H_

#include <string>
#include "PrinterInformation/IPrinterResource.h"
#include "IObservable.h"

/**
 * PDL as a Page Description Languages which describes the organization and contents of the page to be printed.
 * This class definition must be observable from other objects, in our case by Printer information.
 */
class IPdl : public IPrinterResource
{
public:

  /**
   * Return lang level value, that is a revision version of PDL.
   * 
   * @return std::string
   */
  virtual std::string getLangLevel() = 0;
};

#endif /*IPDL_H_*/
