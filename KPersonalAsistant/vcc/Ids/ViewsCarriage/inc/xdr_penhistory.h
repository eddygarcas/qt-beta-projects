/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   xdr_penhistory.h
 *  @author Josep Giralt
 *  @date   Jun 29 2007
 *  @brief  XDR endode/decode pen history.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __xdr_penhistory_h_
#define __xdr_penhistory_h_

#include <string.h>
#include "Xdr/Xdr.h"

/** This method will decode the pen history in an XDR stream.
*/
static inline void XdrDecodePenHistory (tXdr * xdr, IViewsPenSlot::PenHistoryRecord & v)
{
    uint8_t b;
    char *  ptr;

    ptr = &v.serialNumber[0];
    XdrString (xdr, (unsigned char**) &ptr, sizeof(v.serialNumber));

    XdrUInt32 (xdr, &v.status);
    XdrUInt32 (xdr, &v.usage);
    XdrUInt32 (xdr, &v.inkConsumedPercent);
    XdrUInt32 (xdr, &v.maxRecoveryLevel);
    XdrUInt32 (xdr, &v.errorCode);
    XdrUInt32 (xdr, &v.timestamp);
    XdrUInt32 (xdr, &v.insertionDate);
    XdrUInt32 (xdr, &v.slotNumber);

    ptr = &v.partNumber[0];
    XdrString (xdr, (unsigned char**) &ptr, sizeof(v.partNumber));

    XdrUInt32 (xdr, &v.paperJams);

    XdrBoolean (xdr, &b);
    v.nonHpInkUsed = b ? true : false;

    XdrBoolean (xdr, &b);
    v.expiredInkUsed = b ? true : false;

    XdrUInt32 (xdr, &v.colorCalibrationPending);
}

/** This method will encode the pen history in an XDR stream.
*/
static inline void XdrEncodePenHistory (tXdr * xdr, IViewsPenSlot::PenHistoryRecord & v)
{
    uint8_t b;
    char *  ptr;

    ptr = &v.serialNumber[0];
    XdrString (xdr, (unsigned char**) &ptr, strlen(v.serialNumber)+1);

    XdrUInt32 (xdr, &v.status);
    XdrUInt32 (xdr, &v.usage);
    XdrUInt32 (xdr, &v.inkConsumedPercent);
    XdrUInt32 (xdr, &v.maxRecoveryLevel);
    XdrUInt32 (xdr, &v.errorCode);
    XdrUInt32 (xdr, &v.timestamp);
    XdrUInt32 (xdr, &v.insertionDate);
    XdrUInt32 (xdr, &v.slotNumber);

    ptr = &v.partNumber[0];
    XdrString (xdr, (unsigned char**) &ptr, strlen(v.partNumber)+1);

    XdrUInt32 (xdr, &v.paperJams);

    b = v.nonHpInkUsed ? 1 : 0;
    XdrBoolean (xdr, &b);

    b = v.expiredInkUsed ? 1 : 0;
    XdrBoolean (xdr, &b);

    XdrUInt32 (xdr, &v.colorCalibrationPending);
}

#endif
