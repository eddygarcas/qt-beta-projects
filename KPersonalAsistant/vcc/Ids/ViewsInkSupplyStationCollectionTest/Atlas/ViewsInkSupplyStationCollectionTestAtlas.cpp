/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupplyStationCollectionTestAtlas.cpp
 *  @author Iqbal Shaikh
 *  @date   Thu Jun 12 12:36:29 CET 2008
 *  @brief  Views Ink Supply Station Collection Test Atlas Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "Logging.h"
#include "ViewsInkSupplyStationCollectionTestAtlas.h"
#include "ViewsInkSupplyStationCollection/Atlas/ViewsInkSupplyStation.h"
#include "ViewsInkSupplyStationCollection/Atlas/ViewsInkSupplySlot.h"
#include "ViewsUnitTestingControllerAtlas.h"
#include "ViewsInkSupplyStationCollectionSuite.h"
#include "views_types.h"

IViewsInkSupplyStationCollection* ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection = NULL;
IInkSupplyStation * ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection;
IFluidManager* ViewsInkSupplyStationCollectionTestAtlas::fluidManager = NULL;
ICds* ViewsInkSupplyStationCollectionTestAtlas::cds = NULL;

/**
 * When using METAGOD_DYNAMIC, the metagod infrastructure assumes that everything is written in C, so we need to
 * declare all the functions like plain C. Use "extern "C" " instead of just "extern" 
 * for the symbols to be stored as in plain C. 
 */
#ifdef METAGOD_DYNAMIC

extern "C" void * getViewsInkSupplyStationCollectionTestAtlas (const char * name);

/** create a fake instance of a ViewsInkSupplyStationCollection.
    @param name instance name.
    @return a pointer to the instance.
*/
void * getViewsInkSupplyStationCollectionTestAtlas (const char * name)
{
	ViewsInkSupplyStationCollectionTestAtlas * it;
    it = new ViewsInkSupplyStationCollectionTestAtlas (std::string(name));
    assert(it);
    return (void *)it;
}

#else

/** create a fake instance of a Ink Supply Station Collection.
    @param name instance name.
    @return a pointer to the instance.
*/
IComponent * getViewsInkSupplyStationCollectionTestAtlas(std::string name)
{
    ViewsInkSupplyStationCollectionTestAtlas * it;
    it = new ViewsInkSupplyStationCollectionTestAtlas(name);
    assert(it);
    return (IComponent *)it;
}
#endif

/** public constructor.
 *   @param instanceName instance name.
 */
ViewsInkSupplyStationCollectionTestAtlas::ViewsInkSupplyStationCollectionTestAtlas(std::string instanceName) : IComponent(instanceName, "ViewsInkSupplyStationCollectionTestAtlas")
{
	//
    // Mutual exclusion semaphore.
    //
    monitor_ = RedOSMonitorCreate();
    assert(monitor_ != 0);
	
	// by definition this is a singleton, 
	// if you would need more than one instance sharing the same log,
	// check while creating the log if it's the first log created, in that case create it,
	// otherwise, retrieve the existant
	log_ = new Logging(componentName(), 3);
	log_->prefix("VCC");
	log_->set(LOG_INFO); //channel for info
	log_->set(LOG_WARNING); //channel for warnings
	log_->set(LOG_ERROR); //channel for errors
}

/** public destructor.
 */
ViewsInkSupplyStationCollectionTestAtlas::~ViewsInkSupplyStationCollectionTestAtlas()
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
Result ViewsInkSupplyStationCollectionTestAtlas::initialize(void)
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
Result ViewsInkSupplyStationCollectionTestAtlas::start(void)
{    
	return RESULT_OK;
}

/** launch the component. this method will be called call after the @e start() one so the component knowing that all the system is ready to be used.
    default implementation so it is not mandatory to implement it of not needed (that @e start() provides the desired  functionality).
    @return RESULT_OK if successful, the failure code otherwise.
    @note components could perform any task they want.
    @note this is not a "virtual" function providing an empty "safe" implementation.
*/
Result ViewsInkSupplyStationCollectionTestAtlas::go (void)
{
	log_->log(LOG_INFO,"%s: Adding ViewsInkSupplyStationCollectionSuite to the ViewsUnitTestingController.\n",componentName().data());
		    
	ViewsUnitTestingControllerAtlas::runner.addTest( ViewsInkSupplyStationCollectionSuite::suite() );

	return RESULT_OK;
}

/** perform an emergency shutdown.
 *  @note only the indispensable actions should be performed.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionTestAtlas::emergencyShutdown(void)
{
	return RESULT_OK;
}

/** shutdown the component.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionTestAtlas::shutdown(void)
{
    	return RESULT_OK;
}

/** enter sleep mode.
 *  @note most likely this would mean doing some power saving activities on it.
 * 
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionTestAtlas::enterSleepMode(void)
{
    	return RESULT_OK;
}

/** abandon the sleep mode.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionTestAtlas::exitSleepMode(void)
{
    	return RESULT_OK;
}

/** provide a pointer of a named interface.
 * 
 *  @param instanceName the name of the component instance providing the interface.
 *  @param interfaceName the name of the provided interface.
 *  @param interface a pointer to the provided interface.
 */
void ViewsInkSupplyStationCollectionTestAtlas::setInterface(std::string instanceName, std::string interfaceName, void *interface)
{	
    if (interfaceName == "IFluidManager")
    {
    	/* add the ink supply station supplied by the Fluid Manager to the list of engine ink supply stations.
         */
    	ViewsInkSupplyStationCollectionTestAtlas::fluidManager = ((IFluidManager *)interface);
    }
    else if (interfaceName == "IViewsInkSupplyStationCollection")
    {
    	ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection = (IViewsInkSupplyStationCollection *)interface;
    }
    else if (interfaceName == "ICds")
    {
    	ViewsInkSupplyStationCollectionTestAtlas::cds = (ICds *)interface;
    }
    else	
    {
        assert(0);
    }	
}

/** query for an an interface that you implement.
 * 
 *  @param interfaceName the name of the interface that other is asking you to provide.
 *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
 */
void ViewsInkSupplyStationCollectionTestAtlas::getInterface(std::string interfaceName, void **interface)
{
    assert(interfaceName == "ITest");
    *interface = (void *)((ITest *)this);
}

/** This method should be called to lock access to a resource needing mutex access.
 */
void ViewsInkSupplyStationCollectionTestAtlas::lock()
{
    tRedResult result;
    
    result = RedOSMonitorLock(monitor_, RED_WAIT_FOREVER);
    assert(result == RED_SUCCESS);
}

/** This method should be called to unlock access to a resource needing mutex access.
 */
void ViewsInkSupplyStationCollectionTestAtlas::unlock()
{
    RedOSMonitorUnlock(monitor_);
}

/**
 *  ITest required implementations.
 */

/** 
  * Method to run all the test suites implemented by this Test Component.
  *    
  */
void ViewsInkSupplyStationCollectionTestAtlas::runTest()
{
    log_->log(LOG_INFO,"%s: Use the ViewsUnitTestController component to run the ViewsInkSupplyStationCollectionSuite!.\n",componentName().data());
}


