/////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsCarriageStub.cpp
 *  @author Josep Giralt
 *  @date   Tue Jun  3 19:28:38 CEST 2008
 *  @brief  Stub for the IViewsCarriage interface
 *          
 *
 *  (c) Copyright Hewlett-Packard Company, 2004.
 *  All rights reserved. Copying or other reproduction of this program except 
 *  for archival purposes is prohibited without written consent of 
 *  Hewlett-Packard Company. 
 * 
 */
//////////////////////////////////////////////////////////////////////////////
                                                                           
#include "SystemManager/SystemManager.h"
#include "ViewsCarriageStub.h"
#include "IRpcIdentifiers.h"
#include "xdr_penhistory.h"                                        

bool ViewsCarriageStub::installed_ = false;


////////////////////////////////////////////////////////////////////////////// 
//                                                                             
// Factory for the MetaGod                                                     
//                                                                             
////////////////////////////////////////////////////////////////////////////// 


IComponent * getViewsCarriageMipsStub(std::string spaceName, std::string instanceName)
{
    ViewsCarriageStub * it;
    it = new ViewsCarriageStub(spaceName, instanceName);
    assert_removable(it);
    return it;
} 

////////////////////////////////////////////////////////////////////////////// 
//                                                                              
//  CONSTRUCTOR - DESTRUCTOR
//                                                                             
////////////////////////////////////////////////////////////////////////////// 


ViewsCarriageStub::ViewsCarriageStub(std::string spaceName, std::string instanceName) : IComponent (instanceName, "ViewsCarriageStub")
{
}


ViewsCarriageStub::~ViewsCarriageStub()
{
}


////////////////////////////////////////////////////////////////////////////// 
//                                                                              
// Public IComponent functions / methods.                                      
//                                                                             
////////////////////////////////////////////////////////////////////////////// 


Result ViewsCarriageStub::initialize(void)
{
    rpc_ = static_cast<IRpc*>(NULL);
    vc_  = static_cast<IViewsCarriage*>(NULL);

    return RESULT_OK;
}


Result ViewsCarriageStub::start(void)
{
    Result res;

    assert_removable( rpc_ );
    assert_removable( vc_ );

    IComponent::lockStart();

    if ( !installed_ )
    {
        // Register class-wide functions 
        //
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETVIEWSPENSANDSLOTS, getViewsPensAndSlots_Stub, (void *) this);
        assert_removable (res == RESULT_OK);

        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETFEEDINGCARTRIDGES, getFeedingCartridges_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETJAMS, getJams_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETTOTALLIFECONSUMPTION, getTotalLifeConsumption_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETPERCENTFIRED, getPercentFired_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETMAXRECOVERYLEVEL, getMaxRecoveryLevel_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETNONHPINKUSED, getNonHPInkUsed_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETEXPIREDINKUSED, getExpiredInkUsed_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETSLOTPOSITION, getSlotPosition_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETSTATUSASSTRINGKEY, getStatusAsStringKey_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETWARRANTYSTATUS, getWarrantyStatus_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETWARRANTYSTATUSASSTRINGKEY, getWarrantyStatusAsStringKey_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETMANUFACTURERDATE, getManufacturerDate_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETINSTALLDATE, getInstallDate_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETWARRANTYEXPIRATIONDATE, getWarrantyExpirationDate_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_ISMISSING, isMissing_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETCOLORS, getColors_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETSERIALNUMBER, getSerialNumber_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETMANUFACTURER, getManufacturer_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETORDERNUMBER, getOrderNumber_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETPARTNUMBER, getPartNumber_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETPRINTABLEORDERNUMBER, getPrintableOrderNumber_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETTOTALINSERTIONSCOUNT, getTotalInsertionsCount_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETPENSUSEDCOUNT, getPensUsedCount_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        res = rpc_->rpcStubRegister (RPC_IVIEWSCARRIAGE_GETPENEVENTS, getPenEvents_Stub, (void *)this);
        assert_removable (res == RESULT_OK);
        
        installed_ = true;
    }

    IComponent::unlockStart();

    return RESULT_OK;
}


Result ViewsCarriageStub::emergencyShutdown(void)
{
    return RESULT_OK;
}


Result ViewsCarriageStub::shutdown(void)
{
    return RESULT_OK;
}


Result ViewsCarriageStub::enterSleepMode(void)
{
    return RESULT_OK;
}


Result ViewsCarriageStub::exitSleepMode(void)
{
    return RESULT_OK;
}


