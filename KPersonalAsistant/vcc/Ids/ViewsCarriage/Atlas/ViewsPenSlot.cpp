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
//#include "engine_interface.h"

/** public constructor.
 *   @param myViewsPen is the pointer to the IViewsPen installed in this slot
 *   @param enginePen is the pointer to the engine IPen 
 *   @param componentLog is the log created by the root component
 */
ViewsPenSlot::ViewsPenSlot(ViewsPen *myViewsPen, IPen * enginePen, Logging *componentLog) 
{
    	log_ = componentLog;
	viewsPen_ = myViewsPen;
	enginePen_ = enginePen;
    	
    	log_->log(0, "ViewsPenSlot: This is the slot for the pen: %d\n", enginePen_->getSlot());
}
	

/** public destructor.
 */
ViewsPenSlot::~ViewsPenSlot()
{
}

/** Method returning a pointer to the corresponding Pen installed in this slot
 *   @return the pointer to the specific Pen
 */
IViewsPen* ViewsPenSlot::getPen()
{
	return viewsPen_;
}

/** Method returning the slot ordinal position
 *   @return slot number (0..n-1)
 */
uint32_t ViewsPenSlot::getSlotPosition()
{
	return viewsPen_->getSlotPosition();
}

/** Method returning the total number of Pen insertions on this Slot
 *   @return total number of insertions
 */
uint32_t ViewsPenSlot::getTotalInsertionsCount()
{
	return enginePen_->getPenInsertionCount();
}

/** Method returning the total number of Pens used this Slot
 *   @return total number of pens used
 */
uint32_t ViewsPenSlot::getPensUsedCount()
{
	return enginePen_->getNumberOfPensInserted();
}
	

/** Method returning a vector with the indexes (0..n-1) of the events inside penEvents binded to this slot
 *   @param penEvents (output param) is a reference to a vector of pen events of the given slot.
 *   @return the number of events collected.
 *   @note the penEvents vector will be cleared prior filling it.
 */
uint32_t ViewsPenSlot::getPenEvents(std::vector<IViewsPenSlot::PenHistoryRecord> & penEvents)
{
    std::vector<PenHistory::Record> v;
    std::vector<PenHistory::Record>::iterator viter;
    uint32_t currentSlotNb = getSlotPosition();     // this is indexed 0..n-1

    // we retrieve history from the Engine Pen.
    //
    PenHistory * history = enginePen_->getHistory();
	
    // we clear the vector before we use it.
    //
    penEvents.clear();		
	
    if (history != 0)
    {
        // history->retrieve returns the history for all the pens.
        //
        history->retrieve (v);
		
        for (viter = v.begin() ; viter != v.end() ; viter++)
        {
            // slotNumber as registed in the PrintheadErrorLogEntry is indexed (1..n)
            //
            if (currentSlotNb == viter->slotNumber-1) 
            {
                // we just introduce the entries corresponding to this slot.
                //
                IViewsPenSlot::PenHistoryRecord	vnew;
                
                // copy the data.
                //
                strcpy (vnew.serialNumber, viter->serialNumber);
                vnew.status             = viter->status;
                vnew.usage              = viter->usage;
                vnew.inkConsumedPercent = viter->inkConsumedPercent;
                vnew.maxRecoveryLevel   = viter->maxRecoveryLevel;
                vnew.errorCode          = viter->errorCode;
                vnew.timestamp          = viter->timestamp;
                vnew.insertionDate      = viter->insertionDate;
                vnew.slotNumber         = viter->slotNumber;
                strcpy (vnew.partNumber, viter->partNumber);
                vnew.paperJams          = viter->paperJams;
                vnew.nonHpInkUsed       = viter->nonHpInkUsed;
                vnew.expiredInkUsed     = viter->expiredInkUsed;
                vnew.colorCalibrationPending = viter->colorCalibrationPending;
                
                penEvents.push_back(vnew);
            }
        }
    }
  	
    return penEvents.size ();	
}

