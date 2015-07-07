/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupplyStation.cpp
 *  @author Xavier Santotomas
 *  @date   Wed Nov 21 15:56:35 CET 2007
 *  @brief  Views Ink Supply Station
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "ViewsInkSupplyStation.h"
#include "SystemManager/SystemManager.h"
	

/** public constructor.
 *  @param rpc Pointer to the RPC interface to be used to interface with the remote pen.
 *  @param the ISS Pointer to the remote IViewsInkSupplyStation interface.
 *  @param the collection of Views Ink Supplies binded to the ISS.
 */
ViewsInkSupplyStation::ViewsInkSupplyStation (IRpc * rpc, IViewsInkSupplyStation * theISS, const ViewsInkSupplyCollection & viewsInkSupplies)
{
    rpc_              = rpc;
    theISS_           = theISS;
    viewsInkSupplies_ = viewsInkSupplies;
}


/** public destructor.
 */
ViewsInkSupplyStation::~ViewsInkSupplyStation()
{
}
	
/** Method returning a copy of the vector of Views Ink Supplies
 *   @return a copy of the vector of Views Ink Supplies
 */
ViewsInkSupplyCollection ViewsInkSupplyStation::getViewsInkSupplies()
{
    return viewsInkSupplies_;
}

/** method to receive notifications from the observable objects.
 *  @param observable is the object that forced the execution of this method.
 *  @param reason reason for the callback, it has to be defined in the class using this callback.
 */
void ViewsInkSupplyStation::onChange (IObservable &observable, uint32_t reason)
{
    assert_non_removable (0);
}


/** Method to register an observer for this views carriage.
 *   @param observer object to be registered. Later will be notified.
 */
void ViewsInkSupplyStation::registerObserver (IObserver &observer)
{
    assert_non_removable (0);
}


/** Method to unregister an observer for this views carriage.
 *   @param observer object to be unregistered. No more notifications will be received.
 */
void ViewsInkSupplyStation::unregisterObserver (IObserver &observer)
{
    assert_non_removable (0);
}

/** This method should be called by the observable to notify all the attached observers.
 *   @param reason is the slot position (0..n-1) of the ViewsInkSupply raising the change
 */
void ViewsInkSupplyStation::notify(uint32_t reason)
{
    assert_non_removable (0);
}



