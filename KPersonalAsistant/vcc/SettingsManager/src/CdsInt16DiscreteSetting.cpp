/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CdsInt16DiscreteSetting.cpp
 *  @author Jesus Barahona
 *  @date   Thu Jan 17 19:29:11 CEST 2008
 *  @brief  CdsInt32ContinuosSetting implementation for views.
 *
 *  (c) Copyright Hewlett-Packard Company, 2008-2010.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "CdsInt16DiscreteSetting.h"
#include "ViewsSetting.h"
#include "SystemManager/SystemManager.h"

/** 
 * Constructor
 */
CdsInt16DiscreteSetting::CdsInt16DiscreteSetting(int32_t settingId, ICds* cds,
    std::vector<int32_t> &optionLabels, std::vector<int32_t> &optionValues)
{
  ViewsSetting::settingId_ = settingId;
  ViewsSetting::cds_ = cds;
  ViewsSetting::cdsObject_ = NULL;
  optionLabels_ = optionLabels;
  optionValues_ = optionValues;
}

/*
 * Destructor
 */
CdsInt16DiscreteSetting::~CdsInt16DiscreteSetting()
{

}

DiscreteOptionsCollection CdsInt16DiscreteSetting::getOptionLabels()
{
  return optionLabels_;
}

DiscreteOptionsCollection CdsInt16DiscreteSetting::getOptionValues()
{
  return optionValues_;
}

/** Method returning the value of the setting. 
 @return the current value of the setting.
 */
std::string CdsInt16DiscreteSetting::getStringValue()
{
  Cds::CdsResult result;
  int16_t value;

  // Assures the cdsObject_ protected variable is properly initialized.
  ViewsSetting::getCdsObject();

  result = cdsObject_->get(value);
  assert_removable(result == Cds::CDS_SUCCESS);

  std::ostringstream returnValue_;
  returnValue_ << value;
  return returnValue_.str();

}

void CdsInt16DiscreteSetting::setValue(int32_t optionValue)
{
  Cds::CdsResult result;

  // Assures the cdsObject_ protected variable is properly initialized.
  ViewsSetting::getCdsObject();

  result = cdsObject_->set((int16_t&)optionValue);
  assert_removable(result == Cds::CDS_SUCCESS);

}

