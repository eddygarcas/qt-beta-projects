#include "InkLevelTemplate.h"
#include <iostream>
#include <typeinfo>

InkLevelTemplate::InkLevelTemplate(QWidget *parent) :
  QWidget(parent, Qt::FramelessWindowHint)
{
  setupUi(this);
}

bool InkLevelTemplate::clear()
{
  QWidget *obj;
  for (; Ui_InkLevelScreen::hboxLayout->count()!=0;)
  {
    obj = dynamic_cast<QWidget*>(Ui_InkLevelScreen::hboxLayout->itemAt(0)->widget());
    Ui_InkLevelScreen::hboxLayout->removeWidget(obj);
  }
  hasBeenShowed_ = false;
  return true;
}

void InkLevelTemplate::addInkLevel(const QString color, int32_t percent)
{
  InkLevel *ink_ = new InkLevel(0,0,this);
  ink_->setColorText(color);
  ink_->change_ink_value(percent);
  Ui_InkLevelScreen::hboxLayout->addWidget(ink_);
}

void InkLevelTemplate::show()
{
  hasBeenShowed_ = true;
}

void InkLevelTemplate::setWindowTitle(const std::string &_windowTitle_)
{
  screentitle->setWindowTitle(QString::fromStdString(_windowTitle_));
}

InkLevelTemplate::~InkLevelTemplate()
{

}
