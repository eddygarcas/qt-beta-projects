/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CdsInt16DiscreteSetting.h
 *  @author Eduard Garcia
 *  @date   Thu Jan 17 19:29:11 CEST 2008
 *  @brief  CdsInt32ContinuosSetting representation for views.
 *
 *  (c) Copyright Hewlett-Packard Company, 2008-2010.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#ifndef CDSINT16DISCRETESETTING_H_
#define CDSINT16DISCRETESETTING_H_

#include "Cds/ICds.h"
#include "DiscreteSetting.h"

/** This class describes the Views Continuos Setting.
 */
class CdsInt16DiscreteSetting : public DiscreteSetting {
public:
  /** @name CdsInt16ContinuosSetting public methods.
   @{
   */

  /**
   * Public Constructor
   * 
   * @param settingId
   * @param cds
   * @param _optionLabel
   * @param _optionValue
   * 
   */
  CdsInt16DiscreteSetting(int32_t settingId, ICds* cds,
      std::vector<int32_t> &_optionLabel,
      std::vector<int32_t> &_optionValue);

  /*
   * Destructor
   */
  ~CdsInt16DiscreteSetting();

  /** Method returning the value of the setting. 
   @return the current value of the setting.
   */
  virtual std::string getStringValue();

  /** Method to set a value in a setting. 
   @return whether the value has been correctly set or not.
   */
  virtual void setValue(int32_t optionValue);

  /**
   * Returns labels option key for specific discrete setting.
   * 
   * @return DiscreteOptionsCollection 
   */
  virtual DiscreteOptionsCollection getOptionLabels();

  /**
   * Returns labels values key for specific discrete setting.
   * 
   * @return DiscreteOptionsCollection 
   */
  virtual DiscreteOptionsCollection getOptionValues();

  /** @}
   */

};

#endif /*CDSINT16DISCRETESETTING_H_*/
