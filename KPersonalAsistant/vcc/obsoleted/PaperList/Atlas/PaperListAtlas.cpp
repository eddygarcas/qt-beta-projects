#include "PaperListAtlas.h"
#include "CommonCalibration.h"
#include "PaperAdvanceCalibration.h"
#include "PaperCadCalibration.h"
#include "ColorPaperCalibration.h"
#include "RedOS_pub_api.h"
#include <cstdlib>

/** create a fake instance of a PrinterCalibrationManager.
 *  @param name instance name.
 *  @return a pointer to the instance.
*/
IComponent* getPaperListAtlas (std::string name)
{
  PaperListAtlas * it;
  it = new PaperListAtlas (name);
  assert_removable(it);
  return it;
}


PaperListAtlas::PaperListAtlas(std::string instance):
  IComponent(instance,"PaperListAtlas")
{
  //
  // Mutual exclusion semaphore.
  //
  monitor_ = RedOSMonitorCreate();
  assert_removable(monitor_ != 0);
  log_ = new Logging(componentName(), 3);
  log_->prefix("VCC");
  log_->set(0);
  log_->set(1);
  log_->set(2);
  
}

/**
 * Remove all media instances
 */
PaperListAtlas::~PaperListAtlas()
{
  delete log_;
}

/**
 * Return a paper list version
 * 
 * @return uint32_t
 */
int32_t PaperListAtlas::getPaperListVersion(void)
{ 
	return atoi(paperListVersion.c_str());
}

/**
 * It returns a IPaper instance, by means of media key and locale specified by parameter.
 * 
 * @param _mediaKey Key value of paper item.
 * @param _locale Instance of ILocale interface with system locale value.
 * @return IPaper*
 */
IPaper* PaperListAtlas::getPaper(const std::string &_Key,ILocale &_loc)
{
  /**
   *NOTE: Same case as getPaperIterator(), if the paper list are void, 
   * you must create a connection to engine for obtaining a paper list. 
   * next, you will be able to obtain a paper element with key value.
   * Developer: You must create a funtion for this functionality.
   */
  if (locale_ != _loc)
  {
    changeMediaLocale(_loc);
  }
  return static_cast<IPaper*>(&mediaList[_Key]);
}

/**
 * It returns a list of IPaper instances, they are kept in an internal list.
 * 
 * @param _locale Instance of ILocale interface with system locale value.
 * @return ViewsIterator<IPaper*>
 */
ViewsIterator<IPaper*> PaperListAtlas::getPaperIterator(ILocale &_loc)
{
  /**NOTE:
   * If the paper list are void, you should accede to engine to obtain a paper list
   * otherwise, you must iterate over paper list and make up a ViewsIterator.
   */
  std::list<IPaper*> auxList;

  std::map<std::string,Paper>::iterator startIterator;
  for (startIterator = mediaList.begin(); startIterator != mediaList.end(); startIterator++)
  {
    auxList.push_back(getPaper((std::string)startIterator->first,_loc));
  }
  return ViewsIterator<IPaper*>(auxList);
}

/** Method to be called to register a new Observer.
 *  @param observer object to be registered. Later will be notified.
 */
void PaperListAtlas::registerObserver(IObserver &observer)
{
  lock();
  onChangeList_.push_back( &observer );
  unlock();
}


/** Method to be called to unregister an existant Observer.
 *  @param observer object to be unregistered. No more notifications will be received.
 */
void PaperListAtlas::unregisterObserver(IObserver &observer)
{
  lock();
  onChangeList_.remove(&observer);
  unlock();
}

/** pure virtual function declaration.
 *  @param observable is the object that forced the execution of this method.
 *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void PaperListAtlas::onChange (IObservable & observable, uint32_t reason)
{
  start();
  notify(reason); 
}


/** This method should be called by the observable to notify all the attached observers.
 *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void PaperListAtlas::notify(uint32_t reason)
{
  for ( std::list <IObserver *>::iterator it = onChangeList_.begin() ; it != onChangeList_.end() ; it++ )
  {
    (*it)->onChange(*(static_cast<IObservable*>(this)), reason);
  }
}

/**
 * This function will be called by OMES when some change in media list
 * event parameter can be null.
 * It returns true if changes ends well or false in otherwise.
 * 
 * @param Event
 * @return bool
 */
