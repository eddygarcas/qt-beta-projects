/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsPenSlot.h
 *  @author Xavier Santotomas
 *  @date  Tue Jan  8 14:32:56 CET 2008
 *  @brief  Views Pen Slot
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __ViewsPenSlot_h_
#define __ViewsPenSlot_h_

#include "ViewsCarriage/IViewsPenSlot.h"
#include "Logging.h"
#include "ViewsPen.h"

/** This class describes the Views Pen Slot.
*    It should be used to retrieve the associated Pen slot metrics (those metrics not associated to the current Pen inserted).
*/
class ViewsPenSlot: public IViewsPenSlot
{
public:

    /** public constructor.
     *   @param myViewsPen is the pointer to the ViewsPen installed in this slot
     *   @param enginePen is the pointer to the engine IPen 
     *   @param componentLog is the log created by the root component
     */
    ViewsPenSlot(ViewsPen *myViewsPen, IPen * enginePen, Logging *componentLog);

    /** public destructor.
     */
    virtual ~ViewsPenSlot();


    /** @name IViewsPenSlot public methods.
        @{
    */
    
    /** Method returning a pointer to the corresponding Pen installed in this slot
     *   @return the pointer to the specific Pen
     */
    IViewsPen* getPen();
	
    /** Method returning the slot ordinal position
     *   @return slot number (0..n-1)
     */
    uint32_t getSlotPosition();

    /** Method returning the total number of Pen insertions on this Slot
     *    @return total number of insertions
     */
    uint32_t getTotalInsertionsCount();
	
    /** Method returning the total number of Pens used this Slot
     *   @return total number of pens used
     */
    uint32_t getPensUsedCount();
	
    /** Method returning a vector with the indexes (0..n-1) of the events inside penEvents binded to this slot
     *   @param penEvents (output param) is a reference to a vector of pen events of the given slot.
     *   @return the number of events collected.
     *   @note the penEvents vector will be cleared prior filling it.
     */
    uint32_t getPenEvents(std::vector<IViewsPenSlot::PenHistoryRecord> & penEvents);
    
    /** @}
     */

private:

    /** The pointer to the corresponding ViewsPen currently installed
     */
    ViewsPen *viewsPen_;

    /** The pointer to the corresponding Engine Pen 
     */
    IPen *enginePen_;

    /**
     * To write logs in the system
     */
    Logging* log_;

};

#endif
