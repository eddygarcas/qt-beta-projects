/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsCarriageTestAtlas.h
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


#ifndef __ViewsCarriageTestAtlas_h_
#define __ViewsCarriageTestAtlas_h_

#include "ViewsCarriage/IViewsCarriage.h"
#include "Carriage/ICarriage.h"
#include "IComponent.h"
#include "ITest.h"
#include "RedOS_pub_api.h"
#include "Cds/ICds.h"


/** This class provides an entry point (like a main) for executing unit tests related with the ViewsCarriage component.
*/
class ViewsCarriageTestAtlas : public IComponent,
							   public ITest
{
public:
	// Allow these variables to be accessed by the test suite to perform the tests. 
    static ICarriage* carriage;
    static IViewsCarriage* viewsCarriage;
    static ISuppliesConfigurator* suppliesConfigurator;
    static ICds* cds;

    /** public constructor.
        @param instanceName instance name.
     */
    ViewsCarriageTestAtlas (std::string instanceName);

    /** public destructor.
     */
    virtual ~ViewsCarriageTestAtlas ();
    
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
    Result initialize (void);
            

    /** start the component. 
     *  @note components should perform the hardware related actions
     *  to turn into an operative status either through drivers or other
     *  components.
     * 
     *  @return RESULT_OK if successful, the failure code otherwise.
     */
    Result start (void);
    
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
    Result emergencyShutdown (void);

    /** shutdown the component.
     * 
     *  @return RESULT_OK if successful, the failure code otherwise.
     */
    Result shutdown (void);   

    /** enter sleep mode.
     *  @note most likely this would mean doing some power saving activities on it.
     * 
     *  @return  RESULT_OK if successful, the failure code otherwise.
     */
    Result enterSleepMode (void);
     
    /** abandon the sleep mode.
     *
     *  @return  RESULT_OK if successful, the failure code otherwise.
     */
    Result exitSleepMode (void);

    /** provide a pointer of a named interface.
     * 
     *  @param instanceName the name of the component instance providing the interface.
     *  @param interfaceName the name of the provided interface.
     *  @param interface a pointer to the provided interface.
     */
    void setInterface (std::string instanceName, std::string interfaceName, void *interface);

    /** query for an an interface that you implement.
     * 
     *  @param interfaceName the name of the interface that other is asking you to provide.
     *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
     */
    void getInterface (std::string interfaceName, void **interface);
    
    /** @name ITest required functions.
      *  @{
      */        
    
    /** 
      * Method to run all the test suites implemented by this Test Component.
      *    
      */
    void runTest();
    
    /** @}
     */        

protected: 
	
    /** @name IObservable required methods.
        @{
    */

	/** This method should be called by the observable to notify all the attached observers of this views carriage.
     *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
     */
    void notify(uint32_t reason);

    /** @}
     */

private:

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
    Logging *log_;
    
    
};

#endif