void ViewsCarriageStub::setInterface(std::string instanceName, std::string interfaceName, void * interface)
{
    if ( interfaceName == "IRpc" )  
    {
        rpc_ = static_cast<IRpc*>(interface);
    }
    else if ( interfaceName == "IViewsCarriage" )
    {
        vc_ = static_cast<IViewsCarriage*>(interface);
    }
    else
    {
        assert_removable (0);
    }
}


void ViewsCarriageStub::getInterface(std::string interfaceName, void ** interface)
{
    assert_non_removable (0);
}


////////////////////////////////////////////////////////////////////////////// 
// 
// STUB functions
// 
//////////////////////////////////////////////////////////////////////////////


void ViewsCarriageStub::getViewsPensAndSlots_Stub(void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsCarriage *       vc;
    uint32_t               interface;
    ViewsPenSlotCollection slots;
    ViewsPenSlotIterator   iter;
    uint32_t               n;
    
    // decode the IViewsCarriage interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vc = (IViewsCarriage *) interface;
    
    // fetch the slots.
    //
    slots = vc->getViewsPenSlots ();
    
    // encode the number of slots.
    //
    n = slots.size ();
    XdrUInt32 (outXdr, &n);

    // encode the pen and slot interfaces.
    //
    for (iter = slots.begin() ; iter != slots.end() ; iter++)
    {   
        // encode the pen.
        interface = (uint32_t)((*iter)->getPen());
        XdrUInt32 (outXdr, &interface);
        
        // encode the slot.
        interface = (uint32_t)(*iter);
        XdrUInt32 (outXdr, &interface);
    }
}


void ViewsCarriageStub::getFeedingCartridges_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen *           vpen;
    uint32_t              interface;
    std::vector<uint16_t> vec;
    std::vector<uint16_t>::iterator iter;
    uint32_t              n;
    uint16_t              v;

    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value..
    //
    vec = vpen->getFeedingCartridges ();
    
    // encode the number of values.
    //
    n = vec.size ();
    XdrUInt32 (outXdr, &n);

    // encode the values.
    //
    for (iter = vec.begin() ; iter != vec.end() ; iter++)
    {
        v = *iter;
        XdrUInt16 (outXdr, &v);
    }
}

void ViewsCarriageStub::getJams_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint32_t    v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the values.
    //
    v = vpen->getJams ();
    
    // encode the value.
    //
    XdrUInt32 (outXdr, &v);
}

void ViewsCarriageStub::getTotalLifeConsumption_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint32_t    v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getTotalLifeConsumption ();
    
    // encode the value.
    //
    XdrUInt32 (outXdr, &v);
}

void ViewsCarriageStub::getPercentFired_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint32_t    v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the slots.
    //
    v = vpen->getPercentFired ();
    
    // encode the value.
    //
    XdrUInt32 (outXdr, &v);
}

void ViewsCarriageStub::getMaxRecoveryLevel_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint32_t    v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getMaxRecoveryLevel ();
    
    // encode the value.
    //
    XdrUInt32 (outXdr, &v);
}

void ViewsCarriageStub::getNonHPInkUsed_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint8_t     v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the slots.
    //
    v = vpen->getNonHPInkUsed () ? 1 : 0;
    
    // encode the value.
    //
    XdrBoolean (outXdr, &v);
}

void ViewsCarriageStub::getExpiredInkUsed_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint8_t     v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getExpiredInkUsed () ? 1 : 0;
    
    // encode the value.
    //
    XdrBoolean (outXdr, &v);
}

void ViewsCarriageStub::getSlotPosition_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint32_t    v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getSlotPosition ();
    
    // encode the value.
    //
    XdrUInt32 (outXdr, &v);
}

void ViewsCarriageStub::getStatusAsStringKey_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen *  vpen;
    uint32_t     interface;
    std::string  v;
    const char * ptr;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getStatusAsStringKey ();
    
    // encode the value.
    //
    ptr = (char *)v.c_str();
    XdrString (outXdr, (unsigned char **)&ptr, v.length()+1);
}

void ViewsCarriageStub::getWarrantyStatus_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint32_t    v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getWarrantyStatus ();
    
    // encode the value.
    //
    XdrUInt32 (outXdr, &v);
}

void ViewsCarriageStub::getWarrantyStatusAsStringKey_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
}

void ViewsCarriageStub::getManufacturerDate_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint32_t    v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getManufacturerDate ();
    
    // encode the value.
    //
    XdrUInt32 (outXdr, &v);
}

