#include "Paper.h"
#include "CommonCalibration.h"
#include "ColorPaperCalibration.h"
#include "PaperCadCalibration.h"


Paper::Paper()
{
	
}

/*
 * This function can only use in Fake process.
 */
Paper::Paper(std::string* _mediaKey,std::string* _mediaName,uint32_t colorStatus ,uint32_t gaStatus,uint32_t cadStatus):
	mediaKey_(*_mediaKey),
	mediaName_(*_mediaName)
{

}

/**
 * 
 */
Paper::Paper(char* _mediaKey,char* _mediaName,uint32_t colorStatus,uint32_t gaStatus,uint32_t cadStatus)
{
  mediaKey_ = _mediaKey;
  mediaName_ = _mediaName;
}

/**
 * 
 */
std::string Paper::getMediaKey()
{
	return mediaKey_;
}
void Paper::setMediaKey(const std::string& _mediaKey)
{
  mediaKey_ = _mediaKey;
}

/**
 * 
 */
MediaType Paper::getMediaType()
{
  return mediaType_;
}
void Paper::setMediaType(MediaType &mediaType)
{
	mediaType_ = mediaType;
}

/**
 * 
 */
std::string Paper::getName()
{
	return mediaName_;
}
void Paper::setName(const std::string& _name)
{
  mediaName_ = _name;
}

/**
 * 
 */
std::string Paper::getShortName()
{
  return mediaShortName_;
}
void Paper::setShortName(const std::string& _shortName)
{
  mediaShortName_ = _shortName;
}

/**
 * 
 */
std::string Paper::getVendor()
{
  return vendorName_;
}
void Paper::setVendor(const std::string& _vendor)
{
  vendorName_ = _vendor;
}

/**
 * 
 */
std::string Paper::getDonorKey()
{
	return donorKey_;
}
void Paper::setDonorKey(const std::string& _donorKey)
{
  donorKey_ = _donorKey;
}

/**
 * 
 */
uint32_t Paper::getCategory()
{
	return category_;
}
void Paper::setCategory(const uint32_t _category)
{
  category_ = _category;
}

/**
 * 
 */
std::string Paper::getCategoryName()
{
  return categoryName_;
}
void Paper::setCategoryName(const std::string& _categoryName)
{
  categoryName_ = _categoryName;
}

/**
 * 
 */
std::string Paper::getShortCategoryName()
{
  return shortCategoryName_;
}

void Paper::setShortCategoryName(const std::string& _shortCategoryName)
{
  shortCategoryName_ = _shortCategoryName;
}

/**
 * 
 */
std::string Paper::getCategoryToString()
{
  return categoryString_;
}
void Paper::setCategoryToString(const std::string& _categoryString)
{
  categoryString_ = _categoryString;
}

/**
 * 
 */
std::string Paper::getRevision()
{
	return revision_;
}
void Paper::setRevision(const std::string& _revision)
{
  revision_ = _revision;
}

/**
 * 
 */
uint32_t Paper::getConsume()
{
	return consume_;
}
void Paper::setConsume(const uint32_t _consume)
{
	consume_ = _consume;
}

/**
 * 
 */
bool Paper::isCoreMedia()
{
	return coreMedia_;
}
void Paper::setCoreMedia(const bool _coreMedia)
{
  coreMedia_ = _coreMedia;
}

/**
 * 
 */
bool Paper::isErasable()
{
	return erasable_;
}
void Paper::setErasable(const bool _erasable)
{
  erasable_ = _erasable;
}

/**
 * 
 */
bool Paper::isCalibratable()
{
	return calibratable_;
}
void Paper::setCalibratable(const bool _calibratable)
{
  calibratable_ = _calibratable;
}

/**
 * 
 */
bool Paper::isCutterSupported()
{
  return cutter_;
}
void Paper::setCutterSupported(const bool _cutterSupported)
{
  cutter_ = _cutterSupported;
}

/**
 * 
 */
bool Paper::isBorderlesSupported()
{
  return borderless_;
}
void Paper::setBorderlesSupported(const bool _borderlesSupported)
{
  borderless_ = _borderlesSupported; 
}

/**
 * 
 */
bool Paper::isScanningSupported()
{
  return scanning_;
}
void Paper::setScanningSupported(const bool _scanningSupported)
{
  scanning_ = _scanningSupported;
}

/**
 * Return a paper color calibration intance that contain all ICalibrationStatus of paper.
 * 
 * @return ICalibrationStatus*
 */
CommonCalibration* Paper::getCalibration(CommonCalibration::ViewsCalibrationKind calibrationType)
{
  return calibrationMap_[calibrationType];
}
void Paper::setCalibration(CommonCalibration &_colorCalibration)
{
  calibrationMap_.insert(std::make_pair(_colorCalibration.getCalibrationType(),&_colorCalibration));
}

/** Method to be called to register a new Observer.
 *  @param observer object to be registered. Later will be notified.
 */
void Paper::registerObserver(IObserver &observer)
{
    onChangeList_.push_back( &observer );
}


/** Method to be called to unregister an existant Observer.
 *  @param observer object to be unregistered. No more notifications will be received.
 */
void Paper::unregisterObserver(IObserver &observer)
{
  onChangeList_.remove(&observer);
}

/** This method should be called by the observable to notify all the attached observers.
 *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void Paper::notify(uint32_t reason){

    for ( std::list <IObserver *>::iterator it = onChangeList_.begin() ; it != onChangeList_.end() ; it++ )
    {
        (*it)->onChange(*(static_cast<IObservable*>(this)), reason);
    }

}

/**
 * 
 */
Paper::~Paper()
{

}

