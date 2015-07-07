/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupplySlot.h
 *  @author Xavier Santotomas
 *  @date  Mon Nov 19 11:57:06 CET 2007
 *  @brief  Views Ink Supply Slot  Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __ViewsInkSupplySlot_h_
#define __ViewsInkSupplySlot_h_

#include "ViewsInkSupplyStationCollection/IViewsInkSupplySlot.h"
#include "Logging.h"
#include "Cds/ICds.h"


/** This class describes the Views Ink Supply Slot.
 *    It should be used to retrieve the associated metrics x type of Ink Supplies that could be attached to a slot.
 */
class ViewsInkSupplySlot : public IViewsInkSupplySlot
{
public:

    /** public constructor.
     *   @param cdsInterface is the CDS interface
     *   @param myViewsInkSupply is the pointer to the corresponding IViewsInkSupply
     *   @param componentLogging is the log created by the root component
     */
    ViewsInkSupplySlot(ICds * cdsInterface, IViewsInkSupply *myViewsInkSupply, Logging *componentLogging);

    /** public destructor.
     */
    virtual ~ViewsInkSupplySlot();

    /** @name IViewsInkSupplySlot public methods.
        @{
    */
	
    /** Method returning a pointer to the corresponding Ink Supply installed in this slot
     *   @return the pointer to the specific Ink Supply
     */
    IViewsInkSupply * getInkSupply();
	
    /** Method refilling a vector with Metrics x Type
     *   @param metricsVector (output param) is a reference to a vector with Metrics x Type for the given slot.
     *   @return the number of metrics collected (that is, the types supported in this slot).

     *   @note the metricsVector will be cleared prior filling it.
     */
    uint32_t getMetricsPerType(std::vector<IViewsInkSupplySlot::MetricsPerType> & metricsVector);

    /** @}
     */

private:


    /** The pointer to the corresponding ViewsInkSuppy currently installed
     */
    IViewsInkSupply *viewsInkSupply_;

    /**
     * To write logs in the system
     */
    Logging* log_;
    
    /**
     * this vector keeps the records initialized with the static information
     */
    std::vector<IViewsInkSupplySlot::MetricsPerType> typesCollection_;
    
    /** Cds internal class object array for IDS-ISS-SLOT-1..n-TYPE-1..m-TOTAL-CTG-USED
     */
    Cds::CdsObject **cdsTotalInkSuppliesUsedObject_;

    /** Cds internal class object array for IDS-ISS-SLOT-1..n-TYPE-1..m-CONSUM
     */
    Cds::CdsObject **cdsConsumptionObject_;
    
    /** Cds internal class object array for IDS-ISS-SLOT-1..n-TYPE-1..m-NON-HP-INK
     */
    Cds::CdsObject **cdsNonHPInkUsedObject_;
    
};

#endif