bool PaperListAtlas::onEventCore(Event const & event) const 
{
  const_cast<PaperListAtlas*>(this)->onChange((IObservable&)*this, 1);
  return true;
}


/** initialize the component.
 *  @note at initialization time components must ask for all the memory and
 *  Operating System services that they are suposed to use. No other component or
 *  hardware access is allowed.	
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result PaperListAtlas::initialize (void)
{
  return RESULT_OK;
}

/** start the component. 
 *  @note components should perform the hardware related actions
 *  to turn into an operative status either through drivers or other
 *  components.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result PaperListAtlas::start (void)
{
  //TODO: Must change the language harcoded value for CDS language value or something like that.
  locale_ = Locale("en","EN");
  obtainPaperList(locale_.formatLocale());
  
  ViewsIterator<IPaper*> itPaper = getPaperIterator(locale_);
  log_->log(0,"Paper list in %s language\n",locale_.getLanguage().c_str());
  while (itPaper.hasNext())
  {
	IPaper *paper = itPaper.next();
	log_->log(0,"Media key: %s \n",paper->getMediaKey().c_str());
	log_->log(0,paper->getName().append("\n").data());
  }

  
  Locale aux_locale_ = Locale("es","ES");
  itPaper = getPaperIterator(aux_locale_);
  log_->log(0,"Paper list in %s language\n",locale_.getLanguage().c_str());
  while (itPaper.hasNext())
  {
    IPaper *paper = itPaper.next();
    log_->log(0,"Media key: %s \n",paper->getMediaKey().c_str());
    log_->log(0,paper->getName().append("\n").data());
  }
  
  return RESULT_OK;
}

/** perform an emergency shutdown.
 *  @note only the indispensable actions should be performed.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result PaperListAtlas::emergencyShutdown (void)
{
  return RESULT_OK;
}

/** shutdown the component.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result PaperListAtlas::shutdown (void)
{
  return RESULT_OK;
}

/** enter sleep mode.
 *  @note most likely this would mean doing some power saving activities on it.
 * 
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result PaperListAtlas::enterSleepMode (void)
{
  return RESULT_OK;
}

/** abandon the sleep mode.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result PaperListAtlas::exitSleepMode (void)
{
  return RESULT_OK;
}

/** provide a pointer of a named interface.
 * 
 *  @param instanceName the name of the component instance providing the interface.
 *  @param interfaceName the name of the provided interface.
 *  @param interface a pointer to the provided interface.
 */
void PaperListAtlas::setInterface (std::string instanceName, std::string interfaceName, void *interface)
{
  log_->log(0,"%s interface will be loaded.\n",interfaceName.data());
  
  if (interfaceName == "IOMES")
  {
    /**NOTE:
     * The unique functionality that must be implemented in this method is to obtain 
     * from omes the paper list version.
     * Because for the rest of information is necessary a locale value.
     * This value will be provided by front panel. 
     */
    omesInterface_ = (IOMES*)interface;

    paperListVersion = omesInterface_->getMediumListVersion();
    omesInterface_->newListener(this);
    
  }
  else if (interfaceName == "IMediaManager")
  {
    mediaManager_ = (IMediaManager*)interface;
  }
  else if (interfaceName == "IEngineStateMachine")
  {
    engineStateMachine_ = (IEngineStateMachine *)interface;
  }
  else
  {
	  assert_removable(0);
  }
}

/** query for an an interface that you implement.
 * 
 *  @param interfaceName the name of the interface that other is asking you to provide.
 *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
 */
void PaperListAtlas::getInterface (std::string interfaceName, void **interface)
{
  assert (interfaceName == "IPaperList");
  *interface = (void *)((IPaperList *)this);
}

/**
 * Launch operations against Engine state machine.
 * It pass through parameter a string with operation name.
 * 
 * @parm std::string
 *  
 */
bool PaperListAtlas::execute (std::string &executeCommand)
{
  return false;
}



