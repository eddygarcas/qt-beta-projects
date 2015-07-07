/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsCarriage.h
 *  @author Xavier Santotomas
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  Views Carriage Atlas Abstract Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __IViewsCarriage_h_
#define __IViewsCarriage_h_

#include "IObserver.h"
#include "ViewsCarriage/IViewsPenSlot.h"

/**
 * A Collection of Views Pens
 */
typedef std::vector<IViewsPen *> ViewsPenCollection;

/**
 * To iterate a ViewsPenCollection.
 */
typedef ViewsPenCollection::iterator ViewsPenIterator;


/**
 * A Collection of Views Pen Slots
 */
typedef std::vector<IViewsPenSlot *> ViewsPenSlotCollection;

/**
 * To iterate a ViewsPenSlotCollection.
 */
typedef ViewsPenSlotCollection::iterator ViewsPenSlotIterator;



/** This class describes the Views Carriage abstraction interface.
*/
class IViewsCarriage : public IObserver, 
                       public IObservable
{
public:
    /** @name IViewsCarriage public methods.
      @{
    */

	/** Method returning a copy of the vector of Views Pens
	 *   @return a copy of the vector of Views Pens
	 */
	virtual ViewsPenCollection getViewsPens() = 0;
	
	/** Method returning a copy of the vector of Views Pen Slots
	 *   @return a copy of the vector of Views Pen Slots
	 */
	virtual ViewsPenSlotCollection getViewsPenSlots() = 0;

    /** @}
     */

};

#endif
