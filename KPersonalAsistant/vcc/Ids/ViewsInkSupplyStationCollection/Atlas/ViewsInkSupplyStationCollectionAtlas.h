/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupplyStationCollectionAtlas.h
 *  @author Xavier Santotomas
 *  @date   Mon Nov 19 12:18:21 CET 2007
 *  @brief  Views Ink Supply Station Collection Atlas Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2003.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __ViewsInkSupplyStationCollectionAtlas_h_
#define __ViewsInkSupplyStationCollectionAtlas_h_

#include "IComponent.h"
#include "ViewsInkSupplyStationCollection/IViewsInkSupplyStationCollection.h"
#include "ViewsInkSupplyStation.h"
#include "InkSupplyStation/IInkSupplyStation.h"
#include "Cds/ICds.h"


/** This class provides a real implementation of the Views Ink Supply Station Collection abstraction interface.
 */
class ViewsInkSupplyStationCollectionAtlas : public IViewsInkSupplyStationCollection, 
                                             public IComponent
{
public:

    /** public constructor.
        @param instanceName instance name.
    */
    ViewsInkSupplyStationCollectionAtlas(std::string instanceName);

    /** public destructor.
     */
    virtual ~ViewsInkSupplyStationCollectionAtlas();
    
    /** @name IViewsInkSupplyStationCollection required methods.
        @{
    */
	
    /** Method returning a copy of the vector of Views Ink Supply Slots
     *   @return a copy of the vector of Views Ink Supply Slots
     */
    ViewsInkSupplySlotCollection getViewsInkSupplySlots();

    /** Method returning a copy of the vector of Views Ink Supply Stations
     *   @return a copy of the vector of Views Ink Supply Stations
     */
    ViewsInkSupplyStationCollection getViewsInkSupplyStations();

    /** Method returning a copy of the vector of Views Ink Supplies
     *   @return a copy of the vector of Views Ink Supplies
     */
    ViewsInkSupplyCollection getViewsInkSupplies();
 	
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
	

private:

    /** The pointer to the engine CDS instance. It allows access to his interface.
     */
    ICds *cds_;

    /** The list of views Ink Supply stations 
     */
    ViewsInkSupplyStationCollection viewsInkSupplyStationCollection_;
    
    /** The list of engine Ink Supply stations 
     */
    std::vector<IInkSupplyStation *> engineInkSupplyStationCollection_;
    
    /** The list of Views slots for Ink Supplies
     */
    ViewsInkSupplySlotCollection slotsCollection_;
    
    /** The list of Views Ink Supplies
     */
    ViewsInkSupplyCollection viewsInkSupplyCollection_;
    
    /**
     * To write logs in the system
     */
    Logging* log_;

};

#endif
