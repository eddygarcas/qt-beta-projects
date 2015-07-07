/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsPen.cpp
 *  @author Josep Giralt
 *  @date   Tue Jun  3 19:28:38 CEST 2008
 *  @brief  ViewsPen Proxy Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2008.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include <string.h>
#include <time.h>
#include "ViewsPen.h"
#include "IRpcIdentifiers.h"
#include "SystemManager/SystemManager.h"

/** public constructor.
 *  @param rpc Pointer to the RPC interface to be used to interface with the remote pen.
 *  @param thePen Pointer to the remote pen interface.
 */
ViewsPen::ViewsPen(IRpc * rpc, IViewsPen * thePen)
{
    rpc_    = rpc;
    thePen_ = thePen;
}

/** public destructor.
 */
ViewsPen::~ViewsPen()
{
}

/** Method returning the status of the Views Pen as String Key (to be used later to get the real localized string)
 *  @return the string key corresponding to the status of the views Pen
 */
StringKey ViewsPen::getStatusAsStringKey() 
{
    // make the call
    //
    return rpcGetString (RPC_IVIEWSCARRIAGE_GETSTATUSASSTRINGKEY);
}

/** Method returning the warranty status of the Pen as String Key
 *   @return the String Key corresponding to the warranty status of the Pen
 */
StringKey ViewsPen::getWarrantyStatusAsStringKey()
{
    // make the call
    //
    return rpcGetString (RPC_IVIEWSCARRIAGE_GETWARRANTYSTATUSASSTRINGKEY);
}

/** Method returning the warranty status of the Views Pen
 *   @return the warranty status of the Views Ink Consumable as defined in IInkConsumable::WarrantyStatus
 */
uint32_t ViewsPen::getWarrantyStatus()
{
    // make the call
    //
    return rpcGetUint32 (RPC_IVIEWSCARRIAGE_GETWARRANTYSTATUS);
}

/** Method to be called by the observable object.
 *  @param object that forced the execution of this method.
 *  @param reason for the callback, a new value in the user reported status of the engine Pen
 *  @return integer flag indicating if method has finished OK
 */
uint32_t ViewsPen::callback(ICallbacker &object, uint32_t reason) 
{
    return RESULT_OK;
}


/** Method returning the slot corresponding to this views Pen
 *  @return slot number (0..n-1)
 */
uint32_t ViewsPen::getSlotPosition()
{
    // make the call
    //
    return rpcGetUint32 (RPC_IVIEWSCARRIAGE_GETSLOTPOSITION);
}

/** Method to get the feeding cartridges of a views pen
 *   @return a vector with the indexes (0..n-1) of the cartridges binded to this pen
 */
std::vector<uint16_t> ViewsPen::getFeedingCartridges()
{
    tXdr *                inXdr;
    tXdr *                outXdr;
    Result                res;
    uint32_t              interface;
    std::vector<uint16_t> vec;
    uint32_t              n, i;
    uint16_t              v;

    // Create the encoding / decoding XDR's
    //
    res = rpc_->rpcXdrCreate (&inXdr, &outXdr);
    assert_removable (res == RESULT_OK);

    // Request the call
    //
    res = rpc_->rpcCallRequest (RPC_IVIEWSCARRIAGE_GETFEEDINGCARTRIDGES, inXdr);
    assert_removable (res == RESULT_OK);

    // Encode the remote IViewsPen interface
    //
    interface = (uint32_t)thePen_;
    XdrUInt32 (inXdr, &interface);

    // Wait for the reply
    //
    res = rpc_->rpcCallWaitReply (RPC_IVIEWSCARRIAGE_GETFEEDINGCARTRIDGES, outXdr);
    assert_removable (res == RESULT_OK);

    // decode the output parameters.
    //
    XdrUInt32 (outXdr, &n);
    for (i = 0 ; i < n ; i++)
    {
        XdrUInt16 (outXdr, &v);
        vec.push_back (v);
    }

    // Destroy previously allocated XDR's
    //
    res = rpc_->rpcXdrDestroy (inXdr, outXdr);
    assert_removable (res == RESULT_OK);

    return vec;
}


/** Method to get the jams of a views pen
 *   @return the jams of a views pen
 */
uint32_t ViewsPen::getJams()
{
    // make the call
    //
    return rpcGetUint32 (RPC_IVIEWSCARRIAGE_GETJAMS);
}

/** Method to get the total life consumption of a views pen
 *   @return the total life consumption of a views pen ((number of cubics centimeters))
 */
uint32_t ViewsPen::getTotalLifeConsumption()
{
    // make the call
    //
    return rpcGetUint32 (RPC_IVIEWSCARRIAGE_GETTOTALLIFECONSUMPTION);
}


/** Method to get the percent of ink fired for this views pen
 *   @return the percent of ink fired
 */
uint32_t ViewsPen::getPercentFired()
{
    // make the call
    //
    return rpcGetUint32 (RPC_IVIEWSCARRIAGE_GETPERCENTFIRED);
}
	
