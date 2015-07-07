/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupplyStationCollectionSuite.cpp
 *  @author Iqbal Shaikh
 *  @date   Fri Jun 13 17:29:11 CEST 2008
 *  @brief  Views Ink Supply Station Collection Suite that contains all the unit test regarding the IViewsInkSupplyStationCollection.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "ViewsInkSupplyStationCollectionSuite.h"
#include "ViewsInkSupplyStationCollectionTestAtlas.h"
#include "SystemManager/SystemManager.h"
#include "ViewsInkSupplyStationCollection/IViewsInkSupply.h"
#include "views_util.h"

#include <stdio.h>
#include <iostream>

void ViewsInkSupplyStationCollectionSuite::setUp(void)
{
	SystemManager* systemManagerInstance = SystemManager::instance();
	systemManagerInstance->tester(this);
}

void ViewsInkSupplyStationCollectionSuite::tearDown(void)
{

}

void ViewsInkSupplyStationCollectionSuite::getAbsolutInkLevelTest(void)
{	
	Volume inkLevelVolume;
	std::vector<int32_t> viewsAbsoluteInkLevel;
	std::vector<int32_t> engineAbsoluteInkLevel;
	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsAbsoluteInkLevel.push_back(auxInkSupply->getAbsolutInkLevel() );
	}
	
	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineAbsoluteInkLevel = tmpInkSupplyCollection[i];
			Result res = tmpEngineAbsoluteInkLevel->getInkLevel(inkLevelVolume);
			if (res == RESULT_OK)
				engineAbsoluteInkLevel.push_back( inkLevelVolume.getCc() );
		    else 
		    	engineAbsoluteInkLevel.push_back(-1);
					
			CPPUNIT_ASSERT_EQUAL(viewsAbsoluteInkLevel[i], engineAbsoluteInkLevel[i]);
		}
    }
}

void ViewsInkSupplyStationCollectionSuite::getPercentualInkLevelTest(void)
{
	Volume inkLevelVolume;
	Volume capacityVolume;
	std::vector<int32_t> viewsPercentualInkLevel;
	std::vector<int32_t> enginePercentualInkLevel;
	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsPercentualInkLevel.push_back(auxInkSupply->getPercentualInkLevel() );
	}
	
	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineAbsoluteInkLevel = tmpInkSupplyCollection[i];
			Result res1 = tmpEngineAbsoluteInkLevel->getInkLevel(inkLevelVolume);
			Result res2 = tmpEngineAbsoluteInkLevel->getInkCapacity(capacityVolume);
		    if (res1 == RESULT_OK && res2 == RESULT_OK)
		    	enginePercentualInkLevel.push_back( (int32_t)(((double)inkLevelVolume.getCc() / (double)capacityVolume.getCc())*10000) );
		    else 
		    	enginePercentualInkLevel.push_back(-1);
					
			CPPUNIT_ASSERT_EQUAL(viewsPercentualInkLevel[i], enginePercentualInkLevel[i]);
		}
    }
}

void ViewsInkSupplyStationCollectionSuite::getExpirationDateTest(void)
{
	struct tm date;
	std::vector<uint32_t> viewsExpirationDate;
	std::vector<uint32_t> engineExpirationDate;
	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsExpirationDate.push_back(auxInkSupply->getExpirationDate() );
	}
	
	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineExpirationDate = tmpInkSupplyCollection[i];
		    
		    Result res = tmpEngineExpirationDate->getExpirationDate(date);
		    if (res == RESULT_OK)
		        engineExpirationDate.push_back( (uint32_t)mktime(&date) );
		    else
		    	engineExpirationDate.push_back(0);

			CPPUNIT_ASSERT_EQUAL(viewsExpirationDate[i], engineExpirationDate[i]);
		}
    }
}

