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
#include "ViewsInkSupply.h"
#include "Logging.h"


/** This class describes the Views Ink Supply Slot.
*    It should be used to retrieve the associated types of Ink Supplies that could be attached to a slot.
*/
class ViewsInkSupplySlot : public IViewsInkSupplySlot
{
public:

    /** public constructor.
     */
    ViewsInkSupplySlot(ViewsInkSupply *myViewsInkSupply, Logging *componentLogging);

    /** public destructor.
     */
    virtual ~ViewsInkSupplySlot();

    /** @name IViewsInkSupplySlot public methods.
      @{
    */
	
	/** Method returning a pointer to the corresponding Ink Supply installed in this slot
	 *   @return the pointer to the specific Ink Supply
	 */
	ViewsInkSupply* getInkSupply();
	
	/** Method returning a copy of the vector of Views Ink Supply Types
	 *   @return a copy of the vector of Views Ink Supply Types
	 */
	ViewsInkSupplyTypeCollection getViewsInkSupplyTypes();

    /** @}
     */

private:

    /** The list of Types associated to this slot
     */
    ViewsInkSupplyTypeCollection typesCollection_;

    /** The pointer to the corresponding ViewsInkSuppy currently installed
     */
    ViewsInkSupply *viewsInkSupply_;

    /**
     * To write logs in the system
     */
    Logging* log_;
    
};

#endif
