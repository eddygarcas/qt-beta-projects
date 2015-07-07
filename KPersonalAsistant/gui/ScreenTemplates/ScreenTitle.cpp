#include "ScreenTitle.h"
#include "FrontPanelEnum.h"

ScreenTitle::ScreenTitle(QWidget *parent):QWidget(parent,Qt::FramelessWindowHint)
{
  //resize(QSize(WIDGET_WIDTH,TITLE_HEIGHT));
  setMaximumHeight(TITLE_HEIGHT);
  setMinimumHeight(TITLE_HEIGHT);

  setContentsMargins(0,0,0,0);
  hboxLayout = new QHBoxLayout(this);
  hboxLayout->setSpacing(0);
  hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
  hboxLayout->setContentsMargins(0, 0, 0, 0);

  vboxLayout = new QVBoxLayout();
  vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
  vboxLayout->setSpacing(0);
  vboxLayout->setContentsMargins(0, 0, 0, 0);


  vboxLayout1 = new QVBoxLayout();
  vboxLayout1->setSpacing(0);
  vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
  vboxLayout1->setContentsMargins(0, 0, 0, 0);

  screen_title = new QLabel(this);
  //screen_title->resize(QSize(WIDGET_WIDTH,TITLE_HEIGHT));

  screen_title->setObjectName(QString::fromUtf8("screen_title"));

  vboxLayout1->addWidget(screen_title);

  separator = new QFrame(this);
  separator->setObjectName(QString::fromUtf8("separator"));
  separator->setFrameShape(QFrame::HLine);
  separator->setFrameShadow(QFrame::Sunken);

  vboxLayout1->addWidget(separator);


  vboxLayout->addLayout(vboxLayout1);


  hboxLayout->addLayout(vboxLayout);

  QMetaObject::connectSlotsByName(parent);
}


void ScreenTitle::setScreenTitle(QString &screenTitle)
{
  screen_title->setText(screenTitle);
  aux_screenTitle = screenTitle;
}
void ScreenTitle::setWindowTitle(const QString _textScreen)
{
  screen_title->setText(_textScreen);
}

ScreenTitle::~ScreenTitle()
{
  delete hboxLayout;
  delete vboxLayout;
  delete vboxLayout1;
  delete screen_title;
  delete separator;

  hboxLayout   = 0;
  vboxLayout   = 0;
  vboxLayout1  = 0;
  screen_title = 0;
  separator    = 0;
}


