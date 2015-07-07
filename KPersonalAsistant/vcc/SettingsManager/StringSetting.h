/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   StringSetting.h
 *  @author Eduard Garcia
 *  @date   Thu Jan 03 19:29:11 CEST 2008
 *  @brief  Discrete Setting (i.e. a setting that only accepts certain values) representation for views.
 *
 *  (c) Copyright Hewlett-Packard Company, 2008-2010.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#ifndef STRINGSETTING_H_
#define STRINGSETTING_H_

#include "ViewsSetting.h"
#include "IStringSetting.h"

/** This class describes the Views String Setting.
 */
class StringSetting : public ViewsSetting, public IStringSetting {
public:
  /** @name StringSetting public methods.
   @{
   */

  /** Method returning the value of the setting. 
   @return the current value of the setting.
   */
  virtual std::string getStringValue() = 0;

  /** Method to set a value in a setting. 
   @return whether the value has been correctly set or not.
   */
  virtual void setValue(std::string &optionValue);

  /**
   * Return the allowed characters by this string setting.
   * 
   * @return AllowedCharsCollection
   */
  virtual AllowedCharsCollection getAllowedChars() = 0;

  /** @}
   */
  
  virtual ~StringSetting();
  
protected:
  /**Vector instance which will contains the allowed characters*/
  AllowedCharsCollection allowedChars_;

  /**Voi constructor*/
  StringSetting();

private:

};

#endif /*STRINGSETTING_H_*/
