/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Observable.h
 *  @author Xavier Santotomas
 *  @date  Thu Apr 24 18:19:03 CEST 2008 
 *  @brief  Views Observable header file
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2008.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 
#ifndef __Observable_h_
#define __Observable_h_

#include "RedOS_pub_api.h"
#include "IObservable.h"
#include "Logging.h"
#include <list>

/** This class describes the Views Observable.
*/
class Observable: public IObservable
{

public:

    /** public constructor.
     *   @param componentLog is the log created by the root component
     */
    Observable(Logging * componentLog);

    /** public destructor.
     */
    virtual ~Observable();


    /** @name IObservable public methods.
      @{
    */
    
    /** Method to register an Observer.
     *  @param observer object to be registered. Later the observer will be notified.
     */
    void registerObserver(IObserver& observer);

    
    /** Method to register an Observer with a concrete aspect of interest.
     *  @param observer object to be registered. Later the observer will be notified.
     *  @param interest parameter allows registering observers only for specific events of interest.
     */
    void registerObserver(IObserver& observer, Aspect& interest);


    /** Method to unregister a previously registered observer.
     *  @param observer object to be unregistered. No more notifications will be received.
     */
    void unregisterObserver(IObserver& observer);


    /** This method should be called by the observable to notify all the attached observers.
     *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
     */
    void notify(uint32_t reason);

    /** @}
     */

protected:
    
    /** @name IObservable protected methods.
      @{
    */


    /** @}
     */

private:
	
    /** This method should be called to lock access to a resource needing mutex access.
     */
    void lock();

    /** This method should be called to unlock access to a resource needing mutex access.
     */
    void unlock();

    /** This list will keep the list of observers for this views pen.
     */
    std::list <IObserver *>  onChangeList_;
    
    /**
     * To write logs in the system
     */
    Logging* log_;
    
    /**
     * To guarantee mutual exclusion when accessing onChangeList_
     */
    tRedOSMonitor monitor_;
    
    
};

#endif
