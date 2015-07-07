/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsCarriageAtlas.h
 *  @author Xavier Santotomas
 *  @date   Wed Nov 21 11:46:08 CET 2007
 *  @brief  Views Carriage Atlas Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2003.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __ViewsCarriageAtlas_h_
#define __ViewsCarriageAtlas_h_

#include "IComponent.h"
#include "ViewsCarriage/IViewsCarriage.h"



/** This class provides the Atlas implementation of the Views Carriage abstraction interface.
*/
class ViewsCarriageAtlas : public IViewsCarriage, 
                           public IComponent
{
public:

    /** public constructor.
        @param instanceName instance name.
     */
    ViewsCarriageAtlas(std::string instanceName);

    /** public destructor.
     */
    virtual ~ViewsCarriageAtlas();
    
    /** @name IViewsCarriage required methods.
        @{
    */

	/** Method returning a copy of the vector of Views Pens
	 *   @return a copy of the vector of Views Pens
	 */
	ViewsPenCollection getViewsPens();

	/** Method returning a copy of the vector of Views Pen Slots
	 *   @return a copy of the vector of Views Pen Slots
	 */
	ViewsPenSlotCollection getViewsPenSlots();


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

    /** @name IComponent required functions.
     *  @{
     */        

    /** initialize the component.
     *  @note at initialization time components must ask for all the memory and
     *  Operating System services that they are suposed to use. No other component or
     *  hardware access is allowed.
     * 
     *  @return RESULT_OK if successful, the failure code otherwise.
     */
    Result initialize(void);
            

    /** start the component. 
     *  @note components should perform the hardware related actions
     *  to turn into an operative status either through drivers or other
     *  components.
     * 
     *  @return RESULT_OK if successful, the failure code otherwise.
     */
    Result start(void);

    /** perform an emergency shutdown.
     *  @note only the indispensable actions should be performed.
     *
     *  @return  RESULT_OK if successful, the failure code otherwise.
     */
    Result emergencyShutdown(void);

    /** shutdown the component.
     * 
     *  @return RESULT_OK if successful, the failure code otherwise.
     */
    Result shutdown(void);   

    /** enter sleep mode.
     *  @note most likely this would mean doing some power saving activities on it.
     * 
     *  @return  RESULT_OK if successful, the failure code otherwise.
     */
    Result enterSleepMode(void);
     
    /** abandon the sleep mode.
     *
     *  @return  RESULT_OK if successful, the failure code otherwise.
     */
    Result exitSleepMode(void);

    /** provide a pointer of a named interface.
     * 
     *  @param instanceName the name of the component instance providing the interface.
     *  @param interfaceName the name of the provided interface.
     *  @param interface a pointer to the provided interface.
     */
    void setInterface(std::string instanceName, std::string interfaceName, void *interface);

    /** query for an an interface that you implement.
     * 
     *  @param interfaceName the name of the interface that other is asking you to provide.
     *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
     */
    void getInterface(std::string interfaceName, void **interface);

    /** @}
     */        

protected: 
	
    /** @name IObservable required methods.
        @{
    */

    /** This method should be called by the observable to notify all the attached observers of this views carriage.
     *  @param reason is the slot position (0..n-1) of the ViewsPen raising the change
     */
    void notify(uint32_t reason);

    /** @}
     */

private:

    /** The pointer to the engine Carriage instance. It allows access to his interface.
     */
    ICarriage *carriage_;
    
    /** The pointer to the engine CDS instance. It allows access to his interface.
     */
    ICds *cds_;
    
    /** The pointer to the engine SuppliesConfigurator instance. It allows access to his interface.
     */
    ISuppliesConfigurator *suppliesConfigurator_;
    
    /** The list of views pens (not engine pens) 
     */
    ViewsPenCollection viewsPenCollection_;
    
    /** The list of Views Pen Slots for this Carriage.
     */
    ViewsPenSlotCollection slotsCollection_;
    
    /**
     * To write logs in the system
     */
    Logging *log_;
    
    /**
     * To implement the IObservable interface we will use delegation on a Observable object
     */
    Observable *myObservable_;
    
};

#endif
