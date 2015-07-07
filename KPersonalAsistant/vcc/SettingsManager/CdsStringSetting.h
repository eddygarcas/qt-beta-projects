#ifndef CDSSTRINGSETTING_H_
#define CDSSTRINGSETTING_H_
/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CdsStringSetting.h
 *  @author Jesus Barahona
 *  @date   Thu Jan 17 19:29:11 CEST 2008
 *  @brief  CdsInt32ContinuousSetting representation for views.
 *
 *  (c) Copyright Hewlett-Packard Company, 2008-2010.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "Cds/ICds.h"
#include "StringSetting.h"

/** This class describes the Views Continuous Setting.
 */
class CdsStringSetting : public StringSetting {
public:
  /** @name CdsInt32ContinuousSetting public methods.
   @{
   */

  /**
   * Public Constructor
   * 
   * @param settingId
   * @param cds
   * @param AllowedCharsCollection
   * 
   */
  CdsStringSetting(int32_t settingId, ICds* cds,
      AllowedCharsCollection &_allowedChars);

  /*
   * Destructor
   */
  ~CdsStringSetting();

  /** Method returning the value of the setting. 
   @return the current value of the setting.
   */
  virtual std::string getStringValue();

  /** Method to set a value in a setting. 
   @return whether the value has been correctly set or not.
   */
  virtual void setValue(std::string optionValue);

  /**
   * Return the allowed characters by this string setting.
   * 
   * @return AllowedCharsCollection
   */
  virtual AllowedCharsCollection getAllowedChars();
  /** @}
   */

private:

};
#endif /*CDSSTRINGSETTING_H_*/