/** Method to get the maximum recovery level for this views pen
 *   @return the maximum recovery level
 */
uint32_t ViewsPen::getMaxRecoveryLevel()
{
    // make the call
    //
    return rpcGetUint32 (RPC_IVIEWSCARRIAGE_GETMAXRECOVERYLEVEL);
}

/** Method to know whether non HP ink has been used for this views pen
 *   @return a boolean flag: true if non hp ink has been used, false otherwise
 */
bool ViewsPen::getNonHPInkUsed()
{
    // make the call
    //
    return rpcGetBool (RPC_IVIEWSCARRIAGE_GETNONHPINKUSED);
}

/** Method to know whether expired ink has been used for this views pen
 *   @return a boolean flag: true if expired ink has been used, false otherwise
 */
bool ViewsPen::getExpiredInkUsed()
{
    // make the call
    //
    return rpcGetBool (RPC_IVIEWSCARRIAGE_GETEXPIREDINKUSED);
}


/** Method to be called to register a new Observer.
 *  @param observer object to be registered. Later will be notified.
 */
void ViewsPen::registerObserver(IObserver &observer)
{
    assert_non_removable (0);
}


/** Method to be called to unregister an existant Observer.
 *  @param observer object to be unregistered. No more notifications will be received.
 */
void ViewsPen::unregisterObserver(IObserver &observer)
{
    assert_non_removable (0);
}


/** Method returning the CDS color(s) associated to this consumable
 *  @return a vector filled with the color(s) identifier(s) as defined in IInkConsumable::CDSColor
 */
std::vector<CDSColorId> ViewsPen::getColors()
{
    tXdr *                  inXdr;
    tXdr *                  outXdr;
    Result                  res;
    uint32_t                interface;
    std::vector<CDSColorId> vec;
    uint32_t                n, i;
    CDSColorId              v;

    // Create the encoding / decoding XDR's
    //
    res = rpc_->rpcXdrCreate (&inXdr, &outXdr);
    assert_removable (res == RESULT_OK);

    // Request the call
    //
    res = rpc_->rpcCallRequest (RPC_IVIEWSCARRIAGE_GETFEEDINGCARTRIDGES, inXdr);
    assert_removable (res == RESULT_OK);

    // Encode the remote IViewsPen interface
    //
    interface = (uint32_t)thePen_;
    XdrUInt32 (inXdr, &interface);

    // Wait for the reply
    //
    res = rpc_->rpcCallWaitReply (RPC_IVIEWSCARRIAGE_GETFEEDINGCARTRIDGES, outXdr);
    assert_removable (res == RESULT_OK);

    // decode the output parameters.
    //
    XdrUInt32 (outXdr, &n);
    for (i = 0 ; i < n ; i++)
    {
        XdrSInt16 (outXdr, &v);
        vec.push_back (v);
    }

    // Destroy previously allocated XDR's
    //
    res = rpc_->rpcXdrDestroy (inXdr, outXdr);
    assert_removable (res == RESULT_OK);

    return vec;
}

/** Method returning the manufacturer type of the Views Consumable
 *   @return the manufacturer type as defined in IConsumable::ManufacturerType
 */
uint32_t ViewsPen::getManufacturer()
{
    // make the call
    //
    return rpcGetUint32 (RPC_IVIEWSCARRIAGE_GETMANUFACTURER);
}

/** Method returning the Manufacturer date of a Ink Consumable
 *    @return the manufacturer date of the pen (Number of seconds since 1/1/1970)
 */
uint32_t ViewsPen::getManufacturerDate()
{
    // make the call
    //
    return rpcGetUint32 (RPC_IVIEWSCARRIAGE_GETMANUFACTURERDATE);
}

/**
 * Get the printable order number of this consumable 
 * usually the printable order number is the order number plus the "HP" prefix 
 * @return the printable order number 
 */
std::string ViewsPen::getPrintableOrderNumber()
{
    // make the call
    //
    return rpcGetString (RPC_IVIEWSCARRIAGE_GETPRINTABLEORDERNUMBER);
}

/**
 * Get the order number of this consumable
 * @return the order number
 */
std::string ViewsPen::getOrderNumber()
{
    // make the call
    //
    return rpcGetString (RPC_IVIEWSCARRIAGE_GETORDERNUMBER);
}

/**
 * Get the part number of this consumable
 * @return the part number
 */
std::string ViewsPen::getPartNumber()
{
    // make the call
    //
    return rpcGetString (RPC_IVIEWSCARRIAGE_GETPARTNUMBER);
}

/**
 * Get the serial number of this consumable
 * @return the serial number of this pen
 */
std::string ViewsPen::getSerialNumber()
{
    // make the call
    //
    return rpcGetString (RPC_IVIEWSCARRIAGE_GETSERIALNUMBER);
}

/** Method returning the installation date of a Ink Consumable 
 *   @return the installation date of this pen (Number of seconds since 1/1/1970)
 */
