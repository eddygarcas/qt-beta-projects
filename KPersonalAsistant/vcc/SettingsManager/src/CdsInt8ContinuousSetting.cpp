/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CdsInt8ContinuousSetting.cpp
 *  @author Jesus Barahona
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

#include "CdsInt8ContinuousSetting.h"
#include "ViewsSetting.h"
#include "SystemManager/SystemManager.h"

/** 
 * Constructor
 */
CdsInt8ContinuousSetting::CdsInt8ContinuousSetting(int32_t settingId, ICds* cds)
{
  ViewsSetting::settingId_ = settingId;
  ViewsSetting::cds_ = cds;
  ViewsSetting::cdsObject_ = NULL;

}

/*
 * Destructor
 */
CdsInt8ContinuousSetting::~CdsInt8ContinuousSetting()
{

}

/** Method returning the value of the setting. 
 @return the current value of the setting.
 */
std::string CdsInt8ContinuousSetting::getStringValue()
{
  Cds::CdsResult result;
  int8_t value;

  // Assures the cdsObject_ protected variable is properly initialized.
  ViewsSetting::getCdsObject();

  result = cdsObject_->get(value);
  assert_removable(result == Cds::CDS_SUCCESS);

  std::ostringstream returnValue_;
  returnValue_ << value;
  return returnValue_.str();

}

void CdsInt8ContinuousSetting::setValue(int32_t optionValue)
{
  Cds::CdsResult result;

  // Assures the cdsObject_ protected variable is properly initialized.
  ViewsSetting::getCdsObject();

  result = cdsObject_->set((int8_t&)optionValue);
  assert_removable(result == Cds::CDS_SUCCESS);

}

/**
 * It returns the minimum range value.
 * 
 * @return int 
 */
int32_t CdsInt8ContinuousSetting::getMinimum()
{
  return 0;
}

/**
 * It returns the maximum range value
 * 
 * @return int 
 */
int32_t CdsInt8ContinuousSetting::getMaximum()
{
  return 0;
}

