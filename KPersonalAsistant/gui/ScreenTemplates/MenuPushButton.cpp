#include "MenuPushButton.h"
#include <iostream>

/*We remove  title and border window with FramelessWindowHint constructor parameter.*/
MenuPushButton::MenuPushButton(const QSize &_size, QWidget *parent) :
  QPushButton(parent)
{

  resize(_size);

  setMinimumSize(QSize(0,0));//51, 51));
  setMaximumSize(_size);

  setIconSize(_size);

  QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  setSizePolicy(sizePolicy);
  connect(this,SIGNAL(clicked(bool)),this,SLOT(menu_button_clicked(bool)));
  installEventFilter(this);

}

QIcon MenuPushButton::onfocusIcon()
{
  return mouseOverIcon_;
}

void MenuPushButton::setOnfocusIcon(const QIcon &_iconOn)
{
  mouseOverIcon_ = _iconOn;
}

QIcon MenuPushButton::outfocusIcon()
{
  return mouseOutIcon_;
}

void MenuPushButton::setOutfocusIcon(const QIcon &_iconOut)
{
  mouseOutIcon_ = _iconOut;
  setIcon(mouseOutIcon_);
}

QSize MenuPushButton::buttonSize()
{
  return QSize(width(), height());
}

void MenuPushButton::setButtonSize(QSize &_buttonSize)
{
  setIconSize(_buttonSize);
  resize(_buttonSize);
}

bool MenuPushButton::buttonEnabled()
{
  return isEnabled();
}

void MenuPushButton::setButtonEnabled(bool _buttonEnabled)
{
  setEnabled(_buttonEnabled);
}

QString MenuPushButton::buttonInformation()
{
  return toolTip();
}

void MenuPushButton::setButtonInformation(const QString &_buttonInformation)
{
  setToolTip(_buttonInformation);
}

void MenuPushButton::menu_button_clicked(bool checked_)
{
  if (menuAction_ != NULL)
  {
    menuAction_->execute();
  }
}

/**
 * Implements a eventFilter to control the keys that will be pressed.
 *
 * In every key press event this function re-calculate the scroll bar position to show the virtual
 * object in visible rectangle. If the object which we will show is out of visible rectangle,
 * will change a widgets positions to allow a correct visualization.
 *
 * Note:
 *  parentWidget->focusWidget() returns a widget child which its values are relative to super-parent, such as y(),x() methods
 *  however the widget->children() method returns QObject list which its values are relative to parent.
 *
 * @param QObject* Object that we want apply the event filter.
 * @param QEvent* Relased event
 */
bool MenuPushButton::eventFilter(QObject *target, QEvent *event)
{
  QKeyEvent *aux = static_cast<QKeyEvent*>(event);
  bool ret = false;

  if (target==this)
  {
    switch (event->type())
    {
    case QEvent::FocusIn:
    case QEvent::HoverEnter://127 The mouse cursor enters a hover widget (QHoverEvent).
      setIcon(mouseOverIcon_);
      emit text_to_status_bar(toolTip());
      ret = true;
      break;
    case QEvent::FocusOut:
    case QEvent::HoverLeave://128 The mouse cursor leaves a hover widget (QHoverEvent).
      setIcon(mouseOutIcon_);
      ret = true;
      break;
    case QEvent::KeyPress:
      switch(aux->key())
      {
        case Qt::Key_Enter:
          menu_button_clicked(true);
          ret = true;
          break;
      }
      break;
    default:
      ret = false;
      break;

    }
  }
  return ret;

}

void MenuPushButton::setActionModel(IViewsAction *_actionModel)
{
  menuAction_ = _actionModel;
}

MenuPushButton::~MenuPushButton()
{

}
