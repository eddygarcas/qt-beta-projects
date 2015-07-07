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

#ifndef ISTRINGSETTING_H_
#define ISTRINGSETTING_H_

#include <vector>

/**
 * A Collection of discrete setting options
 */
typedef std::vector<char> AllowedCharsCollection;

/**
 * To iterate a DiscreteOptionsCollection.
 */
typedef AllowedCharsCollection::iterator AllowedCharsIterator;

/** This class describes the Views Setting abstraction interface.
 */
class IStringSetting {
public:

  /** @name IStringSetting public methods.
   @{
   */

  virtual AllowedCharsCollection getAllowedChars() = 0;

  /** @}
   */

};

#endif /*ISTRINGSETTING_H_*/
