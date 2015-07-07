/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IPrinterCommands.h
 *  @author Eduard Garcia
 *  @date   Febrary 20 2008
 *  @brief  Views Observer Abstract
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#ifndef IPRINTERCOMMANDS_H_
#define IPRINTERCOMMANDS_H_

#include <string>

/**
 * The class that inherits from this, needs implement the next method, and to do calls to Engine state machine. 
 */
class IPrinterCommands
{
  
public:
  /**
   * The class that inherits from this, needs implement the next method, 
   * and to do calls to Engine state machine. 
   * This method returns true if operation ends well or false in otherwise.
   * 
   * @param std::string
   * @return bool
   */
  virtual bool execute(std::string& _commandAction) = 0;
};

#endif /*IPRINTERCOMMANDS_H_*/
