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
#include "views_util.h"
#include "SystemManager/SystemManager.h"

/** public constructor.
 *   @param cdsInterface is the CDS interface
 *   @param myViewsInkSupply is the pointer to the corresponding IViewsInkSupply
 *   @param componentLogging is the log created by the root component
 */
ViewsInkSupplySlot::ViewsInkSupplySlot(ICds * cdsInterface, IViewsInkSupply *myViewsInkSupply, Logging *componentLogging) 
{

    //variables to keep the cds object pointers used in this constructor
    Cds::CdsObject *cdsTypeTotalNumberObject;
    Cds::CdsObject *cdsSlotColorObject;
    Cds::CdsObject *cdsTypePartNumberObject;
    Cds::CdsObject *cdsTypeOrderNumberObject;
    Cds::CdsObject *cdsLabeledSizeObject;
    	
    log_ = componentLogging;
    viewsInkSupply_ = myViewsInkSupply;
	
    int16_t typesTotalNumber;// local variable to be initialized by the CDS
    uint32_t i = viewsInkSupply_->getSlotPosition()+1; // i is the index (1..slotsNumber) of the current slot
    int16_t slotColor;// color for this slot
  			
    //We initialize keys for CDS objects
    Cds::CdsResult result;
    std::string cdsKey;
	
    //IDS-ISS-SLOT-i-TYPE-TOTAL-NUMBER (where i is the current slot)
    cdsKey = buildCdsKey("IDS-ISS-SLOT-",i ,"-TYPE-TOTAL-NUMBER");	
    result = cdsInterface->find(cdsKey.c_str(), &cdsTypeTotalNumberObject);
    assert_removable(result == Cds::CDS_SUCCESS);
    result = cdsTypeTotalNumberObject->get(typesTotalNumber);  	
    assert_removable(result == Cds::CDS_SUCCESS);

    //IDS-ISS-SLOT-i-COLOR (where i is the current slot)
    cdsKey = buildCdsKey("IDS-ISS-SLOT-",i ,"-COLOR");	
    result = cdsInterface->find(cdsKey.c_str(), &cdsSlotColorObject);	
    assert_removable(result == Cds::CDS_SUCCESS);  	
    result = cdsSlotColorObject->get(slotColor);  	
    assert_removable(result == Cds::CDS_SUCCESS);

	
    // now, for this slot, we are going to create so many different types as supported by this slot 
    // we are going to introduce just the static information (color, part number, order number ...)
    // the dynamic information (ink supplies used, consumption, non hp ink used...) should be retrieved when accessed
    std::string typePartNumber;
    std::string typeOrderNumber;
    int32_t labeledSize;	
    cdsTotalInkSuppliesUsedObject_ = new Cds::CdsObject* [typesTotalNumber];
    cdsConsumptionObject_ = new Cds::CdsObject* [typesTotalNumber];
    cdsNonHPInkUsedObject_ = new Cds::CdsObject* [typesTotalNumber];
	
    for (int16_t j=1; j<=typesTotalNumber; j++) 
    {
        IViewsInkSupplySlot::MetricsPerType newMetricsPerType;
		
        //IDS-ISS-SLOT-i-TYPE-j-PART-NUMBER (where i is the current slot and j is the current type)
        cdsKey = buildCdsKey("IDS-ISS-SLOT-",i ,"-TYPE-",j,"-PART-NUMBER");
        result = cdsInterface->find(cdsKey.c_str(), &cdsTypePartNumberObject);
        assert_removable(result == Cds::CDS_SUCCESS);
        result = cdsTypePartNumberObject->get(typePartNumber);
        assert_removable(result == Cds::CDS_SUCCESS);
		
        log_->log(0,"ViewsInkSupplySlot: IDS-ISS-SLOT-%d-TYPE-%d-PART-NUMBER=%s\n", i, j, typePartNumber.data());

        //IDS-ISS-SLOT-i-TYPE-j-ORDER-NUMBER (where i is the current slot and j is the current type)
        cdsKey = buildCdsKey("IDS-ISS-SLOT-",i ,"-TYPE-",j,"-ORDER-NUMBER");
        result = cdsInterface->find(cdsKey.c_str(), &cdsTypeOrderNumberObject);
        assert_removable(result == Cds::CDS_SUCCESS);
        result = cdsTypeOrderNumberObject->get(typeOrderNumber);
        assert_removable(result == Cds::CDS_SUCCESS);

        log_->log(0,"ViewsInkSupplySlot: IDS-ISS-SLOT-%d-TYPE-%d-ORDER-NUMBER=%s\n", i, j, typeOrderNumber.data());
		
        //IDS-ISS-SLOT-i-TYPE-j-LABELED-SIZE (where i is the current slot and j is the current type)
        cdsKey = buildCdsKey("IDS-ISS-SLOT-",i ,"-TYPE-",j,"-LABELED-SIZE");
        result = cdsInterface->find(cdsKey.c_str(), &cdsLabeledSizeObject);
        assert_removable(result == Cds::CDS_SUCCESS);
        result = cdsLabeledSizeObject->get(labeledSize);
        assert_removable(result == Cds::CDS_SUCCESS);

        log_->log(0,"ViewsInkSupplySlot: IDS-ISS-SLOT-%d-TYPE-%d-LABELED-SIZE=%d\n", i, j, labeledSize);


        newMetricsPerType.color = slotColor;
        newMetricsPerType.labeledSize = labeledSize;
        strcpy (newMetricsPerType.partNumber, typePartNumber.data());
        strcpy (newMetricsPerType.orderNumber, typeOrderNumber.data());
		
        typesCollection_.push_back(newMetricsPerType);	

        //IDS-ISS-SLOT-i-TYPE-j-TOTAL-CTG-USED (where i is the current slot and j is the current type)
        cdsKey = buildCdsKey("IDS-ISS-SLOT-",i ,"-TYPE-",j,"-TOTAL-CTG-USED");
        result = cdsInterface->find(cdsKey.c_str(), &cdsTotalInkSuppliesUsedObject_[j-1]);
        assert_removable(result == Cds::CDS_SUCCESS);

        //IDS-ISS-SLOT-i-TYPE-j-CONSUM (where i is the current slot and j is the current type)
        cdsKey = buildCdsKey("IDS-ISS-SLOT-",i ,"-TYPE-",j,"-CONSUM");
        result = cdsInterface->find(cdsKey.c_str(), &cdsConsumptionObject_[j-1]);
        assert_removable(result == Cds::CDS_SUCCESS);

        //IDS-ISS-SLOT-i-TYPE-j-NON-HP-INK (where i is the current slot and j is the current type)
        cdsKey = buildCdsKey("IDS-ISS-SLOT-",i ,"-TYPE-",j,"-NON-HP-INK");
        result = cdsInterface->find(cdsKey.c_str(), &cdsNonHPInkUsedObject_[j-1]);
        assert_removable(result == Cds::CDS_SUCCESS);

    }		 
}
	

