#ifndef IGUIMAIN_H_
#define IGUIMAIN_H_
/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsJobManager.h
 *  @author Eduard Garcia
 *  @date   Thu Feb 21 16:30:11 CEST 2008
 *  @brief  IViewsJobManager interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

/**
 * This interface defines a generic GUI main class.
 */
class IGuiMain
{
public:
  
  /**
   * Starts the GUI application.
   * 
   */
  virtual void execute() = 0;
};

#endif /*IGUIMAIN_H_*/
