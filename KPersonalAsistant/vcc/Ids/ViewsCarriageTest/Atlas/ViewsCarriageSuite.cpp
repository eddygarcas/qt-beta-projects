/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsCarriageSuite.cpp
 *  @author Jesus Barahona
 *  @date   Wed Oct 31 17:29:11 CEST 2007
 *  @brief  Views Carriage Suite that contains all the unit test regarding the IViewsCarriage.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "ViewsCarriageSuite.h"
#include "ViewsCarriageTestAtlas.h"
#include "SystemManager/SystemManager.h"
#include "Pen/PenAcumen.h"
#include "ViewsCarriage/IViewsPen.h"
#include "views_util.h"

#include <stdio.h>

void ViewsCarriageSuite::setUp(void)
{
	SystemManager* systemManagerInstance = SystemManager::instance();
	systemManagerInstance->tester(this);
}

void ViewsCarriageSuite::tearDown(void)
{

}

void ViewsCarriageSuite::numberOfPensTest(void)
{	
	int origNumberPens = ViewsCarriageTestAtlas::carriage->getPens().size();
	int viewsNumberPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens().size();
	
	CPPUNIT_ASSERT_EQUAL(origNumberPens, viewsNumberPens);
}

void ViewsCarriageSuite::getPensTest(void)
{	
	int viewsNumberPens = 0; 
	int origNumberPens = ViewsCarriageTestAtlas::carriage->getPens().size();
	
	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsNumberPens++;
	}
	
	CPPUNIT_ASSERT_EQUAL(origNumberPens, viewsNumberPens);
}

void ViewsCarriageSuite::getSlotPositionTest(void)
{
	int viewsSlot = ViewsCarriageTestAtlas::viewsCarriage->getViewsPenSlots().size();
	int engineSlot = ViewsCarriageTestAtlas::carriage->getPens().size();
	
	CPPUNIT_ASSERT_EQUAL(viewsSlot, engineSlot);
}

void ViewsCarriageSuite::getFeedingCartridgesTest(void)
{
	std::vector<uint16_t> tmpViewsCtgCollection;
	std::vector<uint16_t> viewsCtgCollection;
	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		tmpViewsCtgCollection = auxPen->getFeedingCartridges();
		for(uint16_t i = 0; i < tmpViewsCtgCollection.size(); i++)
		{
			viewsCtgCollection.push_back(tmpViewsCtgCollection[i] );
		}
	}
	
	std::vector<uint16_t> engineCtgCollection;
	ISuppliesConfigurator::SlotSet isSlots;
	ISuppliesConfigurator::SlotSet penSlots;
	
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	for (uint32_t i = 0; i < iPenCollection.size(); i++ )
	{
		penSlots.insert(iPenCollection[i]->getSlot() );
	}
	
	ViewsCarriageTestAtlas::suppliesConfigurator->getSuppliesFromPh(penSlots, isSlots);
	for (ISuppliesConfigurator::SlotSet::iterator i = isSlots.begin(); i != isSlots.end(); i++)
	{
		// slots are numbered from (0..n-1)
		engineCtgCollection.push_back(*i);
	}
	
	for(uint16_t i = 0; i < engineCtgCollection.size(); i++)
	{
		CPPUNIT_ASSERT_EQUAL(engineCtgCollection[i], viewsCtgCollection[i]);
	}
}

void ViewsCarriageSuite::getWarrantyStatusTest(void)
{
	uint32_t value;
	uint32_t viewsWarrantyStatus;
	uint32_t engineWarrantyStatus;
	uint32_t j = 0;
	Cds::CdsResult result;
	std::string cdsKey;

	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsWarrantyStatus = auxPen->getWarrantyStatus();
		
	    //IDS-PH-1..n-WARRANTY-STATUS
	    cdsKey = buildCdsKey("IDS-PH-",iPenCollection[j]->getSlot()+1,"-WARRANTY-STATUS");
	    result = ViewsCarriageTestAtlas::cds->find(cdsKey.c_str(), &cdsWarrantyStatusObject);
	    assert_removable(result == Cds::CDS_SUCCESS);
	    
	    result = ViewsCarriageSuite::cdsWarrantyStatusObject->get(value);
	    engineWarrantyStatus = value;
	    assert_removable(result == Cds::CDS_SUCCESS);
	
	    CPPUNIT_ASSERT_EQUAL(viewsWarrantyStatus, engineWarrantyStatus);
	    j++;
	}
}

