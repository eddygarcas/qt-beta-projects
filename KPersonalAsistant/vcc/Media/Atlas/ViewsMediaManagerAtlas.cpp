#include "views_types.h"
#include "ViewsMediaManagerAtlas.h"

#include "RedOS_pub_api.h"
#include "MediaPath/IMediaPath.h"
#include "MediaAdvanceCalibration.h"

#include <sstream>

/** create a fake instance of a PrinterInformationFake.
 *  @param name instance name.
 *  @return a pointer to the instance.
 */
IComponent* getViewsMediaManagerAtlas(std::string name)
{
  ViewsMediaManagerAtlas * it;
  it = new ViewsMediaManagerAtlas(name);
  assert_removable(it);
  return it;
}

/**
 * Class constructor, we must pass the instance name which we want to create.
 * 
 * @param std::string
 */
ViewsMediaManagerAtlas::ViewsMediaManagerAtlas(std::string _instanceName) :
  IComponent(_instanceName, "ViewsMediaManagerAtlas")
{
  monitor_ = RedOSMonitorCreate();
  assert_removable(monitor_ != 0);
  log_ = new Logging(componentName(), 3);
  log_->prefix("VCC");
  log_->set(LOG_INFO);
  log_->set(LOG_WARNING);
  log_->set(LOG_ERROR);

  mediaPrinted_ = 0;
  pagesPrinted_ = 0;

}

/**Virtual destructor*/
ViewsMediaManagerAtlas::~ViewsMediaManagerAtlas()
{
  delete log_;
}

/**
 * Load a intray elemento into list of papers
 * 
 * @param viewsIntray
 */
Result ViewsMediaManagerAtlas::loadPaper(IViewsIntray &viewsIntray)
{
  if (getActiveIntray() != &viewsIntray)
  {
    return engineStateMachine_->LoadMedia(viewsIntray.getSource());
  } else
  {
    return RESULT_NOSENSE;
  }
}

/**
 * Returns a ViewsMediaCollection of IViewsIntrays pointers
 * 
 * @return ViewsMediaCollection
 */
ViewsMediaCollection ViewsMediaManagerAtlas::getIntrays()
{
  ViewsMediaCollection aux_intrayList;
  for (unsigned int i = 0; i<intrayList.size(); i++)
  {
    aux_intrayList.push_back(static_cast<IViewsIntray*>(&intrayList.at(i)));
  }

  return aux_intrayList;
}

/**
 * Return the active Intray object.
 *  * @return IViewsIntray
 */
IViewsIntray* ViewsMediaManagerAtlas::getActiveIntray()
{
  IViewsIntray* retIntray;
  IMediaPath::InputPath inputPath_;

  std::vector<ViewsIntray>::iterator it;

  if (mediaManager_->getSelectedInputDevice(inputPath_)
      == IMediaManager::MEDIA_OK)
  {
    ViewsIntray intrayAux(inputPath_);
    for (it = intrayList.begin(); it!=intrayList.end(); it++)
    {
      retIntray = static_cast<IViewsIntray*>(&(static_cast<ViewsIntray>(*it)));
      if (retIntray == &intrayAux)
        break;
    }
  }
  return retIntray;
}

/**
 * Return the actual status
 * 
 * @return IViewsMediaManager::ViewsMediaStatus 
 */
IViewsMediaManager::ViewsMediaStatus ViewsMediaManagerAtlas::getStatus()
{
  IViewsMediaManager::ViewsMediaStatus ret;

  IMediaManager::MediaStatus mediaStatus_ = mediaManager_->getStatus();
  switch (mediaStatus_)
  {
  case IMediaManager::MS_NOT_INITIALIZED:
    ret = IViewsMediaManager::VIEWS_MS_NOT_INITIALIZED;
    break;
  case IMediaManager::MS_INITIALIZING:
    ret = IViewsMediaManager::VIEWS_MS_INITIALIZING;
    break;
  case IMediaManager::MS_CHECKING:
    ret = IViewsMediaManager::VIEWS_MS_CHECKING;
    break;
  case IMediaManager::MS_NO_PAPER:
    ret = IViewsMediaManager::VIEWS_MS_NO_PAPER;
    break;
  case IMediaManager::MS_PRINTING:
    ret = IViewsMediaManager::VIEWS_MS_PRINTING;
    break;
  case IMediaManager::MS_READY:
    ret = IViewsMediaManager::VIEWS_MS_READY;
    break;
  case IMediaManager::MS_ERROR:
    ret = IViewsMediaManager::VIEWS_MS_ERROR;
    break;
  }
  return ret;
}

