/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   MediaAdvanceCalibration.h
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  PaperAdvanceCalibration class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#ifndef MEDIAADVANCECALIBRATION_H_
#define MEDIAADVANCECALIBRATION_H_


#include "atlas_types.h"
#include "CommonCalibration.h"

/**
 * This class inherit from CommonCalibrations and provides specific functionality for paper advance calibration. 
 * This functionality was implemented in doCalibration(...) method.
 */

class MediaAdvanceCalibration : public CommonCalibration
{

public:

  /**
   * Creates a CalibrationStatus object. Must specify a calibration type, the status and timestamp
   * are optional.
   * 
   * @param _status
   * @param _timeStamp
   */
  MediaAdvanceCalibration(ViewsCalibrationStatus _status = CommonCalibration::VIEWS_UNDEFINED,ulong_t _timeStamp = 0,Logging* _log = 0);
  
  /**Destructor*/
  virtual ~MediaAdvanceCalibration();

protected:

private:

};

#endif /*MEDIAADVANCECALIBRATION_H_*/