void ViewsInkSupplyStationCollectionSuite::getWarrantyStatusTest(void)
{
	Cds::CdsResult result;
    std::string cdsKey;
    uint32_t value;
	std::vector<uint32_t> viewsWarrantyStatus;
	std::vector<uint32_t> engineWarrantyStatus;

	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsWarrantyStatus.push_back( auxInkSupply->getWarrantyStatus() );
	}

	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineWarrantyStatus = tmpInkSupplyCollection[i];
			cdsKey = buildCdsKey("IDS-CTG-",tmpEngineWarrantyStatus->getSlot()+1,"-WARRANTY-STATUS");
			result = ViewsInkSupplyStationCollectionTestAtlas::cds->find(cdsKey.c_str(), &cdsWarrantyStatusObject);
			assert_removable(result == Cds::CDS_SUCCESS);
		    
		    result = ViewsInkSupplyStationCollectionSuite::cdsWarrantyStatusObject->get(value);
		    assert_removable(result == Cds::CDS_SUCCESS);
			engineWarrantyStatus.push_back(value);

			CPPUNIT_ASSERT_EQUAL(viewsWarrantyStatus[i], engineWarrantyStatus[i]);
		}
	}
}

void ViewsInkSupplyStationCollectionSuite::getManufacturerDateTest(void)
{
	Cds::CdsResult result;
    std::string cdsKey;
    uint32_t value;
	std::vector<uint32_t> viewsManufacturerDate;
	std::vector<uint32_t> engineManufacturerDate;

	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsManufacturerDate.push_back( auxInkSupply->getManufacturerDate() );
	}

	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineManufacturerDate = tmpInkSupplyCollection[i];
			cdsKey = buildCdsKey("IDS-CTG-",tmpEngineManufacturerDate->getSlot()+1,"-MANUFACTURER-DATE");
			result = ViewsInkSupplyStationCollectionTestAtlas::cds->find(cdsKey.c_str(), &cdsManufacturerDateObject);
		    assert_removable(result == Cds::CDS_SUCCESS);
		    
		    result = ViewsInkSupplyStationCollectionSuite::cdsManufacturerDateObject->get(value);
		    assert_removable(result == Cds::CDS_SUCCESS);
		    engineManufacturerDate.push_back(value);

			CPPUNIT_ASSERT_EQUAL(viewsManufacturerDate[i], engineManufacturerDate[i]);
		}
	}
}

void ViewsInkSupplyStationCollectionSuite::getInstallDateTest(void)
{
	Cds::CdsResult result;
    std::string cdsKey;
    uint32_t value;
	std::vector<uint32_t> viewsInstallDate;
	std::vector<uint32_t> engineInstallDate;

	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsInstallDate.push_back( auxInkSupply->getInstallDate() );
	}

	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineInstallDate = tmpInkSupplyCollection[i];
			cdsKey = buildCdsKey("IDS-CTG-",tmpEngineInstallDate->getSlot()+1,"-INSTALL-DATE");
			result = ViewsInkSupplyStationCollectionTestAtlas::cds->find(cdsKey.c_str(), &cdsInstallDateObject);
		    assert_removable(result == Cds::CDS_SUCCESS);
		    
		    result = ViewsInkSupplyStationCollectionSuite::cdsInstallDateObject->get(value);
		    assert_removable(result == Cds::CDS_SUCCESS);
		    engineInstallDate.push_back(value);

			CPPUNIT_ASSERT_EQUAL(viewsInstallDate[i], engineInstallDate[i]);
		}
	}
}

void ViewsInkSupplyStationCollectionSuite::getWarrantyExpirationDateTest(void)
{
	struct tm date;
	std::vector<uint32_t> viewsWarrantyExpirationDate;
	std::vector<uint32_t> engineWarrantyExpirationDate;
	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsWarrantyExpirationDate.push_back(auxInkSupply->getWarrantyExpirationDate() );
	}
	
	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineWarrantyExpirationDate = tmpInkSupplyCollection[i];
		    
		    Result res = tmpEngineWarrantyExpirationDate->getEndWarrantyDate(date);
		    if (res == RESULT_OK)
		        engineWarrantyExpirationDate.push_back( (uint32_t)mktime(&date) );
		    else
		    	engineWarrantyExpirationDate.push_back(0);

			CPPUNIT_ASSERT_EQUAL(viewsWarrantyExpirationDate[i], engineWarrantyExpirationDate[i]);
		}
    }	
}

