/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   DiscreteSetting.h
 *  @author Jesus Barahona
 *  @date   Thu Jan 03 19:29:11 CEST 2008
 *  @brief  Discrete Setting (i.e. a setting that only accepts certain values) representation for views.
 *
 *  (c) Copyright Hewlett-Packard Company, 2008-2010.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef DISCRETESETTING_H_
#define DISCRETESETTING_H_

#include "IDiscreteSetting.h"
#include "ViewsSetting.h"

/** This class describes the Views Discrete Setting.
 */
class DiscreteSetting : public ViewsSetting, public IDiscreteSetting
{
public:
  /** @name DiscreteSetting public methods.
   @{
   */

  /** Method returning the value of the setting. 
   @return the current value of the setting.
   */
  virtual std::string getStringValue() = 0;

  /** Method to set a value in a setting. 
   @return whether the value has been correctly set or not.
   */
  virtual void setValue(int32_t optionValue);

  /**
   * Returns labels option key for specific discrete setting.
   * 
   * @return DiscreteOptionsCollection 
   */
  virtual DiscreteOptionsCollection getOptionLabels() = 0;

  /**
   * Returns labels values key for specific discrete setting.
   * 
   * @return DiscreteOptionsCollection 
   */
  virtual DiscreteOptionsCollection getOptionValues() = 0;

  /** @}
   */

  virtual ~DiscreteSetting();
  
protected:

  /**Void constructor*/
  DiscreteSetting();

private:

};

#endif //DISCRETESETTING_H_
