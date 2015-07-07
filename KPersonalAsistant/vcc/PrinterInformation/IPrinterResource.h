/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IPrinterResource.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  IPrinterResource interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef IPRINTERRESOURCE_H_
#define IPRINTERRESOURCE_H_

#include <string>

class IPrinterResource
{
public:

  /**
   * Return a printer resource description. These objects are dynamic, is possible that this
   * function retun null(0).
   * 
   * @return std::string
   */
  virtual std::string getDescription() = 0;

};

#endif /*IPRINTERRESOURCE_H_*/