/** This method should be called to lock access to a resource needing mutex access.
 */
void PaperListAtlas::lock()
{
    tRedResult result;
    
    result = RedOSMonitorLock(monitor_, RED_WAIT_FOREVER);
    assert_removable(result == RED_SUCCESS);
}

/** This method should be called to unlock access to a resource needing mutex access.
 */
void PaperListAtlas::unlock()
{
    RedOSMonitorUnlock(monitor_);
}

/**
 * It receives a system locale instance and make up map with paper list engine values.
 * 
 * @param _localeString String which contains a locale value in ISO 8601 format.
 * @param std::map<std::string,IPaper*>&
 */
Result PaperListAtlas::obtainPaperList(std::string localeString_)
{
 
  IOMES::MediaLocalizations localizations;
  std::vector<IMediaManager::ConsumeRecord> consumeRecords;
  std::map<std::string,IMediaManager::ConsumeRecord> consumeMap;
  IMediaManager::ConsumeRecord consumeRecord_;
  bool hasConsumeRecords;
	  
  //Obtain form iomes and media manager a media values.
  omesInterface_->getMediaLocalizations(localeString_, localizations);
  ViewsIterator<IOMES::MediaLocalization> iter(localizations);

	  
  mediaManager_->getServiceInfo(consumeRecords);
  ViewsIterator<IMediaManager::ConsumeRecord> iConsumeRecord(consumeRecords);

  //Create consumer record map to facillity itself search.
  log_->log(0,"Consume record size is: %d",iConsumeRecord.size());
  hasConsumeRecords = iConsumeRecord.size() > 0 ? true:false;
  while(iConsumeRecord.hasNext())
  {
	consumeRecord_ = iConsumeRecord.next();
	consumeMap.insert(make_pair(std::string(consumeRecord_.name),consumeRecord_));
  }
	  
  //Iterate throught localizations list to obtain a paper values.
  while(iter.hasNext())
  {
	Paper paper_;	
	AtlasMediaIdentification::MediaIdentification           mident;
	AtlasMediaSettings::MediaSettings                       msets;
	IOMES::IMediaCalibrationStatus::MediumCalibrationStatus mcStatus;

	IOMES::MediaLocalization holdMedia_ = iter.next();

    MediaType mediaId   = MediaType(holdMedia_.id, std::string());
    
	MediaType localized = localizedMedia(holdMedia_);

	if (!omesInterface_->getMediaSettings(omesInterface_->getMediaSettingsUrl(mediaId), holdMedia_.id, msets))
	{
      assert_removable(0);
	}
	    
	if(msets.cutter && msets.cutter->cutterEnable)
	{
	  paper_.setCutterSupported(msets.cutter->cutterEnable->cutterEnable ? msets.cutter->cutterEnable->cutterEnable->value : false);
	}
	    
	if(msets.borderless && msets.borderless->borderlessEnable)
	{
	  paper_.setBorderlesSupported(msets.borderless->borderlessEnable->borderlessEnable ? msets.borderless->borderlessEnable->borderlessEnable->value : false);
	}
	   
	omesInterface_->getMediaIdentification(mediaId, mident);

	paper_.setMediaType(mediaId);
	paper_.setMediaKey(holdMedia_.id);
	paper_.setName(localized.getName());
	paper_.setVendor(localized.getVendor());	
	paper_.setScanningSupported((bool)omesInterface_->getScanningSupported(mediaId));
	paper_.setShortName(holdMedia_.shortName);
	paper_.setDonorKey(mident.donorId);
	paper_.setErasable(!mident.factory);
	paper_.setCategory(mident.category.asInteger());
	paper_.setCategoryName(holdMedia_.category);
	paper_.setShortCategoryName(holdMedia_.categoryShortName);
	paper_.setCategoryToString(std::string(mident.category.asString()));
	paper_.setCoreMedia(!mident.core.empty() && mident.core[0]);
	paper_.setRevision(mident.revision);
	
	if (hasConsumeRecords)
	{
	  consumeRecord_ = static_cast<IMediaManager::ConsumeRecord>(consumeMap.find(holdMedia_.id)->second);
	  paper_.setConsume(consumeRecord_.consume);
	}
	    
	    
	//Followed code-lines obtaining the color calibration from engine.
	mcStatus = omesInterface_->getMediumCalibrationStatus(mediaId, IOMES::CLC_CONFIGURATION);
	CommonCalibration::ViewsCalibrationStatus viewCalibrationStatus = CommonCalibration::getCdsCalibrationStatus(mcStatus.status);

	ColorPaperCalibration colorCalibration_(viewCalibrationStatus,mcStatus.time,log_); 
    paper_.setCalibration(colorCalibration_);
	    
    //Followed code-lines obtaining the paper advance calibration from engine.
    mcStatus = omesInterface_->getMediumCalibrationStatus(mediaId, IOMES::ADVANCE);
    viewCalibrationStatus = CommonCalibration::getCdsCalibrationStatus(mcStatus.status);
    if (mcStatus.status == IOMES::IMediaCalibrationStatus::MediumCalibrationStatus::VALID) 
    {
    	PaperAdvanceCalibration advCalibration_(viewCalibrationStatus,mcStatus.time,log_);
		paper_.setCalibration(advCalibration_);
    }
    else
    {        
      mcStatus = omesInterface_->getMediumCalibrationStatus(mediaId, IOMES::BVC_CAD_CONFIGURATION);
      viewCalibrationStatus = CommonCalibration::getCdsCalibrationStatus(mcStatus.status);
	      
      PaperCadCalibration cadCalibration_(viewCalibrationStatus,mcStatus.time,log_);
	  paper_.setCalibration(cadCalibration_);
    }
	   
    if ((paper_.getCalibration(CommonCalibration::VIEWS_BVC_CAD_CONFIGURATION)->getCalibrationStatus() == CommonCalibration::VIEWS_TODO) && (holdMedia_.donorId.empty()))
    {
      viewCalibrationStatus = CommonCalibration::VIEWS_UNDEFINED;
      
      PaperCadCalibration undefAdvCalibration_(viewCalibrationStatus,mcStatus.time,log_);

      paper_.setCalibration(undefAdvCalibration_);

    }
    mediaList.insert(make_pair(paper_.getMediaKey(),paper_));
  }
  return RESULT_OK;
}

