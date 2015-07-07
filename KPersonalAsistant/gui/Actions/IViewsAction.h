#ifndef IVIEWSACTION_H_
#define IVIEWSACTION_H_

/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsAction.h
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

#include <string>
#include "atlas_types.h"

/**Model action generic definition*/
class IViewsAction{
  
public:
  //TODO: Put in this enumeration the action types.
  /**Enumeration with a list of action types*/
  enum actionType_enum{
    PAPER_MENU_ACTION,
    JOB_MANAGEMENT_MENU_ACTION,
    INK_MENU_ACTION,
    SETUP_MENU_ACTION,
    IMAGE_QUALITY_MENU_ACTION,
    CONNECTIVITY_MENU_ACTION,
    INTERNAL_PRINTS_MENU_ACTION,
    INFORMATION_MENU_ACTION,
    MENU_ACTION,
    INK_TEXT_MENU_ACTION,
    REPORTER_ACTION,
    SETTINGS_ACTION,
    SYSTEMAERROR_ACTION,
    TOPLEVEL_ACTION,
    INKLEVEL_ACTION,
    TEST_PROGRESSBAR_ACTION,
    ANIMATION_TEST_ACTION,
    INFORMATION_ACTION,
    INSERT_IPV4_ACTION
  };
  
  /**
   * Returns the action type whose are defined in IViewsAction actionType_enum enumerator.
   * 
   * @return actioType_enum 
   */
  virtual actionType_enum   getActionType() = 0;

  /**
  *Returns the action object name. This name will be used to create a menu option list.
  * 
  * @return std::string 
  */
  virtual const std::string& getObjectName() = 0;
  
  /**
   * Return the action model priority
   * 
   * @return int32_t
   */
  virtual int32_t getPriority() = 0;
  
  /**
   * By means of this method we will be able to assign views common classes interfaces into
   * model actions.
   * 
   * @param interfaceName
   * @param *interface
   */
  virtual void setInterface(std::string interfaceName, void *interface) = 0;
  
  /**
   * Next method will contains the logical functionality.
   */
  virtual void execute() = 0;
  
  /**
   * Determines if this option is a action option or otherwise as a menu option.
   * 
   */
  virtual bool hasMenuOption() = 0;
  
};

#endif /*IVIEWSACTION_H_*/
