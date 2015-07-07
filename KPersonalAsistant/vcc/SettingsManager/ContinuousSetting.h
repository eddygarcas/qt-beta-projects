/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ContinuousSetting.h
 *  @author Eduard Garcia
 *  @date   Thu Jan 03 19:29:11 CEST 2008
 *  @brief  Continuous Setting (i.e. an integer) representation for views.
 *
 *  (c) Copyright Hewlett-Packard Company, 2008-2010.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef CONTINUOUSSETTING_H_
#define CONTINUOUSSETTING_H_

#include "ViewsSetting.h"

/** This class describes the Views Continuous Setting.
 */
class ContinuousSetting : public ViewsSetting {
public:
  /** @name ContinuousSetting public methods.
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
   * It returns the minimum range value.
   * 
   * @return int 
   */
  virtual int32_t getMinimum() = 0;

  /**
   * It returns the maximum range value
   * 
   * @return int 
   */
  virtual int32_t getMaximum() = 0;

  /** @}
   */

  virtual ~ContinuousSetting();
  
protected:

  /**Void constructor*/
  ContinuousSetting();

private:

};

#endif //CONTINUOUSSETTING_H_
