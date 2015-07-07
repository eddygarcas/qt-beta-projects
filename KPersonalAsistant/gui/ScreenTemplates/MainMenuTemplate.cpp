#include "MainMenuTemplate.h"
#include <iostream>

MainMenuTemplate::MainMenuTemplate(QWidget *parent): QWidget(parent, Qt::FramelessWindowHint)
{
  setupUi(this);
  row_ = 0;
  col_ = 0;
}

void MainMenuTemplate::show()
{
  hasBeenShowed_ = true;
}

bool MainMenuTemplate::clear()
{
  hasBeenShowed_ = false;
  return true;
}


void MainMenuTemplate::addOption(const std::string &_label_, IViewsAction *_action_)
{
//Here not makes sense.
}

void MainMenuTemplate::addOption(MenuPushButton *_pushButton_)
{
  connect(_pushButton_,SIGNAL(text_to_status_bar(QString)),statusbar,SLOT(statusText(QString)));
  gridLayout->addWidget(_pushButton_,row_,col_);
  if ((col_ + 1) >= MAX_MENU_COLS)
  {
    row_++;
    col_ = 0;
  }
  else
  {
    col_++;
  }
}

void MainMenuTemplate::addHidden(Qt::Key _key_, IViewsAction *_action_)
{

}


void MainMenuTemplate::setWindowTitle(const std::string &_windowTitle_)
{
  screentitle->setWindowTitle(QString::fromStdString(_windowTitle_));
}

MainMenuTemplate::~MainMenuTemplate()
{
  std::cout << "MainMenuTemplate has been called" << std::endl;
}
