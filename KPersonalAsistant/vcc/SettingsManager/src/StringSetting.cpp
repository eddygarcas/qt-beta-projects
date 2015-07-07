/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   StringSetting.cpp
 *  @author Jesus Barahona
 *  @date   Thu Jan 07 19:29:11 CEST 2008
 *  @brief  Discrete Setting (i.e. a setting that only accepts certain values) implementation for views.
 *
 *  (c) Copyright Hewlett-Packard Company, 2008-2010.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "StringSetting.h"

StringSetting::StringSetting()
{
  typeofSetting_ = IViewsSetting::STRINGSETTING;
}

void StringSetting::setValue(std::string &_optionValue)
{
  
}

StringSetting::~StringSetting()
{
  
}