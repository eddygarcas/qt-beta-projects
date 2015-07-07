/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CdsStringSetting.cpp
 *  @author Eduard Garcia
 *  @date   Thu Jan 03 19:29:11 CEST 2008
 *  @brief  Continuous Setting (i.e. an integer) implementation for views.
 *
 *  (c) Copyright Hewlett-Packard Company, 2008-2010.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "CdsStringSetting.h"
#include "ViewsSetting.h"
#include "SystemManager/SystemManager.h"

/*
 * Constructor
 */
CdsStringSetting::CdsStringSetting(int32_t settingId, ICds* cds,
    AllowedCharsCollection &_allowedChars_)
{
  ViewsSetting::settingId_ = settingId;
  ViewsSetting::cds_ = cds;
  ViewsSetting::cdsObject_ = NULL;
  allowedChars_ = _allowedChars_;
}

/*
 * Destructor
 */
CdsStringSetting::~CdsStringSetting()
{

}

/** Method returning the value of the setting. 
 @return the current value of the setting.
 */
std::string CdsStringSetting::getStringValue()
{
  Cds::CdsResult result;
  std::string value;

  // Assures the cdsObject_ protected variable is properly initialized.
  ViewsSetting::getCdsObject();

  result = cdsObject_->get(value);
  assert_removable(result == Cds::CDS_SUCCESS);
  return value;

}

/** Method to set a value in a setting. 
 @return whether the value has been correctly set or not.
 */
void CdsStringSetting::setValue(std::string optionValue)
{
  Cds::CdsResult result;

  // Assures the cdsObject_ protected variable is properly initialized.
  ViewsSetting::getCdsObject();

  result = cdsObject_->set((std::string&)optionValue);
  assert_removable(result == Cds::CDS_SUCCESS);


}

AllowedCharsCollection CdsStringSetting::getAllowedChars()
{
  return allowedChars_;
}

