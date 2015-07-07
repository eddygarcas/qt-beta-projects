/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsInkSupplyStationCollectionSuite.h
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

#ifndef __ViewsInkSupplyStationCollectionSuite_h_
#define __ViewsInkSupplyStationCollectionSuite_h_

#include <cppunit/TestFixture.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include "SystemManager/SystemManager.h"
#include "Cds/ICds.h"


class ViewsInkSupplyStationCollectionSuite : public CppUnit:: TestFixture,
						   public ISystemManagerReport
{
	CPPUNIT_TEST_SUITE( ViewsInkSupplyStationCollectionSuite );
	CPPUNIT_TEST( getAbsolutInkLevelTest );
	CPPUNIT_TEST( getPercentualInkLevelTest );
	CPPUNIT_TEST( getExpirationDateTest );
	CPPUNIT_TEST( getWarrantyStatusTest );
	CPPUNIT_TEST( getManufacturerDateTest );
	CPPUNIT_TEST( getInstallDateTest );
	CPPUNIT_TEST( getWarrantyExpirationDateTest );
	CPPUNIT_TEST( getSerialNumberTest );
	CPPUNIT_TEST( getManufacturerTest );
	CPPUNIT_TEST( getSlotPositionTest );
	CPPUNIT_TEST( getLabeledSizeTest );
	CPPUNIT_TEST( getOrderNumberTest );
	CPPUNIT_TEST( getPartNumberTest );
	CPPUNIT_TEST( getColorsTest );
	CPPUNIT_TEST( isUnknownTest );
	CPPUNIT_TEST( isMissingTest );
	
	CPPUNIT_TEST( getMetricsPerTypeTest );
	CPPUNIT_TEST_SUITE_END();
	
	public:
		void setUp(void);
		void tearDown(void);
		void getAbsolutInkLevelTest(void);
		void getPercentualInkLevelTest(void);
		void getExpirationDateTest(void);
		void getWarrantyStatusTest(void);
		void getManufacturerDateTest(void);
		void getInstallDateTest(void);
		void getWarrantyExpirationDateTest(void);
		void getSerialNumberTest(void);
		void getManufacturerTest(void);
		void getSlotPositionTest(void);
		void getLabeledSizeTest(void);
		void getOrderNumberTest(void);
		void getPartNumberTest(void);
		void getColorsTest(void);
		void isUnknownTest(void);
		void isMissingTest(void);
		
		void getMetricsPerTypeTest(void);
		
		/** Cds internal class object for IDS-CTG-1..n-WARRANTY-STATUS
	     */
	    Cds::CdsObject *cdsWarrantyStatusObject;

	    /** Cds internal class object for IDS-CTG-1..n-MANUFACTURER-DATE
	     */
	    Cds::CdsObject *cdsManufacturerDateObject;
	    
	    /** Cds internal class object for IDS-CTG-1..n-INSTALL-DATE
	     */
	    Cds::CdsObject *cdsInstallDateObject;
	    
	    /** Cds internal class object for IDS-CTG-1..n-MANUFACTURER-TYPE
	     */
	    Cds::CdsObject *cdsManufacturerTypeObject;
	    
	    /** Cds internal class object for IDS-CTG-1..n-LABELED-SIZE
	     */
	    Cds::CdsObject *cdsLabeledSizeObject;
	    
	    /** Cds internal class object for IDS-ISS-SLOT-1..n-COLOR
	     */
	    Cds::CdsObject *cdsSlotColorObject;
		
		virtual void operator()(SystemManager::ErrorRecord & error);
};

#endif