/** public destructor.
 */
ViewsInkSupplySlot::~ViewsInkSupplySlot()
{	
    delete [] cdsTotalInkSuppliesUsedObject_;
    delete [] cdsConsumptionObject_;
    delete [] cdsNonHPInkUsedObject_;
}

/** Method returning a pointer to the corresponding Ink Supply installed in this slot
 *   @return the pointer to the specific Ink Supply
 */
IViewsInkSupply* ViewsInkSupplySlot::getInkSupply()
{
    return viewsInkSupply_;
}


/** Method refilling a vector with Metrics x Type
 *   @param metricsVector (output param) is a reference to a vector with Metrics x Type for the given slot.
 *   @return the number of metrics collected (that is, the types supported in this slot).

 *   @note the metricsVector will be cleared prior filling it.
 */
uint32_t ViewsInkSupplySlot::getMetricsPerType(std::vector<IViewsInkSupplySlot::MetricsPerType> & metricsVector)
{

    Cds::CdsResult result;
    uint32_t totalCtgUsed;
    double consume;
    bool nonHPInk;
  	
    // we clear the vector before we use it.
    metricsVector.clear();		
	
    for (int i=0; i<typesCollection_.size(); i++) 
    {
        //we fill just the dynamic data (data that could be changed after created)		
  		
        result = cdsTotalInkSuppliesUsedObject_[i]->get(totalCtgUsed);
        assert_removable(result == Cds::CDS_SUCCESS);
        typesCollection_[i].totalInkSuppliesUsed = totalCtgUsed;
		
        result = cdsConsumptionObject_[i]->get(consume);
        assert_removable(result == Cds::CDS_SUCCESS);
        typesCollection_[i].consumption = consume;

        result = cdsNonHPInkUsedObject_[i]->get(nonHPInk);
        assert_removable(result == Cds::CDS_SUCCESS);
        typesCollection_[i].nonHPInkUsed = nonHPInk;
		
        metricsVector.push_back(typesCollection_[i]);
    }
	
    return metricsVector.size();
}

	


