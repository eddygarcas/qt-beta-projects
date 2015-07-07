/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsSetting.h
 *  @author Eduard Garcia
 *  @date   Thu Dec 20 19:29:11 CEST 2007
 *  @brief  Setting representation for views.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef IVIEWSSETTING_H_
#define IVIEWSSETTING_H_

#include "atlas_types.h"

#include <string>

/** This class describes the Views Setting abstraction interface.
 */
class IViewsSetting {
public:
  enum TypeofSetting
  {
    CONTINUOUSSETTING,
    DISCRETESETTING,
    STRINGSETTING
  };

  /** @name IViewsSetting public methods.
   @{
   */
  virtual int32_t getId() = 0;

  /** Method returning the value of the setting. 
   *@return the current value of the setting.
   */
  virtual std::string getStringValue() = 0;

  /**
   * It returns the type of setting, which will be able to be one of next values:
   *   IViewsSetting::CONTINUOUSSETTING
   *   IViewsSetting::DISCRETESETTING
   *   IViewsSetting::STRINGSETTING
   * 
   * @return IViewsSetting::TypeofSetting
   */
  virtual IViewsSetting::TypeofSetting getType() = 0;

  /**
   * It returns the key value of title setting.
   * 
   * return int
   */
  virtual int32_t getTitle(void) = 0;

  /**
   * It returns the key value of label setting.
   * 
   * return int
   */
  virtual int32_t getLabel(void) = 0;

  /** @}
   */

};

#endif