void ViewsCarriageSuite::getTotalLifeConsumptionTest(void)
{
	int32_t value;
	uint32_t viewsTotalLifeConsumption;
	uint32_t engineTotalLifeConsumption;
	uint32_t j = 0;
	Cds::CdsResult result;
	std::string cdsKey;

	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsTotalLifeConsumption = auxPen->getTotalLifeConsumption();
		
		//IDS-PH-1..n-TOTAL-LIFE-CONSUMPTION
	    cdsKey = buildCdsKey("IDS-PH-",iPenCollection[j]->getSlot()+1,"-TOTAL-LIFE-CONSUMPTION");
	    result = ViewsCarriageTestAtlas::cds->find(cdsKey.c_str(), &cdsTotalLifeConsumptionObject);
	    assert_removable(result == Cds::CDS_SUCCESS);
	    
	    result = ViewsCarriageSuite::cdsTotalLifeConsumptionObject->get(value);
	    engineTotalLifeConsumption = value;
	    assert_removable(result == Cds::CDS_SUCCESS);
	
	    CPPUNIT_ASSERT_EQUAL(viewsTotalLifeConsumption, engineTotalLifeConsumption);
	    j++;
	}
}

void ViewsCarriageSuite::getPercentFiredTest(void)
{
	int32_t value;
	uint32_t viewsPercentFired;
	uint32_t enginePercentFired;
	uint32_t j = 0;
	Cds::CdsResult result;
	std::string cdsKey;

	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsPercentFired = auxPen->getPercentFired();
		
		//IDS-PH-1..n--PERCENT-FIRED
	    cdsKey = buildCdsKey("IDS-PH-",iPenCollection[j]->getSlot()+1,"-PERCENT-FIRED");
	    result = ViewsCarriageTestAtlas::cds->find(cdsKey.c_str(), &cdsPercentFiredObject);
	    assert_removable(result == Cds::CDS_SUCCESS);
	    
	    result = ViewsCarriageSuite::cdsPercentFiredObject->get(value);
	    enginePercentFired = value;
	    assert_removable(result == Cds::CDS_SUCCESS);
	
	    CPPUNIT_ASSERT_EQUAL(viewsPercentFired, enginePercentFired);
	    j++;
	}
}

void ViewsCarriageSuite::getMaxRecoveryLevelTest(void)
{
	int32_t value;
	uint32_t viewsMaxRecoveryLevel;
	uint32_t engineMaxRecoveryLevel;
	uint32_t j = 0;
	Cds::CdsResult result;
	std::string cdsKey;

	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsMaxRecoveryLevel = auxPen->getMaxRecoveryLevel();
		
		//IDS-PH-1..n--MAX-RECOVERY-LEVEL
	    cdsKey = buildCdsKey("IDS-PH-",iPenCollection[j]->getSlot()+1,"-MAX-RECOVERY-LEVEL");
	    result = ViewsCarriageTestAtlas::cds->find(cdsKey.c_str(), &cdsMaxRecoveryLevelObject);
	    assert_removable(result == Cds::CDS_SUCCESS);
	    
	    result = ViewsCarriageSuite::cdsMaxRecoveryLevelObject->get(value);
	    engineMaxRecoveryLevel = value;
	    assert_removable(result == Cds::CDS_SUCCESS);
	
	    CPPUNIT_ASSERT_EQUAL(viewsMaxRecoveryLevel, engineMaxRecoveryLevel);
	    j++;
	}
}

void ViewsCarriageSuite::getNonHPInkUsedTest(void)
{
	bool value;
	bool viewsNonHPInkUsed;
	bool engineNonHPInkUsed;
	uint32_t j = 0;
	Cds::CdsResult result;
	std::string cdsKey;

	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsNonHPInkUsed = auxPen->getNonHPInkUsed();
		
		//IDS-PH-1..n--NON-HP-INK
	    cdsKey = buildCdsKey("IDS-PH-",iPenCollection[j]->getSlot()+1,"-NON-HP-INK");
	    result = ViewsCarriageTestAtlas::cds->find(cdsKey.c_str(), &cdsNonHpInkUsedObject);
	    assert_removable(result == Cds::CDS_SUCCESS);
	    
	    result = ViewsCarriageSuite::cdsNonHpInkUsedObject->get(value);
	    engineNonHPInkUsed = value;
	    assert_removable(result == Cds::CDS_SUCCESS);
	
	    CPPUNIT_ASSERT_EQUAL(viewsNonHPInkUsed, engineNonHPInkUsed);
	    j++;
	}
}

