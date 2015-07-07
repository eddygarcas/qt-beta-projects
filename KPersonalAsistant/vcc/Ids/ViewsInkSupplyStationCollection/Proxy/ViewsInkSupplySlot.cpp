/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupplySlot.cpp
 *  @author Xavier Santotomas
 *  @date   Wed Dec 19 17:26:24 CET 2007
 *  @brief  Views Ink Supply Slot
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "ViewsInkSupplySlot.h"

/** public constructor.
 */
ViewsInkSupplySlot::ViewsInkSupplySlot(ViewsInkSupply *myViewsInkSupply, Logging *componentLogging) 
{
    	log_ = componentLogging;
    	
    	//this is not working: check why
    	//log_->log(0,"ViewsInkSupplySlot: This is the slot for the ink supply: %p\n", myViewsInkSupply);

	viewsInkSupply_ = myViewsInkSupply;
	
	
	
	//TODO: we create one new type associated to this slot
	//but here we will need to create a new ViewsInkSupplyType for each one of the types of cartridge associated to this slot	
	ViewsInkSupplyType *associated_type = new ViewsInkSupplyType(IInkConsumable::CYAN);
	 
	typesCollection_.push_back(associated_type);	
	
	//we register the just created type for the Ink Supply
	viewsInkSupply_->registerType(associated_type);
}
	

/** public destructor.
 */
ViewsInkSupplySlot::~ViewsInkSupplySlot()
{	
	for (ViewsInkSupplyTypeIterator i = typesCollection_.begin(); i != typesCollection_.end(); i++)
	{
		delete *i;
	}

	//we unregister the type, registering a null
	viewsInkSupply_->registerType(0);
}

/** Method returning a pointer to the corresponding Ink Supply installed in this slot
 *   @return the pointer to the specific Ink Supply
 */
ViewsInkSupply* ViewsInkSupplySlot::getInkSupply()
{
	return viewsInkSupply_;
}


/** Method returning a copy of the vector of Views Ink Supply Types
 *   @return a copy of the vector of Views Ink Supply Types
 */
ViewsInkSupplyTypeCollection ViewsInkSupplySlot::getViewsInkSupplyTypes()
{
 	return typesCollection_;
}

	


