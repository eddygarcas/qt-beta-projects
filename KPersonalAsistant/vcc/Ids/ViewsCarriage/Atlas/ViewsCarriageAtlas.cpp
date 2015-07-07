/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   ViewsCarriageAtlas.cpp
 *  @author Xavier Santotomas
 *  @date   Wed Nov 21 11:46:08 CET 2007
 *  @brief  Views Carriage Atlas Component.
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *   
 */
////////////////////////////////////////////////////////////////////////////// 

#include "Logging.h"
#include "Carriage/ICarriage.h"
#include "Cds/ICds.h"
#include "ViewsPen.h"
#include "ViewsCarriageAtlas.h"
#include "ViewsPenSlot.h"


#include "IViewsLocalizationManager.h"
#include "src/LocalizationManager.h"
#include "ILocale.h"
#include "src/Locale.h"
#include "ILanguage.h"
#include "LocalizationIdentifiers.h"

/** create a Atlas instance of a ViewsCarriage.
 *   @param name instance name.
 *   @return a pointer to the instance.
 */
IComponent * getViewsCarriageAtlas(std::string name)
{
    ViewsCarriageAtlas *it;
    it = new ViewsCarriageAtlas(name);
    assert_removable(it);
    return it;
}

/** public constructor.
 *   @param instanceName instance name.
 */
ViewsCarriageAtlas::ViewsCarriageAtlas(std::string instanceName) : IComponent(instanceName, "ViewsCarriageAtlas")
{
	
    // by definition this is a singleton, 
    // if you would need more than one instance sharing the same log,
    // check while creating the log if it's the first log created, in that case create it,
    // otherwise, retrieve the existant
    log_ = new Logging(componentName(), 3);
    log_->prefix("VCC");
    log_->set(0); //channel for info
    log_->set(1); //channel for warnings
    log_->set(2); //channel for errors
	
    myObservable_ = new Observable(log_);
}

/** public destructor.
 */
ViewsCarriageAtlas::~ViewsCarriageAtlas()
{
    delete log_;
    delete myObservable_;
}

/** initialize the component.
 *  @note at initialization time components must ask for all the memory and
 *  Operating System services that they are suposed to use. No other component or
 *  hardware access is allowed.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsCarriageAtlas::initialize(void)
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
Result ViewsCarriageAtlas::start(void)
{
    
    uint32_t totalPens = carriage_->getPens().size();		
	
    PenCollection iPenCollection = carriage_->getPens();

    //We are going to create an intermediate sortedPenCollection array,
    //in order to sort the Pens function of the slot position returned by the IPen contained into the PenCollection.
    //This is because we don't trust in the order as returned by the carriage_->getPens() method.
    //This array will contain the indexes of the iPenCollection vector already sorted by the slot of the IPen contained into the PenCollection. 
    //IMPORTANT: we are suppossing that getSlot method is returning values in range [0..totalPens-1]
	
    uint32_t *sortedPenCollection = new uint32_t[totalPens];	
	
    for (uint32_t i=0; i < totalPens; i++ )
    {
        sortedPenCollection[iPenCollection[i]->getSlot()] = i;
    }
	
    for (uint32_t i=0; i < totalPens; i++ )
    {
        ViewsPen  *currentViewsPen = new ViewsPen(cds_,iPenCollection[sortedPenCollection[i]],suppliesConfigurator_,log_);

        viewsPenCollection_.push_back(currentViewsPen);

        // we create the slots (one for every Pen previosly created)    
        slotsCollection_.push_back(new ViewsPenSlot(currentViewsPen, iPenCollection[sortedPenCollection[i]], log_));
		
        log_->log(0, "%s: The status of the pen %d is: %d\n",componentName().data(),  i, viewsPenCollection_.back()->getStatusAsStringKey());


IViewsLocalizationManager* locManager = &LocalizationManager::getInstance();

log_->log(0, "Test 1 \n");

Locale loc("ES", "es");
log_->log(0, "Test 2 \n");


ILanguage* myLang = locManager->getLanguage(loc, "GUI");
ILanguage* myLang2 = locManager->getLanguage(loc, "GUI");

log_->log(0, "Test 3 \n");

std::string mystring = myLang->getString(static_cast<l10n::StringKey>(640));

log_->log(0, "The localized status of the pen is: %s\n",mystring.data());

locManager->releaseLanguage(loc, "GUI");
Locale loc2("JA", "ja");
ILanguage* myLang3 = locManager->getLanguage(loc2, "WEB");
locManager->releaseLanguage(loc, "GUI");
locManager->releaseLanguage(loc2, "WEB");

		
        currentViewsPen->registerObserver(*this);
    }
		
    delete [] sortedPenCollection;
	
    return RESULT_OK;
}

/** perform an emergency shutdown.
 *  @note only the indispensable actions should be performed.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsCarriageAtlas::emergencyShutdown(void)
{
    // nothing indispensable to do...
    return RESULT_OK;
}

/** shutdown the component.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsCarriageAtlas::shutdown(void)
{
    for (ViewsPenIterator i = viewsPenCollection_.begin(); i != viewsPenCollection_.end(); i++)
    {
        IViewsPen *currentPen = *i;
        currentPen->unregisterObserver(*this);
        delete currentPen;
    }

    for (ViewsPenSlotIterator j = slotsCollection_.begin(); j != slotsCollection_.end(); j++)
    {
        delete *j;
    }

    return RESULT_OK;
}

/** enter sleep mode.
 *  @note most likely this would mean doing some power saving activities on it.
 * 
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsCarriageAtlas::enterSleepMode(void)
{
    return RESULT_OK;
}

/** abandon the sleep mode.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result ViewsCarriageAtlas::exitSleepMode(void)
{
    return RESULT_OK;
}

/** provide a pointer of a named interface.
 * 
 *  @param instanceName the name of the component instance providing the interface.
 *  @param interfaceName the name of the provided interface.
 *  @param interface a pointer to the provided interface.
 */