void ViewsCarriageSuite::getExpiredInkUsedTest(void)
{
	bool value;
	bool viewsExpiredInkUsed;
	bool engineExpiredInkUsed;
	uint32_t j = 0;
	Cds::CdsResult result;
	std::string cdsKey;

	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsExpiredInkUsed = auxPen->getExpiredInkUsed();
		
		//IDS-PH-1..n--EXPIRED-INK-USED
	    cdsKey = buildCdsKey("IDS-PH-",iPenCollection[j]->getSlot()+1,"-EXPIRED-INK-USED");
	    result = ViewsCarriageTestAtlas::cds->find(cdsKey.c_str(), &cdsExpiredInkUsedObject);
	    assert_removable(result == Cds::CDS_SUCCESS);
	    
	    result = ViewsCarriageSuite::cdsExpiredInkUsedObject->get(value);
	    engineExpiredInkUsed = value;
	    assert_removable(result == Cds::CDS_SUCCESS);
	
	    CPPUNIT_ASSERT_EQUAL(viewsExpiredInkUsed, engineExpiredInkUsed);
	    j++;
	}
}

void ViewsCarriageSuite::getPartNumberTest(void)
{
	std::string viewsPartNumber;
	std::string enginePartNumber;
	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	uint32_t j = 0;
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsPartNumber = auxPen->getPartNumber();
		enginePartNumber = iPenCollection[j]->getPartNumber();
		
		CPPUNIT_ASSERT(viewsPartNumber == enginePartNumber);
		j++;
	}
}

void ViewsCarriageSuite::getOrderNumberTest(void)
{
	std::string viewsOrderNumber;
	std::string engineOrderNumber;
	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	uint32_t j = 0;
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsOrderNumber = auxPen->getOrderNumber();
		engineOrderNumber = iPenCollection[j]->getOrderNumber();
		
		CPPUNIT_ASSERT(viewsOrderNumber == engineOrderNumber);
		j++;
	}
}

void ViewsCarriageSuite::getJamsTest(void)
{
	uint32_t viewsJamsNumber;
	uint32_t engineJamsNumber = 0;
	uint32_t j = 0;
	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsJamsNumber = auxPen->getJams();
		Result res = iPenCollection[j]->getAcumen()->getNumberOfPaperJams(engineJamsNumber);
		assert_removable(res == RESULT_OK);
		CPPUNIT_ASSERT_EQUAL(viewsJamsNumber, engineJamsNumber);
		j++;
	}
}

void ViewsCarriageSuite::getColorsTest(void)
{
	std::vector<CDSColorId> tmpViewsColorCollection;
	std::vector<CDSColorId> viewsColorCollection;
	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		tmpViewsColorCollection = auxPen->getColors();
		for(uint32_t i = 0; i < tmpViewsColorCollection.size(); i++)
		{
			viewsColorCollection.push_back(tmpViewsColorCollection[i]);
		}
	}
	
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	std::vector<CDSColorId> engineColorCollection;
	uint32_t numColors;
	Color::Id const *colors;
    
	for(uint32_t i = 0; i < iPenCollection.size(); i++)
	{
		iPenCollection[i]->getColors(colors, numColors);
		for (uint32_t i = 0; i < numColors; i++)
		{
			engineColorCollection.push_back(ViewsCarriageTestAtlas::suppliesConfigurator->getCdsColorFromColor(colors[i]));
			CPPUNIT_ASSERT_EQUAL(engineColorCollection[i], viewsColorCollection[i]);
		}
	}
}

void ViewsCarriageSuite::getManufacturerTest(void)
{
	uint32_t viewsOemName;
	uint32_t oemId;
	uint32_t oemName = IConsumable::UNKNOWN;
	uint32_t j = 0;
	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsOemName = auxPen->getManufacturer();
		if (iPenCollection[j]->getAcumen() != NULL) 
		{
			Result res = iPenCollection[j]->getAcumen()->getOEMId(oemId);
			if (res == RESULT_OK)
			{
				if (oemId == 1)
				{
					oemName = IConsumable::HP;
	    		}
	    		else
	    		{
	    			oemName = IConsumable::APPROVED_OEM;
	    		}
			}
		}
		CPPUNIT_ASSERT_EQUAL(oemName, viewsOemName);
		j++;
	}
}

void ViewsCarriageSuite::getManufacturerDateTest(void)
{
	struct tm date;
	uint32_t viewsManufacturerDate;
	uint32_t engineManufacturerDate;
	uint32_t j = 0;
	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsManufacturerDate = auxPen->getManufacturerDate();
		if (iPenCollection[j]->getAcumen() != NULL) 
		{
			Result res = iPenCollection[j]->getAcumen()->getManufacturingDate(date);
			assert_removable(res == RESULT_OK);
			engineManufacturerDate = (uint32_t)mktime(&date);
		}
		else 
			engineManufacturerDate = 0;
		CPPUNIT_ASSERT_EQUAL(engineManufacturerDate, viewsManufacturerDate);
		j++;
	}
}

