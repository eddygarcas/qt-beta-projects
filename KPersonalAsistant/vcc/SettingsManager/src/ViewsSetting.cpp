/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsSetting.cpp
 *  @author Jesus Barahona
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

#include "ViewsSetting.h"
#include "SystemManager/SystemManager.h"

/** Method returning the status of the Views Pen
 *
 * @return the status of the Views Pen
 */
int32_t ViewsSetting::getId()
{
  return settingId_;
}

int32_t ViewsSetting::getTitle(void)
{
  return ViewsSetting::titleNames[settingId_];
}

int32_t ViewsSetting::getLabel(void)
{
  return ViewsSetting::labelNames[settingId_];
}

IViewsSetting::TypeofSetting ViewsSetting::getType()
{
  return typeofSetting_;
}

/* 
 * Gets (finds) the CDS object and stores it in the protected variable cdsObject_. It will make an assert if the object does not exist
 * because would mean that the ViewsSetting object is corrupted. 
 */
void ViewsSetting::getCdsObject()
{
  Cds::CdsResult result;

  if (ViewsSetting::cdsObject_ == NULL )
  {
    result = cds_->find(
        ViewsSetting::cdsObjNames[ViewsSetting::settingId_].c_str(),
        &(ViewsSetting::cdsObject_));
    assert_removable(result == Cds::CDS_SUCCESS);
  }
}

ViewsSetting::~ViewsSetting()
{
  
}
