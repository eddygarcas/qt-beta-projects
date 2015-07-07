/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupplyStationCollectionAtlas.cpp
 *  @author Xavier Santotomas
 *  @date   Tue Nov 20 16:29:29 CET 2007
 *  @brief  Views Ink Supply Station Collection Atlas Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "ViewsInkSupplyStationCollectionAtlas.h"
#include "Logging.h"
#include "ViewsInkSupplyStation.h"
#include "ViewsInkSupplySlot.h"
#include "FluidManager/IFluidManager.h"


/** create a fake instance of a Ink Supply Station Collection.
    @param name instance name.
    @return a pointer to the instance.
*/
IComponent * getViewsInkSupplyStationCollectionAtlas(std::string name)
{
    ViewsInkSupplyStationCollectionAtlas * it;
    it = new ViewsInkSupplyStationCollectionAtlas(name);
    assert_removable(it);
    return it;
}

/** public constructor.
 *   @param instanceName instance name.
 */
ViewsInkSupplyStationCollectionAtlas::ViewsInkSupplyStationCollectionAtlas(std::string instanceName) : IComponent(instanceName, "ViewsInkSupplyStationCollectionAtlas")
{
    // by definition this is a singleton, 
    // if you would need more than one instance sharing the same log,
    // check while creating the log if it's the first log created, in that case create it,
    // otherwise, retrieve the existant
    log_ = new Logging(componentName(), 3);
    log_->prefix("VCC");
    log_->set(0); //channel for info
    log_->set(1); //channel for warnings
    log_->set(2); //channel for errors
}

/** public destructor.
 */
ViewsInkSupplyStationCollectionAtlas::~ViewsInkSupplyStationCollectionAtlas()
{
    delete log_;
}

/** initialize the component.
 *  @note at initialization time components must ask for all the memory and
 *  Operating System services that they are suposed to use. No other component or
 *  hardware access is allowed.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionAtlas::initialize(void)
{
    return RESULT_OK;
}

/** start the component. 
 *  @note components should perform the hardware related actions
 *  to turn into an operative status either through drivers or other
 *  components.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionAtlas::start(void)
{    
    uint32_t totalISS =  engineInkSupplyStationCollection_.size();
    
    log_->log(0,"%s: My number of InkSupplyStations is: %d\n", componentName().data(), totalISS);
    
    for (uint32_t i=0; i < totalISS; i++ )
    {	
        // we create a new ViewsInkSupplyStation from the corresponding engine InkSupplyStation
        viewsInkSupplyStationCollection_.push_back(new ViewsInkSupplyStation(cds_, engineInkSupplyStationCollection_[i], log_));
    }
    
	
    for (ViewsInkSupplyStationIterator i = viewsInkSupplyStationCollection_.begin(); i != viewsInkSupplyStationCollection_.end(); i++) 
    {
        ViewsInkSupplyCollection inkSupplyCollection = (*i)->getViewsInkSupplies();
        for (ViewsInkSupplyIterator j = inkSupplyCollection.begin(); j != inkSupplyCollection.end(); j++)
        {
            IViewsInkSupply *currentViewsInkSupply = *j;

            //we create a new ViewsInkSupplySlot from the corresponding IViewsInkSupply
            slotsCollection_.push_back(new ViewsInkSupplySlot(cds_, currentViewsInkSupply, log_));

            //we add the views Ink Supply to the collection at the ViewsInkSupplyStationCollection level
            viewsInkSupplyCollection_.push_back(currentViewsInkSupply);
        }
    }
	
	
    return RESULT_OK;
}

/** perform an emergency shutdown.
 *  @note only the indispensable actions should be performed.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionAtlas::emergencyShutdown(void)
{
    return RESULT_OK;
}

/** shutdown the component.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionAtlas::shutdown(void)
{
    for (ViewsInkSupplyStationIterator i = viewsInkSupplyStationCollection_.begin(); i != viewsInkSupplyStationCollection_.end(); i++) 
    {
        delete *i;
    }

    for (ViewsInkSupplySlotIterator j = slotsCollection_.begin(); j != slotsCollection_.end(); j++) 
    {
        delete *j;
    }

    return RESULT_OK;
}

/** enter sleep mode.
 *  @note most likely this would mean doing some power saving activities on it.
 * 
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionAtlas::enterSleepMode(void)
{
    return RESULT_OK;
}

/** abandon the sleep mode.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionAtlas::exitSleepMode(void)
{
    return RESULT_OK;
}

/** provide a pointer of a named interface.
 * 
 *  @param instanceName the name of the component instance providing the interface.
 *  @param interfaceName the name of the provided interface.
 *  @param interface a pointer to the provided interface.
 */
void ViewsInkSupplyStationCollectionAtlas::setInterface(std::string instanceName, std::string interfaceName, void *interface)
{
    if (interfaceName == "IFluidManager")
    {
        /* add the ink supply station supplied by the Fluid Manager to the list of engine ink supply stations.
         */
        InkSupplyStationCollection issColection =  ((IFluidManager *)interface)->getInkSupplyStation();
        
        for (uint32_t i = 0; i < issColection.size(); i++) 
        {
            engineInkSupplyStationCollection_.push_back(issColection[i]);
        }
    }
    else if (interfaceName == "ICds")
    {
	cds_ = (ICds *)interface;
    }
    else
    {
        assert_removable(0);
    }	
}

/** query for an an interface that you implement.
 * 
 *  @param interfaceName the name of the interface that other is asking you to provide.
 *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
 */
void ViewsInkSupplyStationCollectionAtlas::getInterface(std::string interfaceName, void **interface)
{
    assert_removable(interfaceName == "IViewsInkSupplyStationCollection");
    *interface = (void *)((IViewsInkSupplyStationCollection  *)this);

}


/** Method returning a copy of the vector of Views Ink Supply Slots
 *   @return a copy of the vector of Views Ink Supply Slots
 */
ViewsInkSupplySlotCollection ViewsInkSupplyStationCollectionAtlas::getViewsInkSupplySlots()
{
    return slotsCollection_;
}


/** Method returning a copy of the vector of Views Ink Supply Stations
 *   @return a copy of the vector of Views Ink Supply Stations
 */
ViewsInkSupplyStationCollection ViewsInkSupplyStationCollectionAtlas::getViewsInkSupplyStations()
{
    return viewsInkSupplyStationCollection_;
}


/** Method returning a copy of the vector of Views Ink Supplies
 *   @return a copy of the vector of Views Ink Supplies
 */
ViewsInkSupplyCollection ViewsInkSupplyStationCollectionAtlas::getViewsInkSupplies()
{
    return viewsInkSupplyCollection_;
}


