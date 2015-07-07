/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsInkSupplyStation.h
 *  @author Xavier Santotomas
 *  @date  Mon Nov 19 11:57:06 CET 2007
 *  @brief  Views Ink Supply Station Abstract Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __IViewsInkSupplyStation_h_
#define __IViewsInkSupplyStation_h_

#include "IObserver.h"
#include "ViewsInkSupplyStationCollection/IViewsInkSupply.h"


/**
 * A Collection of Views Ink Supplies
 */
typedef std::vector<IViewsInkSupply *> ViewsInkSupplyCollection;

/**
 * To iterate a ViewsInkSupplyCollection.
 */
typedef ViewsInkSupplyCollection::iterator ViewsInkSupplyIterator;


/** This class describes the Views Ink Supply Station abstraction interface.
 */
class IViewsInkSupplyStation: public IObserver, 
                              public IObservable
{
public:

    /** @name IViewsInkSupplyStation public methods.
        @{
    */

    /** Method returning a copy of the vector of Views Ink Supplies
     *   @return a copy of the vector of Views Ink Supplies
     */
    virtual ViewsInkSupplyCollection getViewsInkSupplies() = 0;

    /** @}
     */

};

#endif
