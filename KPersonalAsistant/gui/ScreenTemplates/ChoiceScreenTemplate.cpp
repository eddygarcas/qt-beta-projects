#include "ChoiceScreenTemplate.h"

ChoiceScreenTemplate::ChoiceScreenTemplate(QWidget *parent): QWidget(parent, Qt::FramelessWindowHint)
{
  setupUi(this);
}

void ChoiceScreenTemplate::show()
{
  hasBeenShowed_ = true;
}

bool ChoiceScreenTemplate::clear()
{
  hasBeenShowed_ = false;
  return true;
}

void ChoiceScreenTemplate::setWindowTitle(const std::string &_windowTitle_)
{
  screentitle->setWindowTitle(QString::fromStdString(_windowTitle_));
}

ChoiceScreenTemplate::~ChoiceScreenTemplate()
{
  delete Ui_ChoiceScreen::vboxLayout;
  delete Ui_ChoiceScreen::vboxLayout1;
  delete Ui_ChoiceScreen::screentitle;
  delete Ui_ChoiceScreen::widgetscroll;

  Ui_ChoiceScreen::vboxLayout   = 0;
  Ui_ChoiceScreen::vboxLayout1  = 0;
  Ui_ChoiceScreen::screentitle  = 0;
  Ui_ChoiceScreen::widgetscroll = 0;

}
