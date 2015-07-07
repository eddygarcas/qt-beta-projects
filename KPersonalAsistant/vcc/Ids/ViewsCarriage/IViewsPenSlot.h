/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsPenSlot.h
 *  @author Xavier Santotomas
 *  @date  Wed Apr 30 16:34:12 CEST 2008
 *  @brief  Views Metrics per Pen Slot Abstract Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2008.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __IViewsPenSlot_h_
#define __IViewsPenSlot_h_

#include "ViewsCarriage/IViewsPen.h"

#ifndef VIEWSPEN_MAX_SERIAL_NUMBER
#define VIEWSPEN_MAX_SERIAL_NUMBER    64                           ///< maximum serial number length.
#endif

/** This class describes the Views Metrics per Pen Slot abstraction interface.
*    Its methods allow access to the historical printhead metrics by slot (not for the inserted printhead)
*/
class IViewsPenSlot
{
public:

    /** defines the pen history record.
     */
    typedef struct
    {
        char        serialNumber[VIEWSPEN_MAX_SERIAL_NUMBER];      ///< serial number.
        uint32_t    status;                                        ///< pen status.
        uint32_t    usage;                                         ///< usage time in seconds.
        uint32_t    inkConsumedPercent;                            ///< percentage of ink consumed.
        uint32_t    maxRecoveryLevel;                              ///< maxium recovery level applied.
        uint32_t    errorCode;                                     ///< last error code.
        uint32_t    timestamp;                                     ///< timestamp of the error.
        uint32_t    insertionDate;                                 ///< when the pen was installed.
        uint32_t    slotNumber;                                    ///< slot position where the pen is.
        char        partNumber[7];                                 ///< product number of the pen
        uint32_t    paperJams;                                     ///< number of paper jams
        bool        nonHpInkUsed;                                  ///< indicates if nonHpInk has been used.
        bool        expiredInkUsed;                                ///< indicates if expired ink has been used.
        uint32_t    colorCalibrationPending;                       ///< indicates what moment of CLC obselence is.
    } PenHistoryRecord;

    /** @name IViewsPenSlot public methods.
        @{
    */
    /** Method returning a pointer to the corresponding Pen installed in this slot
     *   @return the pointer to the specific Pen
     */
    virtual IViewsPen * getPen() = 0;
	
    /** Method returning the slot ordinal position
     *   @return slot number (0..n-1)
     */
    virtual uint32_t getSlotPosition() = 0;

    /** Method returning the total number of Pen insertions on this Slot
     *   @return total number of insertions
     */
    virtual uint32_t getTotalInsertionsCount() = 0;
		
    /** Method returning the total number of Pens used this Slot
     *   @return total number of pens used
     */
    virtual uint32_t getPensUsedCount() = 0;

    /** Method returning a vector with the indexes (0..n-1) of the events inside penEvents binded to this slot
     *   @param penEvents (output param) is a reference to a vector of pen events of the given slot.
     *   @return the number of events collected.
     *   @note the penEvents vector will be cleared prior filling it.
     */
    virtual uint32_t getPenEvents(std::vector<PenHistoryRecord> & penEvents) = 0;

    /** @}
     */

};

#endif
