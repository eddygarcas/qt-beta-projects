/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsIterator.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  IViewsIterator class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef IVIEWSITERATOR_H_
#define IVIEWSITERATOR_H_

#include "atlas_types.h"
/**
 * Interface which allows us to create a Views iterator implementation. 
 * This way we want a generic structure for manipulating lists and have control about as be used.
 */
template<typename Ti>
class IViewsIterator
{
public:

  /**
   * Return a list object referenced.
   * @return Ti
   */
  virtual Ti next() = 0;
  
  /**
   * This method returns true if iterator has object or false in otherwise.
   * @return bool
   */
  virtual bool hasNext() = 0;
  
  /**
   * It Inform to IViewsIterator interface implementation that client has finished of using the iterator 
   * and for deleting itself.
   */
  //virtual void remove() = 0;

  /**
   * It returns a iterator size.
   * 
   * @return uint32_t
   */
  virtual uint32_t size() = 0;

  /**
   * Returns a instance value hold in position passed through parameter.
   * 
   * @param uint16_t
   * @return Ti
   */
  virtual Ti getElementAt(uint16_t _pos) = 0;

};

#endif /*IVIEWSITERATOR_H_*/
