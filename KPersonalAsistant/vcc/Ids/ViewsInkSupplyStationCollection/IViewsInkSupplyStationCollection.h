/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsInkSupplyStationCollection.h
 *  @author Xavier Santotomas
 *  @date  Mon Nov 19 11:57:06 CET 2007
 *  @brief  Views Ink Supply Station Collection Abstract Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __IViewsInkSupplyStationCollection_h_
#define __IViewsInkSupplyStationCollection_h_

#include "ViewsInkSupplyStationCollection/IViewsInkSupplyStation.h"
#include "ViewsInkSupplyStationCollection/IViewsInkSupplySlot.h"


/**
 * A Collection of Views Ink Supply Slots
 */
typedef std::vector<IViewsInkSupplySlot *> ViewsInkSupplySlotCollection;

/**
 * To iterate a ViewsInkSupplySlotCollection.
 */
typedef ViewsInkSupplySlotCollection::iterator ViewsInkSupplySlotIterator;


/**
 * A Collection of Views Ink Supply Stations
 */
typedef std::vector<IViewsInkSupplyStation *> ViewsInkSupplyStationCollection;

/**
 * To iterate a ViewsInkSupplyStationCollection.
 */
typedef ViewsInkSupplyStationCollection::iterator ViewsInkSupplyStationIterator;


/** This class describes the Views Ink Supply Station Collection abstraction interface.
 */
class IViewsInkSupplyStationCollection 
{
public:

    /** @name Views Ink Supply Station Collection protected methods.
        @{
    */
	
    /** Method returning a copy of the vector of Views Ink Supply Slots
     *   @return a copy of the vector of Views Ink Supply Slots
     */
    virtual ViewsInkSupplySlotCollection getViewsInkSupplySlots() = 0;

    /** Method returning a copy of the vector of Views Ink Supply Stations
     *   @return a copy of the vector of Views Ink Supply Stations
     */
    virtual ViewsInkSupplyStationCollection getViewsInkSupplyStations() = 0;

    /** Method returning a copy of the vector of Views Ink Supplies
     *   @return a copy of the vector of Views Ink Supplies
     */
    virtual ViewsInkSupplyCollection getViewsInkSupplies() = 0;

    /** @}
     */

};

#endif
