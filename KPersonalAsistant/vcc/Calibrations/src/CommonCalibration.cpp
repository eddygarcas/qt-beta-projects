#include "views_types.h"
#include "CommonCalibration.h"

/**Creates a CalibrationStatus object. Must specify a calibration type, the status and timestamp
 * are optional.
 * 
 * @param std::string _calibrationType
 * @param uint32_t _status
 * @param ulong_t  _timeStamp
 */
CommonCalibration:: CommonCalibration(ViewsCalibrationKind _Type,ViewsCalibrationStatus _stat,ulong_t _timeS,Logging* log):
	calibrationType_(_Type),
	status_(_stat),
	timeStamp_(_timeS)
{
  log_ = log;
}

/**CalibrationStatus destructor*/
CommonCalibration::~CommonCalibration()
{
}

/**Return a calibration status type.
 * 
 * @return std::string
 */
CommonCalibration::ViewsCalibrationKind CommonCalibration::getCalibrationType()
{
	return calibrationType_;
}

/**Return a status of calibration.
 *
 * @return ViewsCalibrationStatus
 */
CommonCalibration::ViewsCalibrationStatus CommonCalibration::getCalibrationStatus()
{
  if (log_!=NULL) log_->log(LOG_INFO,"Calibration status: %d of type: %d\n",status_,calibrationType_);
	return status_;
}

/**
 * Sets calibrations status value.
 * 
 * @param ViewsCalibrationStatus
 */
void CommonCalibration::setCalibrationStatus(CommonCalibration::ViewsCalibrationStatus& _calibrationStatus)
{
  status_ = _calibrationStatus;
}

/**
 * Return a long type with timestamp value
 * 
 * @return ulong_t
 */
ulong_t CommonCalibration::getTimeStamp()
{
  return timeStamp_;
}

/**
 * Returns the string key value of status code.
 * 
 * @return std::string
 */
std::string CommonCalibration::getStatusAsStringKey()
{
  return 0;
}
/**
 * Method for register a IObserver object.
 * 
 * @param observer object to be registered. Later will be notified.
 */
void CommonCalibration::registerObserver(IObserver& observer)
{
  onChangeList_.push_back( &observer );
}

/**
 * Method for unregister a IObserver object.
 *  
 * @param observer object to be unregistered. No more notifications will be received.
 */
void CommonCalibration::unregisterObserver(IObserver& observer)
{
  onChangeList_.remove(&observer);
}

/**
 * This method should be called by the observable to notify all the attached observers.
 * 
 * @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void CommonCalibration::notify(uint32_t reason)
{
  for ( std::list <IObserver*>::iterator it = onChangeList_.begin() ; it != onChangeList_.end() ; it++ )
  {
      (*it)->onChange(*(static_cast<IObservable*>(this)), reason);
  }
}

/**
 * Static method which returns a standard views calibration status value.
 * 
 * @param uint32_t
 * @return ViewsCalibrationStatus
 */
CommonCalibration::ViewsCalibrationStatus CommonCalibration::getCdsCalibrationStatus(uint32_t _calibrationStatus)
{
    IOMES::IMediaCalibrationStatus::MediumCalibrationStatus::Status _status;
    _status = (IOMES::IMediaCalibrationStatus::MediumCalibrationStatus::Status)_calibrationStatus;
  
    return getCdsCalibrationStatus(_status);
}

/**
 * Static method which returns a standard views calibration status value.
 * 
 * @param uint32_t
 * @return ViewsCalibrationStatus
 */
CommonCalibration::ViewsCalibrationStatus CommonCalibration::getCdsCalibrationStatus(IOMES::IMediaCalibrationStatus::MediumCalibrationStatus::Status status)
{
    ViewsCalibrationStatus cdsStatus;
      
    switch(status)
    {
    case IOMES::IMediaCalibrationStatus::MediumCalibrationStatus::UNDEFINED:
        cdsStatus = CommonCalibration::VIEWS_UNDEFINED;
        break;
    case IOMES::IMediaCalibrationStatus::MediumCalibrationStatus::NOT_AVAILABLE:
        cdsStatus = CommonCalibration::VIEWS_NOT_AVAILABLE;
        break;
    case IOMES::IMediaCalibrationStatus::MediumCalibrationStatus::VALID:
        cdsStatus = CommonCalibration::VIEWS_VALID;
        break;
    case IOMES::IMediaCalibrationStatus::MediumCalibrationStatus::TODO:
        cdsStatus = CommonCalibration::VIEWS_TODO;
        break;
    case IOMES::IMediaCalibrationStatus::MediumCalibrationStatus::OBSOLETE:
        cdsStatus = CommonCalibration::VIEWS_OBSOLETE;
        break;
    default:
        cdsStatus = CommonCalibration::VIEWS_UNDEFINED;
        break;
    }
    return cdsStatus;
}