/**
 * Return the active output tray instance.
 * 
 * @return IViewsOutputTray 
 */
IViewsOutputTray* ViewsMediaManagerAtlas::getActiveOutTray()
{
  /**TODO: Not avaiable information for outtrays.
   * However, it's necessary to assure that. I must speak with engine team for this.
   */
  return 0;
}

/**
 * Total comsumption of media for print quality.
 * Iterator order makes relationship with ViewsPrintQuality sort enumeration 
 * 
 * @return ViewsMediaPrintQualityCollection
 */
ViewsMediaPrintQualityCollection ViewsMediaManagerAtlas::getUsagePrintQuality()
{
  return usagePrintQuality_;
}

/**
 * Total consumption of media for print type
 * Iterator order makes relationship with ViewsPrintType sort enumeration
 * 
 * @return ViewsMediaPrintTypeCollection
 */
ViewsMediaPrintTypeCollection ViewsMediaManagerAtlas::getUsagePrintType()
{
  return usagePrintType_;
}

/**
 * It returns the total media printed in inches.
 * 
 * @return uint32_t
 */
uint32_t ViewsMediaManagerAtlas::getTotalMediaPrinted()
{
  return mediaPrinted_;
}

/**
 * It returns total pages printed.
 * 
 * @return uint32_t
 */
uint32_t ViewsMediaManagerAtlas::getTotalPagesPrinted()
{
  return pagesPrinted_;
}

/**
 * Returns media advance calibration
 * 
 * @return CommonCalibration*
 */
CommonCalibration* ViewsMediaManagerAtlas::getMediaAdvanceCalibration()
{
  return mediaAdvanceCalibration_;
}

/** method to receive notificatios from the observable objects.
 *  @param observable is the object that forced the execution of this method.
 *  @param reason reason for the callback, it has to be defined in the class using this callback.
 */
void ViewsMediaManagerAtlas::onChange(IObservable &observable, uint32_t reason)
{
  start();
  notify (reason);
}

/** Method to be called to register a new Observer.
 *  @param observer object to be registered. Later will be notified.
 */
void ViewsMediaManagerAtlas::registerObserver(IObserver &observer)
{
  lock();
  onChangeList_.push_back( &observer );
  unlock();
}

/** Method to be called to unregister an existant Observer.
 *  @param observer object to be unregistered. No more notifications will be received.
 */
void ViewsMediaManagerAtlas::unregisterObserver(IObserver &observer)
{
  lock();
  onChangeList_.remove(&observer);
  unlock();
}

/** This method should be called by the observable to notify all the attached observers.
 *  @param reason is the reason for the callback, it has to be defined in the class using this callback.
 */
void ViewsMediaManagerAtlas::notify(uint32_t reason)
{

  for (std::list <IObserver *>::iterator it = onChangeList_.begin() ; it
      != onChangeList_.end() ; it++)
  {
    (*it)->onChange(*(static_cast<IObservable*>(this)), reason);
  }
}

