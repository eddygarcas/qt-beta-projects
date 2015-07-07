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
#include "ViewsInkSupply.h"

/** public constructor.
 *   @param cdsInterface is the CDS interface
 *   @param myInkSupplyStation is a pointer to the Engine Ink Supply Station.
 *   @param componentLogging is the log created by the root component
 */
ViewsInkSupplyStation::ViewsInkSupplyStation(ICds * cdsInterface, IInkSupplyStation *myInkSupplyStation, Logging *componentLogging) 
{
	
    log_ = componentLogging;
	
    engineInkSupplyStation_ = myInkSupplyStation;
	
    // we get engine instances of the Ink Supply Stations
    std::vector<IInkSupply *> engineInkSupplies= myInkSupplyStation->getSupplies();

    uint32_t totalIS =  engineInkSupplies.size();
    
    log_->log(0,"ViewsInkSupplyStation: My number of Ink Supplies is: %d\n", totalIS);
    
    for (uint32_t i=0; i < totalIS; i++ )
    {	
        // we create a new ViewsInkSupply from the corresponding Engine instance
        viewsInkSupplies_.push_back(new ViewsInkSupply(cdsInterface, engineInkSupplies[i], log_));
    		
        // as ViewsInkSupply is an observable, 
        // we register ViewsInkSupplyStation itself as a observer of ViewsInkSupply
        viewsInkSupplies_.back()->registerObserver(*this);
    		
    }

    myObservable_ = new Observable(componentLogging);
    	
}
	

/** public destructor.
 */
ViewsInkSupplyStation::~ViewsInkSupplyStation()
{
    for (ViewsInkSupplyIterator i = viewsInkSupplies_.begin(); i != viewsInkSupplies_.end(); i++)
    {
        IViewsInkSupply*currentViewsInkSupply = *i;
        currentViewsInkSupply->unregisterObserver(*this);
        delete currentViewsInkSupply;
    }

    delete myObservable_;

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
void ViewsInkSupplyStation::onChange(IObservable &observable, uint32_t reason)
{

    ViewsInkSupply &observableViewsSupply = (ViewsInkSupply &)observable;
		
    // notify this change to all registered observers (for ViewsInkSupplyStation observers the reason will be the IViewsInkSupply slot)
    notify(observableViewsSupply.getSlotPosition());
}


/** Method to register an observer for this views carriage.
 *   @param observer object to be registered. Later will be notified.
 */
void ViewsInkSupplyStation::registerObserver(IObserver &observer)
{
    myObservable_->registerObserver(observer);
}


/** Method to unregister an observer for this views carriage.
 *   @param observer object to be unregistered. No more notifications will be received.
 */
void ViewsInkSupplyStation::unregisterObserver(IObserver &observer)
{
    myObservable_->unregisterObserver(observer);	
}

/** This method should be called by the observable to notify all the attached observers.
 *   @param reason is the slot position (0..n-1) of the ViewsInkSupply raising the change
 */
void ViewsInkSupplyStation::notify(uint32_t reason)
{
    myObservable_->notify(reason);	
}



