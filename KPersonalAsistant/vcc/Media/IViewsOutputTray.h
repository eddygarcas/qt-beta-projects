/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsOutputTray.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  ViewsOutputTray interface definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////


#ifndef IVIEWSOUTPUTTRAY_H_
#define IVIEWSOUTPUTTRAY_H_

#include "IObservable.h"
#include <string>

/**
 * This interface definition contains all basic methods which define a ouuput tray element. 
 */
class IViewsOutputTray : public IObservable
{
public:

  /**
   * Returns output tray statuc value
   * 
   * @return float
   */
  virtual float getStatus() = 0;

};

#endif /*IVIEWSOUTPUTTRAY_H_*/