void ViewsInkSupplyStationCollectionSuite::getSerialNumberTest(void)
{
	IInkSupply::InkSupplySerialNumber serialNumber;
	std::vector<std::string> viewsSerialNumber;
	std::vector<std::string> engineSerialNumber;
	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsSerialNumber.push_back(auxInkSupply->getSerialNumber() );
	}
	
	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineSerialNumber = tmpInkSupplyCollection[i];
		    
		    Result res = tmpEngineSerialNumber->getSerialNumber(serialNumber);
		    if (res == RESULT_OK)
		    	engineSerialNumber.push_back( serialNumber.get() );

			CPPUNIT_ASSERT(viewsSerialNumber[i] == engineSerialNumber[i]);
		}
    }
}

void ViewsInkSupplyStationCollectionSuite::getManufacturerTest()
{
	Cds::CdsResult result;
    std::string cdsKey;
    int32_t value;
	std::vector<uint32_t> viewsManufacturer;
	std::vector<uint32_t> engineManufacturer;

	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsManufacturer.push_back( auxInkSupply->getManufacturer() );
	}

	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineManufacturer = tmpInkSupplyCollection[i];
			cdsKey = buildCdsKey("IDS-CTG-",tmpEngineManufacturer->getSlot()+1,"-MANUFACTURER-TYPE");
			result = ViewsInkSupplyStationCollectionTestAtlas::cds->find(cdsKey.c_str(), &cdsManufacturerTypeObject);
		    assert_removable(result == Cds::CDS_SUCCESS);
		    
		    result = ViewsInkSupplyStationCollectionSuite::cdsManufacturerTypeObject->get(value);
		    assert_removable(result == Cds::CDS_SUCCESS);
		    engineManufacturer.push_back(value);

			CPPUNIT_ASSERT_EQUAL(viewsManufacturer[i], engineManufacturer[i]);
		}
	}	
}

void ViewsInkSupplyStationCollectionSuite::getSlotPositionTest()
{
	std::vector<uint32_t> viewsSlotPosition;
	std::vector<uint32_t> engineSlotPosition;

	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsSlotPosition.push_back( auxInkSupply->getSlotPosition() );
	}

	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineSlotPosition = tmpInkSupplyCollection[i];
			engineSlotPosition.push_back(tmpEngineSlotPosition->getSlot());
			
			CPPUNIT_ASSERT_EQUAL(viewsSlotPosition[i], engineSlotPosition[i]);
		}
    }
}

void ViewsInkSupplyStationCollectionSuite::getLabeledSizeTest(void)
{
	Cds::CdsResult result;
    std::string cdsKey;
    int32_t value;
	std::vector<int32_t> viewsLabeledSize;
	std::vector<int32_t> engineLabeledSize;

	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsLabeledSize.push_back( auxInkSupply->getLabeledSize() );
	}

	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineLabeledSize = tmpInkSupplyCollection[i];
			cdsKey = buildCdsKey("IDS-CTG-",tmpEngineLabeledSize->getSlot()+1,"-LABELED-SIZE");
			result = ViewsInkSupplyStationCollectionTestAtlas::cds->find(cdsKey.c_str(), &cdsLabeledSizeObject);
		    assert_removable(result == Cds::CDS_SUCCESS);
		    
		    result = ViewsInkSupplyStationCollectionSuite::cdsLabeledSizeObject->get(value);
		  	assert_removable(result == Cds::CDS_SUCCESS);
		    engineLabeledSize.push_back(value);

			CPPUNIT_ASSERT_EQUAL(viewsLabeledSize[i], engineLabeledSize[i]);
		}
	}
}

void ViewsInkSupplyStationCollectionSuite::getOrderNumberTest(void)
{
	std::vector<std::string> viewsOrderNumber;
	std::vector<std::string> engineOrderNumber;

	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsOrderNumber.push_back( auxInkSupply->getOrderNumber() );
	}

	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineOrderNumber = tmpInkSupplyCollection[i];
			engineOrderNumber.push_back(tmpEngineOrderNumber->getOrderNumber());
			
			CPPUNIT_ASSERT(viewsOrderNumber[i] == engineOrderNumber[i]);
		}
    }
}