void ViewsCarriageAtlas::setInterface(std::string instanceName, std::string interfaceName, void *interface)
{
    if (interfaceName == "ICarriage")
    {
        carriage_ = (ICarriage *)interface;
    }
    else if (interfaceName == "ICds")
    {
        cds_ = (ICds *)interface;
    }
    else if (interfaceName == "ISuppliesConfigurator")
    {
        suppliesConfigurator_ = (ISuppliesConfigurator *)interface;
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
void ViewsCarriageAtlas::getInterface(std::string interfaceName, void **interface)
{
    assert_removable(interfaceName == "IViewsCarriage");
    *interface = (void *)((IViewsCarriage *)this);
}


/** method to receive notificatios from the observable objects.
 *  @param observable is the object that forced the execution of this method.
 *  @param reason reason for the callback, it has to be defined in the class using this callback.
 */
void ViewsCarriageAtlas::onChange(IObservable &observable, uint32_t reason)
{

    IViewsPen &observableViewsPen = (IViewsPen &)observable;
	
    log_->log(0, "%s: I'm being notified by ViewsPen%d !!! reason: %d \n", componentName().data(),observableViewsPen.getSlotPosition(), reason);
	
    // notify this change to all registered observers (for views carriage observers the reason will be the pen slot position)
    notify(observableViewsPen.getSlotPosition());
	
}

/** Method to be called to register a new Observer.
 *  @param observer object to be registered. Later will be notified.
 */
void ViewsCarriageAtlas::registerObserver(IObserver &observer)
{
    myObservable_->registerObserver(observer);
}


/** Method to be called to unregister an existant Observer.
 *  @param observer object to be unregistered. No more notifications will be received.
 */
void ViewsCarriageAtlas::unregisterObserver(IObserver &observer)
{
    myObservable_->unregisterObserver(observer);
}

/** This method should be called by the observable to notify all the attached observers.
 *  @param reason is the slot position (0..n-1) of the ViewsPen raising the change
 */
void ViewsCarriageAtlas::notify(uint32_t reason)
{
    myObservable_->notify(reason);
}



/** Method returning a copy of the vector of Views Pens
 *   @return a copy of the vector of Views Pens
 */
ViewsPenCollection ViewsCarriageAtlas::getViewsPens()
{
    return viewsPenCollection_;
}


/** Method returning a copy of the vector of Views Pen Slots
 *   @return a copy of the vector of Views Pen Slots
 */
ViewsPenSlotCollection ViewsCarriageAtlas::getViewsPenSlots()
{
    return slotsCollection_;
}