/** initialize the component.
 *  @note at initialization time components must ask for all the memory and
 *  Operating System services that they are suposed to use. No other component or
 *  hardware access is allowed.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsMediaManagerAtlas::initialize(void)
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
Result ViewsMediaManagerAtlas::start(void)
{

  obtainIntrayList();
  obtainPrintUsage("PT", usagePrintType_);
  obtainPrintUsage("PQ", usagePrintQuality_);
  obtainMediaUsage();
  obtainMediaAdvanceCalibration();

  for (unsigned int i = 0; i<intrayList.size(); i++)
  {
    IViewsIntray* aux = static_cast<IViewsIntray*>(&intrayList.at(i));
    log_->log(
        LOG_INFO,
        "Hold intray information is\n Model: %s \n Capacity: %d \n Path: %d \n Page store: %d \n Page count: %d \n",
        aux->getModel().c_str(), aux->getMaxCapacity(), aux->getSource(),
        aux->getPageStore(), aux->getPageCount());
  }

  for (unsigned int i = 0; i<usagePrintQuality_.size(); i++)
  {
    int32_t aux = usagePrintQuality_.at(i);
    log_->log(LOG_INFO, "Usage print type: %d\n", aux);
  }

  for (unsigned int i = 0; i<usagePrintType_.size(); i++)
  {
    int32_t aux = usagePrintType_.at(i);
    log_->log(LOG_INFO, "Usage print type: %d\n", aux);
  }

  log_->log(LOG_INFO, "The media printed is: %d and pages printed are: %d",
      mediaPrinted_, pagesPrinted_);

  return RESULT_OK;
}

/** perform an emergency shutdown.
 *  @note only the indispensable actions should be performed.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsMediaManagerAtlas::emergencyShutdown(void)
{
  // nothing indispensable to do...
  return RESULT_OK;
}

/** shutdown the component.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsMediaManagerAtlas::shutdown(void)
{

  return RESULT_OK;
}

/** enter sleep mode.
 *  @note most likely this would mean doing some power saving activities on it.
 * 
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsMediaManagerAtlas::enterSleepMode(void)
{
  return RESULT_OK;
}

/** abandon the sleep mode.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsMediaManagerAtlas::exitSleepMode(void)
{
  return RESULT_OK;
}

/** provide a pointer of a named interface.
 * 
 *  @param instanceName the name of the component instance providing the interface.
 *  @param interfaceName the name of the provided interface.
 *  @param interface a pointer to the provided interface.
 */
void ViewsMediaManagerAtlas::setInterface(std::string instanceName,
    std::string interfaceName, void *interface)
{
  log_->log(LOG_INFO, "Doing setInterface method %s\n", interfaceName.data());

  if (interfaceName == "ICds")
  {
    cds_ = (ICds *)interface;
  } else if (interfaceName == "IMediaManager")
  {
    mediaManager_ = (IMediaManager *)interface;
  } else if (interfaceName == "IEngineStateMachine")
  {
    engineStateMachine_ = (IEngineStateMachine *)interface;
  } else if (interfaceName == "IUsageCounters")
  {
    usageCountersInterface_ = (IUsageCounters*)interface;
  } else if (interfaceName == "INvm")
  {
    nvmInterface_ = (INvm*)interface;
  } else
  {
    assert (0);
  }

}

/** query for an an interface that you implement.
 * 
 *  @param interfaceName the name of the interface that other is asking you to provide.
 *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
 */
void ViewsMediaManagerAtlas::getInterface(std::string interfaceName,
    void **interface)
{
  assert (interfaceName == "IViewsMediaManager");
  *interface = (void *)((IViewsMediaManager*)this);
}

/**
 * Launch operations against Engine state machine.
 * It pass through parameter a string with operation name.
 * 
 * @parm std::string
 *  
 */
bool ViewsMediaManagerAtlas::execute(std::string& _executeCommand)
{
  Result result;
  if (_executeCommand == "ColorCalibration")
  {
    result = engineStateMachine_->CalibrateColor();
  }
  return (result == RESULT_OK);
}

/** 
 * This method should be called to lock access to a resource needing mutex access.
 */
void ViewsMediaManagerAtlas::lock()
{
  tRedResult result;

  result = RedOSMonitorLock(monitor_, RED_WAIT_FOREVER);
  assert_removable(result == RED_SUCCESS);
}

/** 
 * This method should be called to unlock access to a resource needing mutex access.
 */
void ViewsMediaManagerAtlas::unlock()
{
  RedOSMonitorUnlock(monitor_);
}

/**
 * Obtain a media usage from engine
 * 
 * @return Result
 */