void ViewsInkSupplyStationCollectionSuite::getPartNumberTest(void)
{
	std::vector<std::string> viewsPartNumber;
	std::vector<std::string> enginePartNumber;

	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsPartNumber.push_back( auxInkSupply->getPartNumber() );
	}

	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEnginePartNumber = tmpInkSupplyCollection[i];
			enginePartNumber.push_back(tmpEnginePartNumber->getProductNumber());
			
			CPPUNIT_ASSERT(viewsPartNumber[i] == enginePartNumber[i]);
		}
    }
}

void ViewsInkSupplyStationCollectionSuite::getColorsTest(void)
{
	Cds::CdsResult result;
    std::string cdsKey;
    CDSColorId color;
	std::vector<CDSColorId> viewsColors;
	std::vector<CDSColorId> tmpViewsColorsCollection;
	std::vector<CDSColorId> engineColors;
	
	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		tmpViewsColorsCollection = auxInkSupply->getColors();
		for (uint32_t i = 0; i < tmpViewsColorsCollection.size(); i++)
		{
			viewsColors.push_back(tmpViewsColorsCollection[i]);
		}
	}

	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineColor = tmpInkSupplyCollection[i];
			cdsKey = buildCdsKey("IDS-ISS-SLOT-",tmpEngineColor->getSlot()+1,"-COLOR");
			result = ViewsInkSupplyStationCollectionTestAtlas::cds->find(cdsKey.c_str(), &cdsSlotColorObject);
		    assert_removable(result == Cds::CDS_SUCCESS);
		    
		    result = ViewsInkSupplyStationCollectionSuite::cdsSlotColorObject->get(color);
		  	assert_removable(result == Cds::CDS_SUCCESS);
		  	engineColors.push_back(color);

			CPPUNIT_ASSERT_EQUAL(viewsColors[i], engineColors[i]);
		}
	}
}

void ViewsInkSupplyStationCollectionSuite::isUnknownTest(void)
{
	std::vector<bool> viewsUnknown;
	std::vector<bool> engineUnknown;
	
	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsUnknown.push_back( auxInkSupply->isUnknown() );
	}

	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineUnknown = tmpInkSupplyCollection[i];
			engineUnknown.push_back(tmpEngineUnknown->getUserReportedStatus() & IViewsInkSupply::UNKNOWN);
			
			CPPUNIT_ASSERT_EQUAL(viewsUnknown[i], engineUnknown[i]);
		}
    }
}

void ViewsInkSupplyStationCollectionSuite::isMissingTest(void)
{
	std::vector<bool> viewsMissing;
	std::vector<bool> engineMissing;
	
	ViewsInkSupplyCollection viewsInkSupply = ViewsInkSupplyStationCollectionTestAtlas::viewsInkSupplyStationCollection->getViewsInkSupplies();
	InkSupplyStationCollection issColection = ViewsInkSupplyStationCollectionTestAtlas::fluidManager->getInkSupplyStation();

	for (ViewsInkSupplyIterator i = viewsInkSupply.begin(); i != viewsInkSupply.end(); i++)
	{
		IViewsInkSupply *auxInkSupply = static_cast <IViewsInkSupply*> (*i);
		viewsMissing.push_back( auxInkSupply->isMissing() );
	}

	for (uint32_t i = 0; i < issColection.size(); i++) 
    {
		ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection = issColection[i];
		InkSupplyCollection tmpInkSupplyCollection = ViewsInkSupplyStationCollectionTestAtlas::engineInkSupplyStationCollection->getSupplies();
		for (uint32_t i = 0; i < tmpInkSupplyCollection.size(); i++)
		{
			IInkSupply* tmpEngineMissing = tmpInkSupplyCollection[i];
			engineMissing.push_back(tmpEngineMissing->getUserReportedStatus() & IViewsInkSupply::UNKNOWN);
			
			CPPUNIT_ASSERT_EQUAL(viewsMissing[i], engineMissing[i]);
		}
    }
}

void ViewsInkSupplyStationCollectionSuite::getMetricsPerTypeTest(void)
{
	CPPUNIT_FAIL( "Needs to implement this method properly.");
}

void ViewsInkSupplyStationCollectionSuite::operator()(SystemManager::ErrorRecord & error)
{
	CPPUNIT_FAIL( "Test failed caused by an assertion." );
}


