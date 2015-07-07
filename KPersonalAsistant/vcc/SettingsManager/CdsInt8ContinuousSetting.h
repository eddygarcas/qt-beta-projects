#ifndef CDSINT8CONTINUOSSETTING_H_
#define CDSINT8CONTINUOSSETTING_H_
/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CdsInt8ContinuousSetting.h
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
#include "ContinuousSetting.h"

/** This class describes the Views Continuous Setting.
 */
class CdsInt8ContinuousSetting : public ContinuousSetting {
public:
  /** @name CdsInt32ContinuousSetting public methods.
   @{
   */
  /*
   * Public constructor
   * 
   * @param settingId
   * @param cds
   */
  CdsInt8ContinuousSetting(int32_t settingId, ICds* cds);

  /*
   * Destructor
   */
  ~CdsInt8ContinuousSetting();

  /** Method returning the value of the setting. 
   @return the current value of the setting.
   */
  virtual std::string getStringValue();

  /** Method to set a value in a setting. 
   @return whether the value has been correctly set or not.
   */
  virtual void setValue(int32_t optionValue);

  /**
   * It returns the minimum range value.
   * 
   * @return int 
   */
  virtual int32_t getMinimum();

  /**
   * It returns the maximum range value
   * 
   * @return int 
   */
  virtual int32_t getMaximum();

  /** @}
   */

};

#endif /*CDSINT8CONTINUOSSETTING_H_*/
