/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupplyStation.h
 *  @author Josep Giralt
 *  @date   Tue Jun  3 19:28:38 CEST 2008
 *  @brief  Views Ink Supply Station Proxy Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2003.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __ViewsInkSupplyStation_h_
#define __ViewsInkSupplyStation_h_

#include "ViewsInkSupplyStationCollection/IViewsInkSupplyStation.h"


/** This class provides a real implementation of the Views Ink Supply Station abstraction interface.
*/
class ViewsInkSupplyStation : public IViewsInkSupplyStation
{
public:

    /** public constructor.
     *  @param rpc Pointer to the RPC interface to be used to interface with the remote pen.
     *  @param the ISS Pointer to the remote IViewsInkSupplyStation interface.
     *  @param the collection of Views Ink Supplies binded to the ISS.
    */
    ViewsInkSupplyStation (IRpc * rpc, IViewsInkSupplyStation * theISS, const ViewsInkSupplyCollection & viewsInkSupplies);

    /** public destructor.
     */
    virtual ~ViewsInkSupplyStation();
    
    /** @name IViewsInkSupplyStation required methods.
        @{
    */

    /** Method returning a copy of the vector of Views Ink Supplies
     *   @return a copy of the vector of Views Ink Supplies
     */
    ViewsInkSupplyCollection getViewsInkSupplies();
    
    /** @}
     */

    /** @name IObserver required methods.
        @{
    */

    /** method to receive notificatios from the observable objects.
     *  @param observable is the object that forced the execution of this method.
     *  @param reason reason for the callback, it has to be defined in the class using this callback.
     */
    void onChange(IObservable &observable, uint32_t reason);
	
    /** @}
     */
	
    /** @name IObservable required methods.
        @{
    */
	
    /** Method to register an observer for this views carriage.
     *  @param observer object to be registered. Later will be notified.
     */
    void registerObserver(IObserver &observer);
	
	
    /** Method to unregister an observer for this views carriage.
     *  @param observer object to be unregistered. No more notifications will be received.
     */
    void unregisterObserver(IObserver &observer);

    /** @}
     */

protected: 
	
    /** @name IObservable required protected functions.
     *  @{
     */        

    /** This method should be called by the observable to notify all the attached observers of this views pen.
     *  @param reason is the slot position (0..n-1) of the ViewsInkSupply raising the change
     */
    void notify(uint32_t reason);

    /** @}
     */

private:

    /** The list of views Ink Supplies binded to this Supply Station.
     */
    ViewsInkSupplyCollection viewsInkSupplies_;
      

    /** Pointer to the Rpc interface
     */
    IRpc *      rpc_;
};

#endif
