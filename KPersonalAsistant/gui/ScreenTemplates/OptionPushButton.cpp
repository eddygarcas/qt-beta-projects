#include "OptionPushButton.h"
#include "FrontPanelEnum.h"
#include <QtCore/QString>
#include <iostream>

/*We remove  title and border window with FramelessWindowHint constructor parameter.*/
OptionPushButton::OptionPushButton(const std::string& optionText,QWidget *parent) :
  MenuPushButton(QSize(SCREEN_WIDTH,BUTTON_HEIGHT),parent)
{
  MenuPushButton::setFlat(true);
  MenuPushButton::setText(QString::fromUtf8(optionText.c_str()));
  setStyleSheet("text-align: left");
}

void OptionPushButton::setOptionText(const std::string& optionText)
{
    setText(QString::fromUtf8(optionText.c_str()));
}

OptionPushButton::~OptionPushButton()
{

}
