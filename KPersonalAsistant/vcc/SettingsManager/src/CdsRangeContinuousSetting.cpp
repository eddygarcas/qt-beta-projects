/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CdsRangeContinuousSetting.cpp
 *  @author Eduard Garcia
 *  @date   Thu Jan 17 19:29:11 CEST 2008
 *  @brief  CdsInt32ContinuousSetting implementation for views.
 *
 *  (c) Copyright Hewlett-Packard Company, 2008-2010.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "CdsRangeContinuousSetting.h"
#include "SystemManager/SystemManager.h"

/** 
 * Constructor
 */
CdsRangeContinuousSetting::CdsRangeContinuousSetting(int32_t settingId, ICds* cds)
{
  ViewsSetting::settingId_ = settingId;
  ViewsSetting::cds_ = cds;
  ViewsSetting::cdsObject_ = NULL;
}

/*
 * Destructor
 */
CdsRangeContinuousSetting::~CdsRangeContinuousSetting()
{

}

/** Method returning the value of the setting. 
 @return the current value of the setting.
 */
std::string CdsRangeContinuousSetting::getStringValue()
{
  Cds::CdsResult result;
  int32_t value;

  // Assures the cdsObject_ protected variable is properly initialized.
  ViewsSetting::getCdsObject();

  result = cdsObject_->get(value);
  assert_removable(result == Cds::CDS_SUCCESS);

  std::ostringstream returnValue_;
  returnValue_ << value;
  return returnValue_.str();

}

void CdsRangeContinuousSetting::setValue(int32_t optionValue)
{
  int32_t returned_value_ = -1;
  Cds::CdsResult result;
  if ( (optionValue <= getMaximum()) && (optionValue >= getMinimum()))
  {
    ViewsSetting::getCdsObject();
    result = cdsObject_->set((int32_t&)optionValue);
    assert_removable(result == Cds::CDS_SUCCESS);
    returned_value_ = 0;
  }
  
}

/**
 * It returns the minimum range value.
 * 
 * @return int 
 */
int32_t CdsRangeContinuousSetting::getMinimum()
{
  return ViewsSetting::minRange[ViewsSetting::settingId_];
}

/**
 * It returns the maximum range value
 * 
 * @return int 
 */
int32_t CdsRangeContinuousSetting::getMaximum()
{
  return ViewsSetting::maxRange[ViewsSetting::settingId_];
}

