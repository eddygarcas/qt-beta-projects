/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsCarriageTestAtlas.cpp
 *  @author Jesus Barahona
 *  @date   Wed Oct 31 17:29:11 CEST 2007
 *  @brief  Views Carriage Test Atlas Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "SystemManager/SystemManager.h"
#include "ViewsCarriageTestAtlas.h"
#include "ViewsCarriageSuite.h"
#include "ViewsUnitTestingControllerAtlas.h"
#include "views_types.h"

#include <iostream>
#include <fstream>

//Initialize the static variables to be accessed from the test suite.
ICarriage* ViewsCarriageTestAtlas::carriage                         = NULL;
IViewsCarriage* ViewsCarriageTestAtlas::viewsCarriage               = NULL;
ISuppliesConfigurator* ViewsCarriageTestAtlas::suppliesConfigurator = NULL;
ICds* ViewsCarriageTestAtlas::cds = NULL;

/**
 *  IComponent required implementations.
 */

/**
 * When using METAGOD_DYNAMIC, the metagod infrastructure assumes that everything is written in C, so we need to
 * declare all the functions like plain C. Use "extern "C" " instead of just "extern" 
 * for the symbols to be stored as in plain C. 
 */
#ifdef METAGOD_DYNAMIC

extern "C" void * getViewsCarriageTestAtlas (const char * name);

/** create a fake instance of a ViewsCarriage.
    @param name instance name.
    @return a pointer to the instance.
*/
void * getViewsCarriageTestAtlas (const char * name)
{
    ViewsCarriageTestAtlas * it;
    it = new ViewsCarriageTestAtlas (std::string(name));
    assert (it);
    return (void *)it;
}

#else

/** create a fake instance of a ViewsCarriage.
    @param name instance name.
    @return a pointer to the instance.
*/
IComponent * getViewsCarriageTestAtlas (std::string name)
{
    ViewsCarriageTestAtlas * it;
    it = new ViewsCarriageTestAtlas (name);
    assert (it);
    return (IComponent *)it;
}
#endif

/** public constructor.
    @param instanceName instance name.
*/
ViewsCarriageTestAtlas::ViewsCarriageTestAtlas (std::string instanceName) : IComponent (instanceName, "ViewsCarriageTestAtlas")
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
ViewsCarriageTestAtlas::~ViewsCarriageTestAtlas ()
{
}

/** initialize the component.
 *  @note at initialization time components must ask for all the memory and
 *  Operating System services that they are suposed to use. No other component or
 *  hardware access is allowed.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsCarriageTestAtlas::initialize (void)
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
Result ViewsCarriageTestAtlas::start (void)
{   
    return RESULT_OK;
}

/** launch the component. this method will be called call after the @e start() one so the component knowing that all the system is ready to be used.
     default implementation so it is not mandatory to implement it of not needed (that @e start() provides the desired  functionality).
     @return RESULT_OK if successful, the failure code otherwise.
     @note components could perform any task they want.
     @note this is not a "virtual" function providing an empty "safe" implementation.
*/
Result ViewsCarriageTestAtlas::go(void)
{
	log_->log(LOG_INFO,"%s: Adding ViewsCarriageSuite to the ViewsUnitTestingController.\n",componentName().data());
		    
	ViewsUnitTestingControllerAtlas::runner.addTest( ViewsCarriageSuite::suite() );
	
    return RESULT_OK;
}


/** perform an emergency shutdown.
 *  @note only the indispensable actions should be performed.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsCarriageTestAtlas::emergencyShutdown (void)
{
	// nothing indispensable to do...
    return RESULT_OK;	
}

/** shutdown the component.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsCarriageTestAtlas::shutdown (void)
{
    return RESULT_OK;
}

/** enter sleep mode.
 *  @note most likely this would mean doing some power saving activities on it.
 * 
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsCarriageTestAtlas::enterSleepMode (void)
{
    return RESULT_OK;
}

/** abandon the sleep mode.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsCarriageTestAtlas::exitSleepMode (void)
{
    return RESULT_OK;
}

/** provide a pointer of a named interface.
 * 
 *  @param instanceName the name of the component instance providing the interface.
 *  @param interfaceName the name of the provided interface.
 *  @param interface a pointer to the provided interface.
 */
void ViewsCarriageTestAtlas::setInterface (std::string instanceName, std::string interfaceName, void *interface)
{
    if (interfaceName == "ICarriage")
    {
        ViewsCarriageTestAtlas::carriage = (ICarriage *)interface;
    }
    else if (interfaceName == "IViewsCarriage")
    {
    	ViewsCarriageTestAtlas::viewsCarriage = (IViewsCarriage *)interface;
    }
    else if (interfaceName == "ISuppliesConfigurator")
    {
    	ViewsCarriageTestAtlas::suppliesConfigurator = (ISuppliesConfigurator *)interface;
    }
    else if (interfaceName == "ICds")
    {
        ViewsCarriageTestAtlas::cds = (ICds *)interface;
    }
    else
    {
        assert (0);    	
    }
}

/** query for an an interface that you implement.
 * 
 *  @param interfaceName the name of the interface that other is asking you to provide.
 *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
 */
void ViewsCarriageTestAtlas::getInterface (std::string interfaceName, void **interface)
{
    assert (interfaceName == "ITest");
    *interface = (void *)((ITest *)this);
}

/** This method should be called to lock access to a resource needing mutex access.
 */
void ViewsCarriageTestAtlas::lock()
{
    tRedResult result;
    
    result = RedOSMonitorLock(monitor_, RED_WAIT_FOREVER);
    assert(result == RED_SUCCESS);
}

/** This method should be called to unlock access to a resource needing mutex access.
 */
void ViewsCarriageTestAtlas::unlock()
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
void ViewsCarriageTestAtlas::runTest()
{
    log_->log(LOG_INFO,"%s: Use the ViewsUnitTestController component to run the ViewsCarriageSuite!.\n",componentName().data());
}


