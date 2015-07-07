/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IObservable.h
 *  @author Xavier Santotomas
 *  @date   Jul 12 2007
 *  @brief  Views Observable Abstract
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __IObservable_h_
#define __IObservable_h_

#include "atlas_types.h"
#include "IObserver.h"



/** This class describes the Views Observable abstraction interface.
*/
class IObservable 
{

public:


    /** @name Views Observable public methods.
      @{
    */
    
    /** Method to register an Observer.
     *  @param observer object to be registered. Later the observer will be notified.
     */
    virtual void registerObserver(IObserver& observer) = 0;

    
    /** Method to register an Observer with a concrete aspect of interest.
     *  @param observer object to be registered. Later the observer will be notified.
     *  @param interest parameter allows registering observers only for specific events of interest.
     */
    virtual void registerObserver(IObserver& observer, Aspect& interest) {};


    /** Method to unregister a previously registered observer.
     *  @param observer object to be unregistered. No more notifications will be received.
     */
    virtual void unregisterObserver(IObserver& observer) = 0;


    /** @}
     */

protected:
    
    /** @name Views Observable protected methods.
      @{
    */

    /** This method should be called by the observable to notify all the attached observers.
     *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
     */
    virtual void notify(uint32_t reason) = 0;

    /** @}
     */

};

#endif
