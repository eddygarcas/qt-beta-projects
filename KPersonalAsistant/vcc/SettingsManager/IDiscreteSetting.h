/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IDiscreteSetting.h
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

#ifndef IDISCRETESETTING_H_
#define IDISCRETESETTING_H_

#include <string>
#include <vector>

/**
 * A Collection of discrete setting options
 */
typedef std::vector<int32_t> DiscreteOptionsCollection;

/**
 * To iterate a DiscreteOptionsCollection.
 */
typedef DiscreteOptionsCollection::iterator DiscreteOptionsIterator;


/** This class describes the Views Setting abstraction interface.
 */
class IDiscreteSetting {
public:

  /** @name IDiscreteSetting public methods.
   @{
   */

  /**
   * Returns labels option key for specific discrete setting.
   * 
   * @return std::vector<int> 
   */
  virtual DiscreteOptionsCollection getOptionLabels() = 0;

  /**
   * Returns values option key for specific discrete setting.
   * 
   * @return std::vector<int> 
   */
  virtual DiscreteOptionsCollection getOptionValues() = 0;

  /** @}
   */

};

#endif /*IDISCRETESETTING_H_*/