void ViewsCarriageStub::getInstallDate_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint32_t    v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getInstallDate ();
    
    // encode the value.
    //
    XdrUInt32 (outXdr, &v);
}

void ViewsCarriageStub::getWarrantyExpirationDate_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint32_t    v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getWarrantyExpirationDate ();
    
    // encode the value.
    //
    XdrUInt32 (outXdr, &v);
}

void ViewsCarriageStub::isMissing_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint8_t     v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getExpiredInkUsed () ? 1 : 0;
    
    // encode the value.
    //
    XdrBoolean (outXdr, &v);
}

void ViewsCarriageStub::getColors_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen *             vpen;
    uint32_t                interface;
    std::vector<CDSColorId> vec;
    std::vector<CDSColorId>::iterator iter;
    uint32_t                n;
    int16_t                 v;

    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the values.
    //
    vec = vpen->getColors ();
    
    // encode the number of values.
    //
    n = vec.size ();
    XdrUInt32 (outXdr, &n);

    // encode the values.
    //
    for (iter = vec.begin() ; iter != vec.end() ; iter++)
    {
        v = (int16_t)*iter;
        XdrSInt16 (outXdr, &v);
    }
}

void ViewsCarriageStub::getSerialNumber_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen *  vpen;
    uint32_t     interface;
    std::string  v;
    const char * ptr;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getSerialNumber ();
    
    // encode the value.
    //
    ptr = (char *)v.c_str();
    XdrString (outXdr, (unsigned char **)&ptr, v.length()+1);
}

void ViewsCarriageStub::getManufacturer_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen * vpen;
    uint32_t    interface;
    uint32_t    v;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getManufacturer ();
    
    // encode the value.
    //
    XdrUInt32 (outXdr, &v);
}

void ViewsCarriageStub::getOrderNumber_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen *  vpen;
    uint32_t     interface;
    std::string  v;
    const char * ptr;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getOrderNumber ();
    
    // encode the value.
    //
    ptr = (char *)v.c_str();
    XdrString (outXdr, (unsigned char **)&ptr, v.length()+1);
}

void ViewsCarriageStub::getPartNumber_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen *  vpen;
    uint32_t     interface;
    std::string  v;
    const char * ptr;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getPartNumber ();
    
    // encode the value.
    //
    ptr = (char *)v.c_str();
    XdrString (outXdr, (unsigned char **)&ptr, v.length()+1);
}

void ViewsCarriageStub::getPrintableOrderNumber_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPen *  vpen;
    uint32_t     interface;
    std::string  v;
    const char * ptr;
    
    // decode the IViewsPen interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vpen = (IViewsPen *) interface;
    
    // fetch the value.
    //
    v = vpen->getPrintableOrderNumber ();
    
    // encode the value.
    //
    ptr = (char *)v.c_str();
    XdrString (outXdr, (unsigned char **)&ptr, v.length()+1);
}

void ViewsCarriageStub::getTotalInsertionsCount_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPenSlot * vslot;
    uint32_t        interface;
    uint32_t        v;
    
    // decode the IViewsPenSlot interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vslot = (IViewsPenSlot *) interface;
    
    // fetch the value.
    //
    v = vslot->getTotalInsertionsCount ();
    
    // encode the value.
    //
    XdrUInt32 (outXdr, &v);
}

void ViewsCarriageStub::getPensUsedCount_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPenSlot * vslot;
    uint32_t        interface;
    uint32_t        v;
    
    // decode the IViewsPenSlot interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vslot = (IViewsPenSlot *) interface;
    
    // fetch the value.
    //
    v = vslot->getPensUsedCount ();
    
    // encode the value.
    //
    XdrUInt32 (outXdr, &v);
}

void ViewsCarriageStub::getPenEvents_Stub (void * param, tXdr * inXdr, tXdr * outXdr)
{
    IViewsPenSlot * vslot;
    uint32_t        interface;
    std::vector<IViewsPenSlot::PenHistoryRecord> vec;
    std::vector<IViewsPenSlot::PenHistoryRecord>::iterator iter;
    uint32_t                n;

    // decode the IViewsPenSlot interface
    //
    XdrUInt32 (inXdr, &interface);
    assert_removable( interface );
    vslot = (IViewsPenSlot *) interface;
    
    // fetch the values and encode the number of values.
    //
    n = vslot->getPenEvents (vec);
    XdrUInt32 (outXdr, &n);

    // encode the values.
    //
    for (iter = vec.begin() ; iter != vec.end() ; iter++)
    {
        // encode the pen history.
        //
        XdrEncodePenHistory (outXdr, *iter);
    }
}


