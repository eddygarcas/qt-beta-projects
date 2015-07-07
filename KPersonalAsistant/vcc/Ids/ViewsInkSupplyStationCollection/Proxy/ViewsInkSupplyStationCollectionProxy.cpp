/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupplyStationCollectionProxy.cpp
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

#include "ViewsInkSupplyStationCollectionProxy.h"
#include "ViewsInkSupplyStation.h"
#include "ViewsInkSupplySlot.h"
#include "IRpcIdentifiers.h"
#include "SystemManager/SystemManager.h"


/** create a fake instance of a Ink Supply Station Collection.
    @param name instance name.
    @return a pointer to the instance.
*/
IComponent * getViewsInkSupplyStationCollectionProxy(std::string name)
{
    ViewsInkSupplyStationCollectionProxy * it;
    it = new ViewsInkSupplyStationCollectionProxy(name);
    assert_removable(it);
    return it;
}

/** public constructor.
 *   @param instanceName instance name.
 */
ViewsInkSupplyStationCollectionProxy::ViewsInkSupplyStationCollectionProxy(std::string instanceName) : IComponent(instanceName, "ViewsInkSupplyStationCollectionProxy")
{
}

/** public destructor.
 */
ViewsInkSupplyStationCollectionProxy::~ViewsInkSupplyStationCollectionProxy()
{
}

/** initialize the component.
 *  @note at initialization time components must ask for all the memory and
 *  Operating System services that they are suposed to use. No other component or
 *  hardware access is allowed.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionProxy::initialize(void)
{
    return RESULT_OK;
}

/** start the component. 
 *  @note components should perform the hardware related actions
 *  to turn into an operative status either through drivers or other
 *  components.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionProxy::start(void)
{    
}

/** launch the component. this method will be called call after the @e start() one so the component knowing that all the system is ready to be used.
    default implementation so it is not mandatory to implement it of not needed (that @e start() provides the desired  functionality).
    @return RESULT_OK if successful, the failure code otherwise.
*/
Result ViewsInkSupplyStationCollectionProxy::go (void)
{
#if 0
    tXdr *           inXdr;
    tXdr *           outXdr;
    Result           res;
    uint32_t         interface1;
    uint32_t         interface2;
    uint32_t         i;
    uint32_t         n;
    IViewsPen *      penPtr;
    IViewsPenSlot *  slotPtr;

    // upon the first request we will request all the IViewsPen & IViewsPenSlots pointers and
    // create local proxies for those.
    //

    // Create the encoding / decoding XDR's
    //
    res = rpc_->rpcXdrCreate(&inXdr, &outXdr);
    assert_removable (res == RESULT_OK);

    // Request the call
    //
    res = rpc_->rpcCallRequest(RPC_IVIEWSCARRIAGE_GETVIEWSPENSANDSLOTS, inXdr);
    assert_removable (res == RESULT_OK);

    // encode the interface.
    //
    interface1 = (uint32_t)vc_;
    XdrUInt32 (inXdr, &interface1);

    // Wait for the reply
    //
    res = rpc_->rpcCallWaitReply(RPC_IVIEWSCARRIAGE_GETVIEWSPENSANDSLOTS, outXdr);
    assert_removable (res == RESULT_OK);

    // Decode the IViewsPen pointers and insert them into the collection.
    //
    XdrUInt32(outXdr, &n);
    for (i = 0; i < n ; i++ )
    {   
        // decode the remote IViewsPen/IViewPenSlot pointers.
        //
        XdrUInt32 (outXdr, &interface1);
        XdrUInt32 (outXdr, &interface2);

        // create a local proxy that will interface with the remote one and 
        // insert it into the local vector. We pass the RPC interface that should
        // be used to interface with the remote pen. Those objects will never be
        // deleted because the pens never get destroyed.
        //
        penPtr = new ViewsPen (rpc_, (IViewsPen *)interface1);
        assert_removable (penPtr);
        viewsPenCollection_.push_back (penPtr);

        // create a local proxy that will interface with the remote one and 
        // insert it into the local vector. We pass the RPC interface that should
        // be used to interface with the remote pen. Those objects will never be
        // deleted because the pens never get destroyed.
        //
        slotPtr = new ViewsPenSlot (rpc_, (IViewsPenSlot *)interface2, (IViewsPen *)interface1);
        assert (slotPtr);
        slotsCollection_.push_back (slotPtr);
    }

    // Destroy previously allocated XDR's
    //
    res = rpc_->rpcXdrDestroy(inXdr, outXdr);
    assert_removable (res == RESULT_OK);

#endif
    return RESULT_OK;
}

/** perform an emergency shutdown.
 *  @note only the indispensable actions should be performed.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionProxy::emergencyShutdown(void)
{
    return RESULT_OK;
}

/** shutdown the component.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionProxy::shutdown(void)
{
    return RESULT_OK;
}

/** enter sleep mode.
 *  @note most likely this would mean doing some power saving activities on it.
 * 
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionProxy::enterSleepMode(void)
{
    return RESULT_OK;
}

/** abandon the sleep mode.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsInkSupplyStationCollectionProxy::exitSleepMode(void)
{
    return RESULT_OK;
}

/** provide a pointer of a named interface.
 * 
 *  @param instanceName the name of the component instance providing the interface.
 *  @param interfaceName the name of the provided interface.
 *  @param interface a pointer to the provided interface.
 */
void ViewsInkSupplyStationCollectionProxy::setInterface(std::string instanceName, std::string interfaceName, void *interface)
{
    if ( interfaceName == "IRpc" )
    {
        rpc_ = static_cast<IRpc *>(interface);
    }
    else if ( interfaceName == "IViewsInkSupplyStationCollection" )
    {
        ssCollection_ = static_cast<IViewsInkSupplyStationCollection *>(interface);
    }
    else
    {
        assert_removable (0);
    }
}

/** query for an an interface that you implement.
 * 
 *  @param interfaceName the name of the interface that other is asking you to provide.
 *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
 */
void ViewsInkSupplyStationCollectionProxy::getInterface(std::string interfaceName, void **interface)
{
    assert_removable(interfaceName == "IViewsInkSupplyStationCollection ");
    *interface = (void *)((IViewsInkSupplyStationCollection *)this);
}


/** Method returning a copy of the vector of Views Ink Supply Slots
 *   @return a copy of the vector of Views Ink Supply Slots
 */
ViewsInkSupplySlotCollection ViewsInkSupplyStationCollectionProxy::getViewsInkSupplySlots()
{
    return slotsCollection_;
}


/** Method returning a copy of the vector of Views Ink Supply Stations
 *   @return a copy of the vector of Views Ink Supply Stations
 */
ViewsInkSupplyStationCollection ViewsInkSupplyStationCollectionProxy::getViewsInkSupplyStations()
{
    return viewsInkSupplyStationCollection_;
}


/** Method returning a copy of the vector of Views Ink Supplies
 *   @return a copy of the vector of Views Ink Supplies
 */
ViewsInkSupplyCollection ViewsInkSupplyStationCollectionProxy::getViewsInkSupplies()
{
    return viewsInkSupplyCollection_;
}


