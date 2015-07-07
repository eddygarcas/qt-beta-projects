#include "StatusBar.h"
#include "FrontPanelEnum.h"
#include <iostream>
#include <iomanip>

/*We remove  title and border window with FramelessWindowHint constructor parameter.*/
StatusBar::StatusBar(QWidget *parent):QWidget(parent,Qt::FramelessWindowHint){


  //resize(_size);

  setLayoutDirection(Qt::RightToLeft);
  vboxLayout = new QVBoxLayout(this);
  vboxLayout->setSpacing(0);
  vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
  vboxLayout->setContentsMargins(0, 0, 0, 0);
  statusBar = new QFrame(this);
  statusBar->setObjectName(QString::fromUtf8("statusBar"));
  QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  sizePolicy.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
  statusBar->setSizePolicy(sizePolicy);
  statusBar->setMinimumSize(QSize(STATUS_BAR_WIDTH, STATUS_BAR_HEIGHT));
  statusBar->setMaximumSize(QSize(UNDEFINED_SIZE, STATUS_BAR_HEIGHT));
  statusBar->setLayoutDirection(Qt::LeftToRight);
  statusBar->setFrameShape(QFrame::Box);
  statusBar->setFrameShadow(QFrame::Raised);
  vboxLayout1 = new QVBoxLayout(statusBar);
  vboxLayout1->setSpacing(0);
  vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
  vboxLayout1->setContentsMargins(2, 0, 0, 0);
  status_text = new QLabel(statusBar);
  status_text->setObjectName(QString::fromUtf8("status_text"));
  sizePolicy.setHeightForWidth(status_text->sizePolicy().hasHeightForWidth());
  status_text->setSizePolicy(sizePolicy);
  status_text->setMaximumSize(QSize(UNDEFINED_SIZE, STATUS_BAR_HEIGHT));
  status_text->setAutoFillBackground(false);
  status_text->setScaledContents(false);

  vboxLayout1->addWidget(status_text);


  vboxLayout->addWidget(statusBar);


  //QObject::connect(this, SLOT(statusText(QString)), status_text, SLOT(setText(QString)));
  QMetaObject::connectSlotsByName(parent);

}

void StatusBar::statusText(QString _text)
{
  status_text->setText(_text);
}

StatusBar::~StatusBar()
{
  delete vboxLayout;
  delete statusBar;
  delete vboxLayout1;
  delete status_text;

  vboxLayout  = 0;
  statusBar   = 0;
  vboxLayout1 = 0;
  status_text = 0;

}
