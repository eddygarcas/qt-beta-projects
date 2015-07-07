#include "TextListMenuTemplate.h"
#include "OptionPushButton.h"
#include <QString>
#include <iostream>

TextListMenuTemplate::TextListMenuTemplate(QWidget *parent) :
    QWidget(parent, Qt::FramelessWindowHint)
{
    setupUi(this);
}

void TextListMenuTemplate::show()
{
    hasBeenShowed_ = true;
}

bool TextListMenuTemplate::clear()
{
    widgetscroll->removeAll();
    hasBeenShowed_ = false;
    return true;
}

void TextListMenuTemplate::addOption(const std::string &_label_, IViewsAction *_action_)
{
    OptionPushButton *_newOptionButton;
    if (_action_->hasMenuOption())
    {
        _newOptionButton = new OptionPushButton(_label_,this);
        //TODO: Change the image path, this is a test
        _newOptionButton->setOutfocusIcon(QIcon(QString::fromUtf8(":/turbotaj/mainmenu/mainMenu/connectivityIcon.bmp")));
    }
    else
    {
        _newOptionButton = new OptionPushButton(_label_,this);
        //TODO: Change the image path, this is a test
        _newOptionButton->setOutfocusIcon(QIcon(QString::fromUtf8(":/turbotaj/mainmenu/mainMenu/connectivityIconSelected.bmp")));
    }

    _newOptionButton->setActionModel(_action_);

    widgetscroll->addWidget(_newOptionButton, QString::fromUtf8(_action_->getObjectName().c_str()), this);
}

void TextListMenuTemplate::addOption(MenuPushButton *_pushButton_)
{

}

void TextListMenuTemplate::addHidden(Qt::Key _key_, IViewsAction *_action_)
{

}

void TextListMenuTemplate::setWindowTitle(const std::string &_windowTitle_)
{
    screentitle->setWindowTitle(QString::fromStdString(_windowTitle_));
}

TextListMenuTemplate::~TextListMenuTemplate()
{

}