void ViewsCarriageSuite::getSerialNumberTest(void)
{
	uint32_t j = 0;
	std::string viewsSerialNumber;
	std::string engineSerialNumber;
	SerialNumber sn;
	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsSerialNumber = auxPen->getSerialNumber();
		if (iPenCollection[j]->getAcumen() != NULL) 
		{
			Result res = iPenCollection[j]->getAcumen()->getSerialNumber(sn);
			assert_removable(res == RESULT_OK);
			engineSerialNumber = sn.get();
		} 
		CPPUNIT_ASSERT(engineSerialNumber == viewsSerialNumber);
		j++;
	}
}

void ViewsCarriageSuite::getInstallDateTest(void)
{
	struct tm date;
	uint32_t viewsInstallDate;
	uint32_t engineInstallDate;
	uint32_t j = 0;
	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsInstallDate = auxPen->getInstallDate();
		if (iPenCollection[j]->getAcumen() != NULL) 
		{
			Result res = iPenCollection[j]->getAcumen()->getInsertionDate(date);
			assert_removable(res == RESULT_OK);
			engineInstallDate = (uint32_t)mktime(&date);
		}
		else
			engineInstallDate = 0;
		CPPUNIT_ASSERT_EQUAL(engineInstallDate, viewsInstallDate);
		j++;
	}
}

void ViewsCarriageSuite::getWarrantyExpirationDateTest(void)
{
	struct tm date;
	uint32_t viewsWarrantyExpirationDate;
	uint32_t engineWarrantyExpirationDate;
	uint32_t j = 0;
	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsWarrantyExpirationDate = auxPen->getWarrantyExpirationDate();
		if (iPenCollection[j]->getAcumen() != NULL) 
		{
			Result res = iPenCollection[j]->getAcumen()->getEndOfWarrantyDate(date);
			assert_removable(res == RESULT_OK);
			engineWarrantyExpirationDate = (uint32_t)mktime(&date);
		}
		else
			engineWarrantyExpirationDate = 0;
		CPPUNIT_ASSERT_EQUAL(engineWarrantyExpirationDate, viewsWarrantyExpirationDate);
		j++;
	}
}

void ViewsCarriageSuite::isMissingTest(void)
{
	bool viewsPenMissing;
	bool enginePenMissing;
	ViewsPenCollection viewsPens = ViewsCarriageTestAtlas::viewsCarriage->getViewsPens();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	uint32_t j = 0;
			
	for (ViewsPenIterator i = viewsPens.begin(); i != viewsPens.end(); i++)
	{
		IViewsPen* auxPen = static_cast<IViewsPen*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsPenMissing = auxPen->isMissing();
		enginePenMissing = (iPenCollection[j]->getUserReportedStatus() & IViewsPen::NO_PEN );
		CPPUNIT_ASSERT_EQUAL(enginePenMissing, viewsPenMissing);
		j++;
	}
}

void ViewsCarriageSuite::getTotalInsertionsCountTest(void)
{
	uint32_t viewsInsertionsCount;
	uint32_t engineInsertionsCount;
	uint32_t j = 0;
	ViewsPenSlotCollection viewsSlots = ViewsCarriageTestAtlas::viewsCarriage->getViewsPenSlots();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	
	for (ViewsPenSlotIterator i = viewsSlots.begin(); i != viewsSlots.end(); i++)
	{
		IViewsPenSlot* auxPen = static_cast<IViewsPenSlot*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsInsertionsCount = auxPen->getTotalInsertionsCount();
		engineInsertionsCount = iPenCollection[j]->getPenInsertionCount();
		CPPUNIT_ASSERT_EQUAL(engineInsertionsCount, viewsInsertionsCount);
		j++;
	}
}

void ViewsCarriageSuite::getPensUsedCountTest(void)
{
	uint32_t viewsPensUsedCount;
	uint32_t enginePensUsedCount;
	uint32_t j = 0;
	ViewsPenSlotCollection viewsSlots = ViewsCarriageTestAtlas::viewsCarriage->getViewsPenSlots();
	PenCollection iPenCollection = ViewsCarriageTestAtlas::carriage->getPens();
	
	for (ViewsPenSlotIterator i = viewsSlots.begin(); i != viewsSlots.end(); i++)
	{
		IViewsPenSlot* auxPen = static_cast<IViewsPenSlot*> (*i);
		CPPUNIT_ASSERT(auxPen != NULL);
		viewsPensUsedCount = auxPen->getPensUsedCount();
		enginePensUsedCount = iPenCollection[j]->getNumberOfPensInserted();
		CPPUNIT_ASSERT_EQUAL(enginePensUsedCount, viewsPensUsedCount);
		j++;
	}
}

void ViewsCarriageSuite::operator()(SystemManager::ErrorRecord & error)
{
	CPPUNIT_FAIL( "Test failed caused by an assertion." );
}


