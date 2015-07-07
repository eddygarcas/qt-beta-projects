#include "ViewsIntray.h"
#include <sstream>


ViewsIntray::ViewsIntray()
{
	
}

/**
 * In this constructor we pass through parameter a input media path and CDS instance, 
 * with these parameters ViewsIntray can make itself.
 * 
 * @param IMediaPath::InputPath&
 * @param ICds*
 */
ViewsIntray::ViewsIntray(IMediaPath::InputPath& _inputPath,ICds* _cds):
  cds_(_cds)
{
  Cds::CdsObject* cdsInternalObj_;
  
  if (cds_->find(buildCdsKey("INTRAY-" ,(int16_t)_inputPath ,"-MAX-CAPACITY").c_str(), &cdsInternalObj_ ) == Cds::CDS_SUCCESS)
    cdsInternalObj_->get(maxCapacity_);
  
  if (cds_->find(buildCdsKey("INTRAY-" ,(int16_t)_inputPath ,"-MODEL").c_str(), &cdsInternalObj_ ) == Cds::CDS_SUCCESS)
    cdsInternalObj_->get(model_);
 
  if (cds_->find(buildCdsKey("INTRAY-" ,(int16_t)_inputPath ,"-PAGE-COUNT").c_str(), &cdsInternalObj_ ) == Cds::CDS_SUCCESS)
    cdsInternalObj_->get(pageCount_);

  if (cds_->find(buildCdsKey("INTRAY-" ,(int16_t)_inputPath ,"-PAGE-STORE").c_str(), &cdsInternalObj_ ) == Cds::CDS_SUCCESS)
    cdsInternalObj_->get(pageStore_);


  convertToViewsInputPath(_inputPath);
}

ViewsIntray::~ViewsIntray()
{
  
}

/**
 * It returns a intray max capacity expressed in inches.
 * 
 * @return uint32_t
 */
int32_t ViewsIntray::getMaxCapacity()
{
  return maxCapacity_;
}

/**
 * It return the views intray status.
 * 
 * @return long
 */
IViewsIntray::ViewsPathStatus ViewsIntray::getStatus()
{
 return status_; 
}
                                          
/**
 * Returns a source code. See IMediaPath for more information about souce codes.
 * 
 * @return unint32_t

 */
IViewsIntray::ViewsInputPath ViewsIntray::getSource()
{
  return source_;
}
/**
 * It returns de model name.
 * 
 * @return std::string
 */
std::string ViewsIntray::getModel()
{
  return model_;
}

int32_t ViewsIntray::getPageCount()
{
  return pageCount_;
}

int32_t ViewsIntray::getPageStore()
{
  return pageStore_;
}

/** Method to be called to register a new Observer.
 *  @param observer object to be registered. Later will be notified.
 */
void ViewsIntray::registerObserver(IObserver &observer)
{
  onChangeList_.push_back(&observer );
}

/** Method to be called to unregister an existant Observer.
 *  @param observer object to be unregistered. No more notifications will be received.
 */
void ViewsIntray::unregisterObserver(IObserver &observer)
{
  onChangeList_.remove(&observer);
}

/** This method should be called by the observable to notify all the attached observers.
 *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void ViewsIntray::notify(uint32_t reason)
{
  for ( std::list <IObserver *>::iterator it = onChangeList_.begin() ; it != onChangeList_.end() ; it++ )
  {
    (*it)->onChange(*(static_cast<IObservable*>(this)), reason);
  }
}

void ViewsIntray::convertToViewsInputPath(IMediaPath::InputPath& inputPath_)
{
  int status = inputPath_;
  switch(status)
  {
  case IMediaPath::INPUT_MEDIA_FAKE:
    source_ = IViewsIntray::VIEWS_INPUT_MEDIA_FAKE;
    break;
  case IMediaPath::INPUT_MEDIA_SHEET:
    source_ = IViewsIntray::VIEWS_INPUT_MEDIA_SHEET;
    break;
  case IMediaPath::INPUT_MEDIA_SPECIALROLL:
    source_ = IViewsIntray::VIEWS_INPUT_MEDIA_SPECIALROLL;
    break;
  case IMediaPath::INPUT_MEDIA_MULTIROLL0:
    source_ = IViewsIntray::VIEWS_INPUT_MEDIA_MULTIROLL0;
    break;
  case IMediaPath::INPUT_MEDIA_MULTIROLL1:
    source_ = IViewsIntray::VIEWS_INPUT_MEDIA_MULTIROLL1;    
    break;
  case IMediaPath::INPUT_MEDIA_MULTIROLL2:
    source_ = IViewsIntray::VIEWS_INPUT_MEDIA_MULTIROLL2;    
    break;
  case IMediaPath::INPUT_MEDIA_MAX_NUM:
    source_ = IViewsIntray::VIEWS_INPUT_MEDIA_MAX_NUM;    
  }
}

void ViewsIntray::convertToViewsStatusPath(IMediaPath::PathStatus& pathStatus_)
{
  int status = pathStatus_;
  switch(status)
  {
  case IMediaPath::PS_NOT_INITIALIZED:
    status_ = IViewsIntray::VIEWS_PS_NOT_INITIALIZED;
    break;
  case IMediaPath::PS_NO_MEDIA:
    status_ = IViewsIntray::VIEWS_PS_NO_MEDIA;
    break;
  case IMediaPath::PS_PRINTING:
    status_ = IViewsIntray::VIEWS_PS_PRINTING;
    break;
  case IMediaPath::PS_READY:
    status_ = IViewsIntray::VIEWS_PS_READY;
    break;
  case IMediaPath::PS_INITIALIZING:
    status_ = IViewsIntray::VIEWS_PS_INITIALIZING;    
    break;
  case IMediaPath::PS_CHECKING:
    status_ = IViewsIntray::VIEWS_PS_CHECKING;    
    break;
  case IMediaPath::PS_NOT_ACTIVE:
    status_ = IViewsIntray::VIEWS_PS_NOT_ACTIVE;    
    break;
  case IMediaPath::PS_ERROR:
    status_ = IViewsIntray::VIEWS_PS_ERROR;
    break;
  case IMediaPath::PS_STANDBY:
    status_ = IViewsIntray::VIEWS_PS_STANDBY;    
  }
}

std::string ViewsIntray::buildCdsKey(const char* component,int16_t index,const char* element)
{
  std::ostringstream cdsKey_;
  cdsKey_ << component << (int16_t) index << element;
  return cdsKey_.str();
}


/**
 * Override equals operator
 * This function olny compare source value.
 * @param &_intray The instance that we want compare.
 * @return bool True if comparation equals, false in otherwise
 */
bool ViewsIntray::operator ==(IViewsIntray &intrayLeft)
{
  return (getSource() == intrayLeft.getSource());
}

/**
 * Override non-equals operator
 * This function olny compare source value.
 * @param &_intray The instance that we want compare.
 * @return bool True if comparation equals, false in otherwise
 */
bool ViewsIntray::operator !=(IViewsIntray &intrayLeft)
{
  return (getSource() != intrayLeft.getSource());
}