Result ViewsMediaManagerAtlas::obtainMediaUsage()
{
  COUNTER_ID id;
  uint16_t nvmKey;

  if (nvmInterface_->findKey("MPROF-TOTAL-CONSUM", nvmKey) == NVM_OK)
  {
    nvmInterface_->getValue(nvmKey, &mediaPrinted_);
  } else
  {
    std::vector<IMediaManager::ConsumeRecord> consumeRecords;

    mediaManager_->getServiceInfo(consumeRecords);

    for (unsigned int i=0; i<consumeRecords.size(); i++)
    {
      mediaPrinted_ += (uint32_t)consumeRecords.at(i).consume;
    }
  }

  if (usageCountersInterface_->getId("SRV-TOTAL-NUMBER-OF-PRINTS", id) == UC_OK)
  {
    usageCountersInterface_->getCounter(id, pagesPrinted_);
  }

  return RESULT_OK;
}

/**
 * Obtain intray list from engine
 * 
 * @return Result
 */
Result ViewsMediaManagerAtlas::obtainIntrayList()
{
  IMediaPath::IntraysInfo intrays_;
  IMediaPath::IntraysInfoIterator startIterator;

  mediaManager_->getIntraysInfo(intrays_);
  for (startIterator = intrays_.begin(); startIterator != intrays_.end(); startIterator++)
  {
    IMediaPath::InputPath pa = (IMediaPath::InputPath)startIterator->first;
    intrayList.push_back(ViewsIntray(pa, cds_));
  }

  return RESULT_OK;
}

/**
 * Obtain print usage.
 * 
 * @param const char*
 * @param std::vector<int32_t>
 * @return Result
 */
Result ViewsMediaManagerAtlas::obtainPrintUsage(const char* printTag_,
    std::vector<int32_t>& printVector_)
{
  int32_t totalNumber_;
  Cds::CdsObject* cdsInternalObj_;

  std::string auxKey = buildCdsKey(buildCdsKey("MEDIA-USAGE-",0,printTag_).c_str(), 0, "-TOTAL-NUMBER");
  if (cds_->find(auxKey.c_str(), &cdsInternalObj_ ) == Cds::CDS_SUCCESS)
  {
    cdsInternalObj_->get((int32_t&)totalNumber_);

    for (int16_t i = 1; i<=totalNumber_; i++)
    {
      int32_t consum_;

      std::string tag("MEDIA-USAGE-");
      tag.append(printTag_);
      tag.append("-");

      if (cds_->find(buildCdsKey(tag.c_str(),i,"-CONSUM").c_str(), &cdsInternalObj_ ) == Cds::CDS_SUCCESS)
      {
        cdsInternalObj_->get((int32_t&)consum_);
        printVector_.push_back(consum_);
        log_->log(LOG_INFO, "Consume value: %d\n", consum_);
      }
    }
  }

  return RESULT_OK;
}

/**
 * Obtain media advance calibration from engine.
 * 
 * @return Result
 */
Result ViewsMediaManagerAtlas::obtainMediaAdvanceCalibration()
{
  Cds::CdsObject* cdsInternalObj_;
  uint32_t calibrationValue;

  if (cds_->find("STATUS-CALIBRATION-MEDIA-ADVANCE", &cdsInternalObj_ )
      == Cds::CDS_SUCCESS)
  {
    cdsInternalObj_->get((uint32_t&)calibrationValue);

    log_->log(LOG_INFO, "Value of status calibration media advance: %d\n",
        calibrationValue);

    mediaAdvanceCalibration_ = new MediaAdvanceCalibration(
        CommonCalibration::getCdsCalibrationStatus(calibrationValue),
        0,
        log_);
  }

  return RESULT_OK;
}

/**
 * Makes a CDS key value by means of parameters.
 * If _index parameter equals zero this function concate component parameter 
 * with element parameter, without index value.
 * 
 * @param const char*
 * @param int16_t
 * @param const char*
 * 
 * @return std::string
 */
std::string ViewsMediaManagerAtlas::buildCdsKey(const char* component,
    int16_t index, const char* element)
{
  std::ostringstream cdsKey_;
  if (index>0)
  {
    cdsKey_ << component << (int16_t) index << element;
  } else
  {
    cdsKey_ << component << element;
  }

  return cdsKey_.str();
}
