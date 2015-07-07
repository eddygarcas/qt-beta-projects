#include "GuiMainAtlas.h"
#include <Qt>
#include <QtGui>
#include <QResource>
#include <QApplication>
#include <QHBoxLayout>

#include "views_types.h"

#include "GuiController.h"


/** create a fake instance of a GuiMainAtlas.
 *  @param name instance name.
 *  @return a pointer to the instance.
 */
IComponent* getGuiMainAtlas(std::string name)
{
  GuiMainAtlas * it;
  it = new GuiMainAtlas(name);
  assert_removable(it);
  return it;
}

/**
 * Class constructor, we must pass the instance name which we want to create.
 * 
 * @param std::string
 */
GuiMainAtlas::GuiMainAtlas(std::string _instanceName) :
  IComponent(_instanceName, "GuiMainAtlas")
{
  monitor_ = RedOSMonitorCreate();
  assert_removable(monitor_ != 0);
  log_ = new Logging(componentName(), 3);
  log_->prefix("GUI");
  log_->set(LOG_INFO);
  log_->set(LOG_WARNING);
  log_->set(LOG_ERROR);
}

/**Virtual destructor*/
GuiMainAtlas::~GuiMainAtlas()
{
  delete log_;
}

/**
 * Starts the GUI application.
 * 
 */
void GuiMainAtlas::execute()
{
    
  log_->log(0, "Starting gui main atlas.\n");
  int32_t argc = 0;
  char **argv;

  QApplication a(argc, argv, QApplication::GuiServer);
  log_->log(0, "Starting application...\n");
  lock();
  GuiController::instance().setInterface("IPrinterInformation",printerInformation_);
  unlock();
  GuiController::instance().start();
  log_->log(0, "Ending application...\n");
  a.exec();
}

/** initialize the component.
 *  @note at initialization time components must ask for all the memory and
 *  Operating System services that they are suposed to use. No other component or
 *  hardware access is allowed.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result GuiMainAtlas::initialize(void)
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
Result GuiMainAtlas::start(void)
{
  return RESULT_OK;
}

/** perform an emergency shutdown.
 *  @note only the indispensable actions should be performed.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result GuiMainAtlas::emergencyShutdown(void)
{
  // nothing indispensable to do...
  return RESULT_OK;
}

/** shutdown the component.
 * 
 *  @return RESULT_OK if successful, the failure code otherwise.
 */
Result GuiMainAtlas::shutdown(void)
{

  return RESULT_OK;
}

/** enter sleep mode.
 *  @note most likely this would mean doing some power saving activities on it.
 * 
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result GuiMainAtlas::enterSleepMode(void)
{
  return RESULT_OK;
}

/** abandon the sleep mode.
 *
 *  @return  RESULT_OK if successful, the failure code otherwise.
 */
Result GuiMainAtlas::exitSleepMode(void)
{
  return RESULT_OK;
}

/** provide a pointer of a named interface.
 * 
 *  @param instanceName the name of the component instance providing the interface.
 *  @param interfaceName the name of the provided interface.
 *  @param interface a pointer to the provided interface.
 */
void GuiMainAtlas::setInterface(std::string instanceName,
    std::string interfaceName, void *interface)
{
  /**TODO:
   * Pass through parameter all views common clases interfaces.
   * This component will distribute these interfaces along model actions
   */
  log_->log(0, "Doing setInterface method %s\n", interfaceName.data());
  
  if (interfaceName == "IPrinterInformation")
  {
    printerInformation_ = static_cast<IPrinterInformation*>(interface);
  }
}

/** query for an an interface that you implement.
 * 
 *  @param interfaceName the name of the interface that other is asking you to provide.
 *  @param interface a pointer to the memory area where the pointer to the requested interface will be left.
 */
void GuiMainAtlas::getInterface(std::string interfaceName, void **interface)
{
  assert_removable (interfaceName == "IGuiMain");
  *interface = static_cast<void*>(static_cast<IGuiMain*>(this));
}

/** launch the component. this method will be called call after the @e start() one so the component knowing that all the system is ready to be used.
 default implementation so it is not mandatory to implement it of not needed (that @e start() provides the desired  functionality).
 @return RESULT_OK if successful, the failure code otherwise.
 @note components could perform any task they want.
 @note this is not a "virtual" function providing an empty "safe" implementation.
 */
Result GuiMainAtlas::go(void)
{
  execute();
  return RESULT_OK;
}

/** This method should be called to lock access to a resource needing mutex access.
 */
void GuiMainAtlas::lock()
{
  tRedResult result;

  result = RedOSMonitorLock(monitor_, RED_WAIT_FOREVER);
  assert_removable(result == RED_SUCCESS);
}

/** This method should be called to unlock access to a resource needing mutex access.
 */
void GuiMainAtlas::unlock()
{
  RedOSMonitorUnlock(monitor_);
}
