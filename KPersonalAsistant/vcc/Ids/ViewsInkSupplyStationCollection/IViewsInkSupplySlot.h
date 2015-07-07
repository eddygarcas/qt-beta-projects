/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   IViewsInkSupplySlot.h
 *  @author Xavier Santotomas
 *  @date  Mon Nov 19 11:57:06 CET 2007
 *  @brief  Views Ink Supply Slot Abstract Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 


#ifndef __IViewsInkSupplySlot_h_
#define __IViewsInkSupplySlot_h_

#include "ViewsInkSupplyStationCollection/IViewsInkSupply.h"

#ifndef SLOT_METRICS_PER_TYPE_MAX_PART_NUMBER
#define SLOT_METRICS_PER_TYPE_MAX_PART_NUMBER     64                           ///< maximum part number length.
#endif

#ifndef SLOT_METRICS_PER_TYPE_MAX_ORDER_NUMBER
#define SLOT_METRICS_PER_TYPE_MAX_ORDER_NUMBER    64                           ///< maximum order number length.
#endif

/** This class describes the Views Ink Supply Slot abstraction interface.
 *    It should be used to retrieve the associated types of Ink Supplies that could be attached to a slot.
 */
class IViewsInkSupplySlot
{
public:

    typedef struct 
    {
    	// static part (not to be changed once created)
    	char     partNumber[SLOT_METRICS_PER_TYPE_MAX_PART_NUMBER];
    	char     orderNumber[SLOT_METRICS_PER_TYPE_MAX_ORDER_NUMBER];
    	int16_t  color;
    	int32_t  labeledSize;

    	// dynamic part (it could be changed once created)
    	uint32_t totalInkSuppliesUsed;
    	double   consumption;
    	bool     nonHPInkUsed;
    } MetricsPerType;

    /** @name IViewsInkSupplySlot public methods.
        @{
    */
	
    /** Method returning a pointer to the corresponding Ink Supply installed in this slot
     *   @return the pointer to the specific Ink Supply
     */
    virtual IViewsInkSupply * getInkSupply() = 0;
	
    /** Method refilling a vector with Metrics x Type
     *   @param metricsVector (output param) is a reference to a vector with Metrics x Type for the given slot.
     *   @return the number of metrics collected (that is, the types supported in this slot).

     *   @note the metricsVector will be cleared prior filling it.
     */
    virtual uint32_t getMetricsPerType(std::vector<IViewsInkSupplySlot::MetricsPerType> & metricsVector) = 0;

	
    /** @}
     */

};

#endif
