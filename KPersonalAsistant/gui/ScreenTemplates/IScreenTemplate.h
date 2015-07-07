/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IScreenTemplate.h
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

#ifndef ISCREENTEMPLATE_H_
#define ISCREENTEMPLATE_H_

#include <string>
#include "atlas_types.h"
#include "IViewsAction.h"

/**
 * Interface which defines the screen template behavior.
 */
class IScreenTemplate
{
public:
	 /*TODO:
	  * You must add all screen templates in this enumeration. The order of this enumeration determines its loads in GuiController.
	  * For example, if choice screen template is the first option, it must be load in first time into GuiController class.
	  * To clarify this appointment, we recomends to see the GuiController source, in fact, see start() method source.
	  */
  /**Enumeration which contains screen template types.*/
  enum screenTemplate_enum{
	  CHOICE_TEMPLATE,
	  TOPLEVEL_TEMPLATE,
   INKLEVEL_TEMPLATE,
   PROGRESSBAR_TEMPLATE,
	  MENU_TEMPLATE,
	  ANIMATION_TEMPLATE,
   INPUTADDRESS_TEMPLATE,
   TEXT_MENU_TEMPLATE,
	  INPUTTEXT_TEMPLATE
  };

  /**
   * Puts in screen template a window title.
   *
   * @param &_windowTitle
   */
  virtual void setWindowTitle(const std::string &_windowTitle) = 0;

  /**
   * Shows the screen template in front panel.
   */
  virtual void show()  = 0;

  /**
   * Removes all components which are in screen template.
   *
   * @return bool
   */
  virtual bool clear() = 0;

  /**
   * Puts in screen template the information data which we will want to show in template.
   *
   * @param _data
   */
  virtual void setData(void* _data) = 0;

  /**
   * Get back the template information data.
   *
   * @return void*
   */
  virtual void* getData()           = 0;

  /**
   * If this template has been showed in the past it gets back true in otherwise false
   *
   * @return bool
   */
  virtual bool hasBeenShowed() = 0;

};

#endif /*ISCREENTEMPLATE_H_*/
