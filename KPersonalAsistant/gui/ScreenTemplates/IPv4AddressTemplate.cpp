#include "IPv4AddressTemplate.h"

IPv4AddressTemplate::IPv4AddressTemplate(QWidget *parent): QWidget(parent, Qt::FramelessWindowHint)
{
  setupUi(this);
  connect(iplineeditwidget,SIGNAL(ipAddressChanged(QString)),this,SIGNAL(giveBackAddress(QString)));

}

void IPv4AddressTemplate::show()
{
  hasBeenShowed_ = true;
}

bool IPv4AddressTemplate::clear()
{
  hasBeenShowed_ = false;
  return true;
}

void IPv4AddressTemplate::setWindowTitle(const std::string &_windowTitle_)
{
  screentitle->setWindowTitle(QString::fromStdString(_windowTitle_));
}

IPv4AddressTemplate::~IPv4AddressTemplate()
{

}
