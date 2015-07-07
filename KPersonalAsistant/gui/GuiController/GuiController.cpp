#include <QtGui/QApplication>
#include <QtCore/QResource>
#include <QtGui/QListWidgetItem>

#include "GuiController.h"
#include "ActionFactory.h"


GuiController::GuiController(QWidget *_parent) :
  QStackedWidget(_parent)
{

#ifdef MONOCROME_SCREEN
  this->parentWidget()->setFixedSize(QSize(240, 160));
  QPalette palette;
  QBrush brush(QColor(255, 255, 255, 255));
  brush.setStyle(Qt::SolidPattern);
  palette.setBrush(QPalette::Active, QPalette::Base, brush);
  palette.setBrush(QPalette::Active, QPalette::Window, brush);
  this->parentWidget()->setPalette(palette);
#endif

}

void GuiController::start()
{
  /* TODO:
   * Should be created a RCC file which contains all front panel images. The command-line to generate this is thus:
   *
   * rcc -binary filename.qrc -o filename.rcc
   *
   * and put binary file when you want.
   * The RCC must be from latest Qtopia version in atlas tools.
   */
  QResource::registerResource("turbotaj_image_resource.rcc");

  int32_t index;
  //TODO: Add templates in the same order of screen enumeration in IScreenTemplate interface.
  index = insertWidget( IScreenTemplate::CHOICE_TEMPLATE,       &choiceScreen_         );
  index = insertWidget( IScreenTemplate::TOPLEVEL_TEMPLATE,     &topLevelScreen_       );
  index = insertWidget( IScreenTemplate::INKLEVEL_TEMPLATE,     &inkLevelScreen_       );
  index = insertWidget( IScreenTemplate::PROGRESSBAR_TEMPLATE,  &progressBarTemplate_  );
  index = insertWidget( IScreenTemplate::MENU_TEMPLATE,         &mainMenuTemplate_     );
  index = insertWidget( IScreenTemplate::ANIMATION_TEMPLATE,    &animationTemplate_    );
  index = insertWidget( IScreenTemplate::INPUTADDRESS_TEMPLATE, &ipv4AddressTemplate_  );
  index = insertWidget( IScreenTemplate::TEXT_MENU_TEMPLATE,    &textListMenuTemaplte_ );


  loadTopLevel();

}

void GuiController::setInterface(std::string _interfaceName, void *_interface)
{
  if (_interfaceName == "IPrinterInformation")
  {
    //printerInformation_ = static_cast<IPrinterInformation*>(_interface);
  }
}

bool GuiController::eventFilter(QObject *_target, QEvent *_event)
{
  bool ret = false;
  if (_event->type()==QEvent::KeyPress)
  {
    QKeyEvent *aux = static_cast<QKeyEvent*>(_event);
    switch (aux->key())
    {
    case Qt::Key_Escape:
      break;
    case Qt::Key_M:
      if (currentIndex() != (int32_t)IScreenTemplate::MENU_TEMPLATE)
      {
        loadMainMenu();
      }
      else
      {
        loadTopLevel();
      }
      break;
    case Qt::Key_Enter:
      break;
    case Qt::Key_F1:
      ActionFactory::instance().getAction(IViewsAction::INKLEVEL_ACTION)->execute();
      break;
    case Qt::Key_F2:
      ActionFactory::instance().getAction(IViewsAction::ANIMATION_TEST_ACTION)->execute();
      break;
    case Qt::Key_F3:
      ActionFactory::instance().getAction(IViewsAction::INSERT_IPV4_ACTION)->execute();
      break;
    case Qt::Key_F4:
      break;
    case Qt::Key_Delete:
      break;
    }
  }
  return ret;
}

int32_t GuiController::addWidget(QWidget *_widget)
{
  putWidgetCharacteristics(_widget);
  return QStackedWidget::addWidget(_widget);

}

int32_t GuiController::insertWidget(
    IScreenTemplate::screenTemplate_enum screenTemplate_, QWidget* _widget)
{
  putWidgetCharacteristics(_widget);
  return QStackedWidget::insertWidget((int32_t)screenTemplate_, _widget);
}

IScreenTemplate* GuiController::screenInstance(int32_t index)
{
  return dynamic_cast<IScreenTemplate*>(widget(index));
}

IScreenTemplate* GuiController::currentWidget(void)
{
  return screenInstance(currentIndex());
}

void GuiController::setCurrentIndex(int32_t _index)
{
  QStackedWidget::setCurrentIndex(_index);
}

void GuiController::putWidgetCharacteristics(QWidget *_widget)
{
  _widget->setParent(this->parentWidget());
  _widget->installEventFilter(this);
  //_widget->setFixedSize(QSize(WIDGET_WIDTH, WIDGET_HEIGHT));
  //_widget->setMinimumSize(QSize(WIDGET_WIDTH, WIDGET_HEIGHT));
  _widget->setWindowOpacity(1.0);
}

void GuiController::show(void)
{
  currentWidget()->show();
  this->parentWidget()->show();
}

IScreenTemplate* GuiController::getScreenTemplateInstance(
    IScreenTemplate::screenTemplate_enum _screenTemplate)
{
  return screenInstance((int32_t)_screenTemplate);
}

bool GuiController::canBeExecuted(IViewsAction::actionType_enum _actionType)
{
  return true;
}

void GuiController::loadMainMenu()
{
  if (getScreenTemplateInstance(IScreenTemplate::MENU_TEMPLATE)->hasBeenShowed())
  {
    setCurrentIndex((int32_t)IScreenTemplate::MENU_TEMPLATE);
    show();
  }
  else
  {
    ActionFactory::instance().getAction(IViewsAction::MENU_ACTION)->execute();
  }
}

void GuiController::loadTopLevel()
{
  if (getScreenTemplateInstance(IScreenTemplate::TOPLEVEL_TEMPLATE)->hasBeenShowed())
  {
    setCurrentIndex((int32_t)IScreenTemplate::TOPLEVEL_TEMPLATE);
    show();
  }
  else
  {
    ActionFactory::instance().getAction(IViewsAction::TOPLEVEL_ACTION)->execute();
  }
}


