/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsPenSlot.cpp
 *  @author Xavier Santotomas
 *  @date   Tue Jan  8 14:37:32 CET 2008
 *  @brief  Views Pen Slot
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "ViewsPenSlot.h"
#include "IRpcIdentifiers.h"
#include "xdr_penhistory.h"
#include "SystemManager/SystemManager.h"

/** public constructor.
 *  @param rpc Pointer to the RPC interface to be used to interface with the remote pen.
 *  @param theSlot Pointer to the remote pen slot interface.
 *  @param thePen Pointer to the remote pen interface.
 */
ViewsPenSlot::ViewsPenSlot(IRpc * rpc, IViewsPenSlot * theSlot, IViewsPen * thePen)
{
    rpc_     = rpc;
    theSlot_ = theSlot;
    thePen_  = thePen;
}
	

/** public destructor.
 */
ViewsPenSlot::~ViewsPenSlot()
{
}

/** Method returning a pointer to the corresponding Pen installed in this slot
 *   @return the pointer to the specific Pen.
 */
IViewsPen * ViewsPenSlot::getPen()
{
    return (IViewsPen *)thePen_;
}

/** Method returning the slot ordinal position
 *   @return slot number (0..n-1)
 */
uint32_t ViewsPenSlot::getSlotPosition()
{
    // make the call
    //
    return (RPC_IVIEWSCARRIAGE_GETSLOTPOSITION);
}

/** Method returning the total number of Pen insertions on this Slot
 *   @return total number of insertions
 */
uint32_t ViewsPenSlot::getTotalInsertionsCount()
{
    // make the call
    //
    return (RPC_IVIEWSCARRIAGE_GETTOTALINSERTIONSCOUNT);
}

/** Method returning the total number of Pens used this Slot
 *   @return total number of pens used
 */
uint32_t ViewsPenSlot::getPensUsedCount()
{
    // make the call
    //
    return (RPC_IVIEWSCARRIAGE_GETPENSUSEDCOUNT);
}
	

/** Method returning a vector with the indexes (0..n-1) of the events inside penEvents binded to this slot
 *   @param penEvents (output param) is a reference to a vector of pen events of the given slot.
 *   @return the number of events collected.
 *   @note the penEvents vector will be cleared prior filling it.
 */
uint32_t ViewsPenSlot::getPenEvents(std::vector<IViewsPenSlot::PenHistoryRecord> & penEvents)
{
    tXdr *                  inXdr;
    tXdr *                  outXdr;
    Result                  res;
    uint32_t                interface;
    std::vector<IViewsPenSlot::PenHistoryRecord> vec;
    uint32_t                n, i;
    IViewsPenSlot::PenHistoryRecord v;

    // Create the encoding / decoding XDR's
    //
    res = rpc_->rpcXdrCreate (&inXdr, &outXdr);
    assert_removable (res == RESULT_OK);

    // Request the call
    //
    res = rpc_->rpcCallRequest (RPC_IVIEWSCARRIAGE_GETPENEVENTS, inXdr);
    assert_removable (res == RESULT_OK);

    // Encode the remote IViewsPenSlot interface
    //
    interface = (uint32_t)theSlot_;
    XdrUInt32 (inXdr, &interface);

    // Wait for the reply
    //
    res = rpc_->rpcCallWaitReply (RPC_IVIEWSCARRIAGE_GETPENEVENTS, outXdr);
    assert_removable (res == RESULT_OK);

    // decode the output parameters.
    //
    XdrUInt32 (outXdr, &n);
    for (i = 0 ; i < n ; i++)
    {
        // decode the pen history.
        //
        XdrDecodePenHistory (outXdr, v);
        vec.push_back (v);
    }

    // Destroy previously allocated XDR's
    //
    res = rpc_->rpcXdrDestroy (inXdr, outXdr);
    assert_removable (res == RESULT_OK);

    return vec.size();
}

/** make an RPC call and return an uint32_t
    @param id RPC identifier.
    @return the 32 bit value.
*/
uint32_t ViewsPenSlot::rpcGetUint32 (uint32_t id)
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

    // Encode the remote IViewsPenSlot interface
    //
    interface = (uint32_t)theSlot_;
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
