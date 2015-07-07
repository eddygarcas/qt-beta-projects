#include "PaperCadCalibration.h"

/**
 * Creates a CalibrationStatus object. Must specify a calibration type, the status and timestamp
 * are optional.
 * 
 * @param ViewsCalibrationKind _calibrationType
 * @param ViewsCalibrationStatus _status
 * @param ulong_t  _timeStamp
 */
PaperCadCalibration::PaperCadCalibration(ViewsCalibrationStatus _stat,ulong_t _timeS,Logging* log):
  CommonCalibration(CommonCalibration::VIEWS_BVC_CAD_CONFIGURATION,_stat,_timeS,log)
{
  
  
}

/**Destructor*/
PaperCadCalibration::~PaperCadCalibration()
{
  
  
}
  
