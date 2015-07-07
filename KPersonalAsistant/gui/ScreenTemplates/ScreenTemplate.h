/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ScreenTemplate.h
 *  @author Eduard Garcia Castello
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef SCREENTEMAPLATE_H_
#define SCREENTEMAPLATE_H_

#include "FrontPanelEnum.h"
#include "IScreenTemplate.h"
#include <iostream>

/**
 * Its a Abstract class which determines the generic behavior of any screen template.
 */
class ScreenTemplate : public IScreenTemplate
{
public:

  /**
   * Puts in screen template the information data which we will want to show in template.
   *
   * @param _data
   */
  void setData(void* _data);

  /**
   * Gets back the template information data.
   *
   * @return void*
   */
  void* getData();

  /**
   * Puts in screen template a window title.
   *
   * @param &_windowTitle
   */
  virtual void setWindowTitle(const std::string &_windowTitle) = 0;

  /**
   * Shows the screen template in front panel.
   */
  virtual void show() = 0;

  /**
   * Removes all components which are in screen template.
   *
   * @return bool
   */
  virtual bool clear() = 0;

  /**
   * If this template has been showed in the past it gets back true in otherwise false
   *
   * @return bool
   */
  bool hasBeenShowed();

  /**
   * Class destructor
   */
  virtual ~ScreenTemplate();

protected:

  /**Void constructor*/
  ScreenTemplate();

  /**Screen template information data*/
  void* data_;

  /** Its used to know if the screen template has been showed in the past.*/
  bool hasBeenShowed_;

private:

};

#endif /*SCREENTEMPLATE_H_*/
