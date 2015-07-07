/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupplyStationCollectionProxy.h
 *  @author Josep Giralt
 *  @date   Tue Jun  3 19:28:38 CEST 2008
 *  @brief  Views Ink Supply Station Collection Proxy Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2008.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __ViewsInkSupplyStationCollectionProxy_h_
#define __ViewsInkSupplyStationCollectionProxy_h_

#include "IComponent.h"
#include "ViewsInkSupplyStationCollection/IViewsInkSupplyStationCollection.h"
#include "ViewsInkSupplyStation.h"


/** This class provides a real implementation of the Views Ink Supply Station Collection abstraction interface.
 */
class ViewsInkSupplyStationCollectionProxy : public IViewsInkSupplyStationCollection, 
                                             public IComponent
{
public:

    /** public constructor.
        @param instanceName instance name.
    */
    ViewsInkSupplyStationCollectionProxy (std::string instanceName);

    /** public destructor.
     */
    virtual ~ViewsInkSupplyStationCollectionProxy ();
    
    /** @name IViewsInkSupplyStationCollection required methods.
        @{
    */
	
    /** Method returning a copy of the vector of Views Ink Supply Slots
     *   @return a copy of the vector of Views Ink Supply Slots
     */
    ViewsInkSupplySlotCollection getViewsInkSupplySlots ();

    /** Method returning a copy of the vector of Views Ink Supply Stations
     *   @return a copy of the vector of Views Ink Supply Stations
     */
    ViewsInkSupplyStationCollection getViewsInkSupplyStations ();

    /** Method returning a copy of the vector of Views Ink Supplies
     *   @return a copy of the vector of Views Ink Supplies
     */
    ViewsInkSupplyCollection getViewsInkSupplies ();
 	
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

    /** launch the component. this method will be called call after the @e start() one so the component knowing that all the system is ready to be used.
        default implementation so it is not mandatory to implement it of not needed (that @e start() provides the desired  functionality).
        @return RESULT_OK if successful, the failure code otherwise.
     */
    Result go (void);

    /** @}
     */        

protected: 
	

private:

    /** Pointer to the Rpc interface
     */
    IRpc * rpc_;

    /** pointer to the remote views Ink Supply station collection interface.
     */
    IViewsInkSupplyStationCollection * ssCollection_;

    /** The list of Views Ink Supply stations.
     */
    ViewsInkSupplyStationCollection viewsInkSupplyStationCollection_;
    
    /** The list of Views slots for Ink Supplies
     */
    ViewsInkSupplySlotCollection slotsCollection_;
    
    /** The list of Views Ink Supplies
     */
    ViewsInkSupplyCollection viewsInkSupplyCollection_;
    
};

#endif