uint32_t ViewsPen::getInstallDate()
{
    // make the call
    //
    return rpcGetUint32 (RPC_IVIEWSCARRIAGE_GETINSTALLDATE);
}

/** Method returning the warranty expiration date of a Ink Consumable 
 *   @return the warranty expiration date of this pen (Number of seconds since 1/1/1970)
 */
uint32_t ViewsPen::getWarrantyExpirationDate() 
{
    // make the call
    //
    return rpcGetUint32 (RPC_IVIEWSCARRIAGE_GETWARRANTYEXPIRATIONDATE);
}

/** Returns whether a printhead is missing in a slot and it is required.
 *   There may be no printhead present but it may not be expected to be there now
 *   if you ask for the printhead present, use the boolean negative of this method
 *   
 *  @return true if a printhead is missing in the slot
 */
bool ViewsPen::isMissing()
{
    // make the call
    //
    return rpcGetBool (RPC_IVIEWSCARRIAGE_ISMISSING);
}

/** This method should be called by the observable to notify all the attached observers.
 *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void ViewsPen::notify(uint32_t reason)
{
    assert_non_removable (0);
}


/** make an RPC call and return an uint32_t
    @param id RPC identifier.
    @return the 32 bit value.
*/
uint32_t ViewsPen::rpcGetUint32 (uint32_t id)
{
    tXdr *           inXdr;
    tXdr *           outXdr;
    Result           res;
    uint32_t         interface;
    uint32_t         v;

    // Create the encoding / decoding XDR's
    //
    res = rpc_->rpcXdrCreate (&inXdr, &outXdr);
    assert_removable (res == RESULT_OK);

    // Request the call
    //
    res = rpc_->rpcCallRequest (id, inXdr);
    assert_removable (res == RESULT_OK);

    // Encode the remote IViewsPen interface
    //
    interface = (uint32_t)thePen_;
    XdrUInt32 (inXdr, &interface);

    // Wait for the reply
    //
    res = rpc_->rpcCallWaitReply (id, outXdr);
    assert_removable (res == RESULT_OK);

    // decode the output parameters.
    //
    XdrUInt32 (outXdr, &v);

    // Destroy previously allocated XDR's
    //
    res = rpc_->rpcXdrDestroy (inXdr, outXdr);
    assert_removable (res == RESULT_OK);

    return v;
}

    
/** make an RPC call and return an std::string
    @param id RPC identifier.
    @return the C++ string value.
*/
std::string ViewsPen::rpcGetString (uint32_t id)
{
    tXdr *           inXdr;
    tXdr *           outXdr;
    Result           res;
    uint32_t         interface;
    char *           ptr;
    std::string      v;

    // Create the encoding / decoding XDR's
    //
    res = rpc_->rpcXdrCreate (&inXdr, &outXdr);
    assert_removable (res == RESULT_OK);

    // Request the call
    //
    res = rpc_->rpcCallRequest (id, inXdr);
    assert_removable (res == RESULT_OK);

    // Encode the remote IViewsPen interface
    //
    interface = (uint32_t)thePen_;
    XdrUInt32 (inXdr, &interface);

    // Wait for the reply
    //
    res = rpc_->rpcCallWaitReply (id, outXdr);
    assert_removable (res == RESULT_OK);

    // decode the output parameters.
    //
    ptr = NULL;
    XdrString (outXdr, (unsigned char**) &ptr, 256);
    assert_removable (ptr);
    v = ptr;
    XdrFree ((uint8_t *)ptr);

    // Destroy previously allocated XDR's
    //
    res = rpc_->rpcXdrDestroy (inXdr, outXdr);
    assert_removable (res == RESULT_OK);

    return v;
}

    
/** make an RPC call and return a boolean
    @param id RPC identifier.
    @return the bool value.
*/
bool ViewsPen::rpcGetBool (uint32_t id)
{
    tXdr *           inXdr;
    tXdr *           outXdr;
    Result           res;
    uint32_t         interface;
    uint8_t          b;

    // Create the encoding / decoding XDR's
    //
    res = rpc_->rpcXdrCreate (&inXdr, &outXdr);
    assert_removable (res == RESULT_OK);

    // Request the call
    //
    res = rpc_->rpcCallRequest (id, inXdr);
    assert_removable (res == RESULT_OK);

    // Encode the remote IViewsPen interface
    //
    interface = (uint32_t)thePen_;
    XdrUInt32 (inXdr, &interface);

    // Wait for the reply
    //
    res = rpc_->rpcCallWaitReply (id, outXdr);
    assert_removable (res == RESULT_OK);

    // decode the output parameters.
    //
    XdrBoolean (outXdr, &b);

    // Destroy previously allocated XDR's
    //
    res = rpc_->rpcXdrDestroy (inXdr, outXdr);
    assert_removable (res == RESULT_OK);

    return b ? true : false;
}

    
