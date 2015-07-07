/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ISettingsManager.h
 *  @author Jesus Barahona
 *  @date   Thu Jan 07 19:29:11 CEST 2008
 *  @brief  The Settings Manager is used to get the available settings in the system.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.  
 */
////////////////////////////////////////////////////////////////////////////// 

#ifndef ISETTINGSMANAGER_H_
#define ISETTINGSMANAGER_H_

#include <IViewsSetting.h>

/** This class describes the Settings Manager abstraction interface.
 */
class ISettingsManager {

public:

  /** @name Settings Manager public methods.
   @{
   */

  /** Method to get an IViewsSetting
   @return the IViewsSetting that corresponds with the id.
   */
  virtual IViewsSetting* getSetting(int32_t id) = 0;

  /** @}
   */

};

#endif
