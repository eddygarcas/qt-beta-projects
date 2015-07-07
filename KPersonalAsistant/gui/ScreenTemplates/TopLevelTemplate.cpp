#include "TopLevelTemplate.h"

TopLevelTemplate::TopLevelTemplate(QWidget *parent): QWidget(parent, Qt::FramelessWindowHint)
{
  setupUi(this);
}

void TopLevelTemplate::setPrinterUrl(const QString _printerUrl)
{
  printerUrl->setText(_printerUrl);
}

void TopLevelTemplate::setPrinterIPv4(const QString _printerIPv4)
{
  printer_IPv4->setText(_printerIPv4);
}

void TopLevelTemplate::setManufacturerLogo(const QPixmap _manufacturerLogo)
{
  manufacturerLogo->setPixmap(_manufacturerLogo);
}

void TopLevelTemplate::setTextToMenu(const QString _textToMenu)
{
  textToMenu->setText(_textToMenu);
}

void TopLevelTemplate::show()
{
  hasBeenShowed_ = true;
}

bool TopLevelTemplate::clear()
{
  hasBeenShowed_ = false;
  return true;
}

void TopLevelTemplate::setWindowTitle(const std::string &_windowTitle_)
{
  screentitle->setWindowTitle(QString::fromStdString(_windowTitle_));
}

TopLevelTemplate::~TopLevelTemplate()
{

}
