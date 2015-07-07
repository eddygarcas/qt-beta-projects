/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsCarriageSuite.h
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

#ifndef __ViewsCarriageSuite_h_
#define __ViewsCarriageSuite_h_

#include <cppunit/TestFixture.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/extensions/HelperMacros.h>
#include "SystemManager/SystemManager.h"
#include "Cds/ICds.h"


class ViewsCarriageSuite : public CppUnit:: TestFixture,
						   public ISystemManagerReport
{
	CPPUNIT_TEST_SUITE( ViewsCarriageSuite );
	CPPUNIT_TEST( numberOfPensTest );
	CPPUNIT_TEST( getPensTest );
	CPPUNIT_TEST( getSlotPositionTest);
	CPPUNIT_TEST( getFeedingCartridgesTest );
	CPPUNIT_TEST( getWarrantyStatusTest );
	CPPUNIT_TEST( getTotalLifeConsumptionTest );
	CPPUNIT_TEST( getPercentFiredTest );
	CPPUNIT_TEST( getMaxRecoveryLevelTest );
	CPPUNIT_TEST( getNonHPInkUsedTest );
	CPPUNIT_TEST( getExpiredInkUsedTest );
	CPPUNIT_TEST( getPartNumberTest );
	CPPUNIT_TEST( getOrderNumberTest );
	CPPUNIT_TEST( getJamsTest );
	CPPUNIT_TEST( getColorsTest );
	CPPUNIT_TEST( getManufacturerTest );
	CPPUNIT_TEST( getManufacturerDateTest );
	CPPUNIT_TEST( getSerialNumberTest );
	CPPUNIT_TEST( getInstallDateTest );
	CPPUNIT_TEST( getWarrantyExpirationDateTest );
	CPPUNIT_TEST( isMissingTest );
	CPPUNIT_TEST( getTotalInsertionsCountTest );
	CPPUNIT_TEST( getPensUsedCountTest );
	CPPUNIT_TEST_SUITE_END();
	
	public:
		void setUp(void);
		void tearDown(void);
		void numberOfPensTest(void);
		void getPensTest(void);
		void getSlotPositionTest(void);
		void getFeedingCartridgesTest(void);
		void getWarrantyStatusTest(void);
		void getTotalLifeConsumptionTest(void);
		void getPercentFiredTest(void);
		void getMaxRecoveryLevelTest(void);
		void getNonHPInkUsedTest(void);
		void getExpiredInkUsedTest(void);
		void getPartNumberTest(void);
		void getOrderNumberTest(void);
		void getJamsTest(void);
		void getColorsTest(void);
		void getManufacturerTest(void);
		void getManufacturerDateTest(void);
		void getSerialNumberTest(void);
		void getInstallDateTest(void);
		void getWarrantyExpirationDateTest(void);
		void isMissingTest(void);
		void getTotalInsertionsCountTest(void);
		void getPensUsedCountTest(void);
		
	    /** Cds internal class object for IDS-PH-1..n-WARRANTY-STATUS
	     */
	    Cds::CdsObject *cdsWarrantyStatusObject;

	    /** Cds internal class object for IDS-PH-1..n-TOTAL-LIFE-CONSUMPTION
	     */
	    Cds::CdsObject *cdsTotalLifeConsumptionObject;
	    
	    /** Cds internal class object for IDS-PH-1..n-PERCENT-FIRED
	     */
	    Cds::CdsObject *cdsPercentFiredObject;
	    
	    /** Cds internal class object for IDS-PH-1..n-MAX-RECOVERY-LEVEL
	     */
	    Cds::CdsObject *cdsMaxRecoveryLevelObject;
	    
	    /** Cds internal class object for IDS-PH-1..n-NON-HP-INK
	     */
	    Cds::CdsObject *cdsNonHpInkUsedObject;

	    /** Cds internal class object for IDS-PH-1..n-EXPIRED-INK-USED
	     */
	    Cds::CdsObject *cdsExpiredInkUsedObject;

	    virtual void operator()(SystemManager::ErrorRecord & error);
};

#endif

