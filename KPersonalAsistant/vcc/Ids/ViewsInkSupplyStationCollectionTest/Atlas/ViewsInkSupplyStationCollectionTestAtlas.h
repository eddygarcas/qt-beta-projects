/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupplyStationCollectionTestAtlas.h
 *  @author Iqbal Shaikh
 *  @date   Thu June 12 12:16:21 CET 2008
 *  @brief  Views Ink Supply Station Collection Test Atlas Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2003.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __ViewsInkSupplyStationCollectionTestAtlas_h_
#define __ViewsInkSupplyStationCollectionTestAtlas_h_

#include "IComponent.h"
#include "ViewsInkSupplyStationCollection/IViewsInkSupplyStationCollection.h"
#include "ITest.h"
#include "FluidManager/IFluidManager.h"
#include "InkSupplyStation/IInkSupplyStation.h"
#include "Cds/ICds.h"


/** This class provides an entry point (like a main) for executing unit tests related with the ViewsInkSupplyStationCollection component.
*/
class ViewsInkSupplyStationCollectionTestAtlas : public IComponent, 
												 public ITest
{
public:
	
	static IViewsInkSupplyStationCollection* viewsInkSupplyStationCollection;
    static IInkSupplyStation * engineInkSupplyStationCollection;
	static IFluidManager* fluidManager;
	static ICds* cds;

    /** public constructor.
        @param instanceName instance name.
     */
    ViewsInkSupplyStationCollectionTestAtlas(std::string instanceName);

    /** public destructor.
     */
    virtual ~ViewsInkSupplyStationCollectionTestAtlas();
    
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
    
    /** launch the component. this method will be called call after the @e start() one so the component knowing that all the system is ready to be used.
        default implementation so it is not mandatory to implement it of not needed (that @e start() provides the desired  functionality).
        @return RESULT_OK if successful, the failure code otherwise.
        @note components could perform any task they want.
        @note this is not a "virtual" function providing an empty "safe" implementation.
	*/
    Result go (void);
    
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
    
    /** 
      * Method to run all the test suites implemented by this Test Component.
      *    
      */
    void runTest();

private:

    /** The pointer to the engine CDS instance. It allows access to his interface.
     */
    ICds *cds_;

    /** The list of views Ink Supply stations 
     */
    
    /** The list of engine Ink Supply stations 
     */
    
    /** The list of Views slots for Ink Supplies
    
    /** The list of Views Ink Supplies
     */

    /** This method should be called to lock access to a resource needing mutex access.
     */
    void lock();

    /** This method should be called to unlock access to a resource needing mutex access.
     */
    void unlock();
    
    /**
     * To guarantee mutual exclusion when accessing onChangeList_.
     */
    tRedOSMonitor monitor_;

    /**
     * To write logs in the system
     */
    Logging* log_;

};

#endif