/**
 * It Returns MediaType instance from IOMES media instance.
 * 
 * @param _media
 */
MediaType PaperListAtlas::localizedMedia(IOMES::MediaLocalization media)
{
  return this->localizedMedia(media.id,media.name);
}

/**
 * It Returns MediaType instance from media id and MediaType instance.
 * 
 * @param _mediaId
 * @param _mediaName
 */
MediaType PaperListAtlas::localizedMedia(std::string mediaId_,MediaType name)
{
  MediaType mediaId         = MediaType(mediaId_, std::string());
	  
  MediaType localized  = name;

  if (localized.getName().empty())
  {
    localized.setName(mediaId.getName());
  }

  if (localized.getVendor().empty())
  {
    localized.setVendor(mediaId.getVendor());
  }
  return localized;
}

/**
 * For each paper instance, it updates the media name and vendor with value of specified locale.
 * 
 * @param &_loc
 */
Result PaperListAtlas::changeMediaLocale(ILocale &_loc)
{
  log_->log(0,"Changing internal locale to: %s",_loc.formatLocale().c_str());
  Paper *paper_;
  MediaType aux_mediatype;
  std::map<std::string,Paper>::iterator startIterator;
  
  for (startIterator = mediaList.begin(); startIterator != mediaList.end(); startIterator++)
  {
	paper_ = &mediaList[startIterator->first];
	
	aux_mediatype = omesInterface_->getLocalizedMedia(paper_->getMediaType(),_loc.formatLocale());
	
	aux_mediatype = localizedMedia(paper_->getMediaKey(),aux_mediatype);

	paper_->setMediaType(aux_mediatype);
	paper_->setName(aux_mediatype.getName());
	paper_->setVendor(aux_mediatype.getVendor());
  }
  locale_ = Locale(_loc);
  
  return RESULT_OK;
}
