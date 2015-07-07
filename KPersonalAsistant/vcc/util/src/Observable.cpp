/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Observable.cpp
 *  @author Xavier Santotomas
 *  @date   Thu Apr 24 18:33:48 CEST 2008
 *  @brief  Views Observable implementation file
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2008.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 
#include "RedOS_pub_api.h"
#include <list>
#include "Observable.h"


/** public constructor.
 */
Observable::Observable(Logging * componentLog) 
{
	log_ = componentLog;

	//
	// Mutual exclusion semaphore.
	//
	monitor_ = RedOSMonitorCreate();
	//TODO: check where the next macro is placed. We dont find it!
	//assert_removable(monitor_ != 0);

}

/** public destructor.
 */
Observable::~Observable()
{
	// we don't do anything because the destructor is no called during the live of the System.
}



/** Method to be called to register a new Observer.
 *  @param observer object to be registered. Later will be notified.
 */
void Observable::registerObserver(IObserver &observer)
{
	lock();
	onChangeList_.push_back( &observer );
	unlock();
}

/** Method to register an Observer with a concrete aspect of interest.
 *  @param observer object to be registered. Later the observer will be notified.
 *  @param interest parameter allows registering observers only for specific events of interest.
 */
void Observable::registerObserver(IObserver& observer, Aspect& interest)
{
	//TODO: as we still dont offer this functionality, we just call to registerObserver without interest
	registerObserver(observer);
}


/** Method to be called to unregister an existant Observer.
 *  @param observer object to be unregistered. No more notifications will be received.
 */
void Observable::unregisterObserver(IObserver &observer)
{
	lock();
	onChangeList_.remove(&observer);
	unlock();
}


/** This method should be called by the observable to notify all the attached observers.
 *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void Observable::notify(uint32_t reason){

	for ( std::list<IObserver *>::iterator it = onChangeList_.begin() ; it != onChangeList_.end() ; it++ )
	{
		(*it)->onChange(*(static_cast<IObservable*>(this)), reason);
	}

}


/** This method should be called to lock access to a resource needing mutex access.
 */
void Observable::lock()
{
	tRedResult result;
	
	result = RedOSMonitorLock(monitor_, RED_WAIT_FOREVER);
	//TODO: check where the next macro is placed. We dont find it!
	//assert_removable(result == RED_SUCCESS);
}

/** This method should be called to unlock access to a resource needing mutex access.
 */
void Observable::unlock()
{
	RedOSMonitorUnlock(monitor_);
}



