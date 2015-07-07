#ifndef MOD_VIEWSCARRIAGE_STUB_H
#define MOD_VIEWSCARRIAGE_STUB_H 

/////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsCarriageStub.h
 *  @author Josep Giralt
 *  @date   Tue Jun  3 19:28:38 CEST 2008
 *  @brief  Stub for the ViewsCarriage interface
 *          
 *
 *  (c) Copyright Hewlett-Packard Company, 2008.
 *  All rights reserved. Copying or other reproduction of this program except 
 *  for archival purposes is prohibited without written consent of 
 *  Hewlett-Packard Company. 
 * 
 */
//////////////////////////////////////////////////////////////////////////////


#include "IComponent.h"
#include "IRpc.h"
#include "ViewsCarriage/IViewsCarriage.h"

                                                                               
////////////////////////////////////////////////////////////////////////////// 
// 
// Public classes. 
// 
////////////////////////////////////////////////////////////////////////////// 

                                                                               
class ViewsCarriageStub : public IComponent
{

public:

    ViewsCarriageStub(std::string spaceName, std::string instanceName);

    ~ViewsCarriageStub();
    

    /** @name IComponent required functions.
     *  @{
     */        

    /** Initialize the component.
     *  @note At initialization time components must ask for all the memory and
     *  Operating System services that they are suposed to use. No other component or
     *  hardware access is allowed.
     * 
     *  @return RESULT_OK if successful, the failure code otherwise.
     */
    Result initialize(void);

    /** Start the component. 
     *  @note Components should perform the hardware related actions
     *  to turn into an operative status either through drivers or other
     *  components.
     * 
     *  @return RESULT_OK if successful, the failure code otherwise.
     */
    Result start(void);

    /** Perform an emergency shutdown.
     *  @note Only the indispensable actions should be performed.
     *
     *  @return  RESULT_OK if successful, the failure code otherwise.
     */
    Result emergencyShutdown(void);

    /** Shutdown the component.
     * 
     *  @return RESULT_OK if successful, the failure code otherwise.
     */
    Result shutdown(void);   

    /** Enter sleep mode.
     *  @note Most likely this would mean doing some power saving activities on it.
     * 
     *  @return  RESULT_OK if successful, the failure code otherwise.
     */
    Result enterSleepMode(void);

    /** Abandon the sleep mode.
     *
     *  @return  RESULT_OK if successful, the failure code otherwise.
     */
    Result exitSleepMode(void);

    /** Provide a pointer of a named interface.
     * 
     *  @param instanceName the name of the component instance providing the interface.
     *  @param interfaceName the name of the provided interface.
     *  @param interface a pointer to the provided interface.
     */
    void setInterface(std::string instanceName, std::string interfaceName, void * interface);

    /** Query for an an interface that you implement.
     * 
     *  @param interfaceName the name of the interface that other is asking you to provide.
     *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
     */
    void getInterface(std::string interfaceName, void ** interface);

    /** @}
     */   

private:

    /**
     * Private stub functions
     */

    static void getViewsPensAndSlots_Stub (void * param, tXdr * inXdr, tXdr * outXdr);

    /** @name IViewsPen stubs.
     *  @{
     */        

    static void getFeedingCartridges_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getJams_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getTotalLifeConsumption_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getPercentFired_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getMaxRecoveryLevel_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getNonHPInkUsed_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getExpiredInkUsed_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getSlotPosition_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getStatusAsStringKey_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getWarrantyStatus_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getWarrantyStatusAsStringKey_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getManufacturerDate_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getInstallDate_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getWarrantyExpirationDate_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void isMissing_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getColors_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getSerialNumber_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getManufacturer_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getOrderNumber_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getPartNumber_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getPrintableOrderNumber_Stub (void * param, tXdr * inXdr, tXdr * outXdr);

    /** @}
     */        

    /** @name IViewsPenSlot stubs.
     *  @{
     */        

    static void getTotalInsertionsCount_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getPensUsedCount_Stub (void * param, tXdr * inXdr, tXdr * outXdr);
    static void getPenEvents_Stub (void * param, tXdr * inXdr, tXdr * outXdr);

    /** @}
     */        

private:

    /** 
     * Pointer to the Rpc interface
     */
    IRpc           * rpc_;

    /**
     * Pointer to the local ViewsCarriage interface
     */
    IViewsCarriage * vc_;

    /**
     * Mark to know if stub was already installed
     */
    static bool      installed_;

};

#endif
