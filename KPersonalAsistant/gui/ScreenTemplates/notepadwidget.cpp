/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   notepadwidget.cpp
 *  @author Eduard Garcia
 *  @date   Wed May 23 17:29:11 CEST 2007
 *  @brief  Language class definition
 *
 *  (c) Copyright Hewlett-Packard Company, 2000-2007.
 *  All rights reserved. Copying or other reproduction of this program except
 *  for archival purposes is prohibited without written consent of
 *  Hewlett-Packard Company.
 *
 */
//////////////////////////////////////////////////////////////////////////////

#include "notepadwidget.h"


/**
* Widget constructor
* Defines widget visual aspect and default values.
* @param *parent Widget parent
*/
NotepadWidget::NotepadWidget(QWidget *parent): QWidget(parent)
{

  //resize(QSize(240,30));

  setMinimumSize(QSize(0,20));
  //setMaximumSize(QSize(240,100));

  wordList = new QListWidget(this);
  wordList->setObjectName(QString::fromUtf8("wordList"));
  QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
  sizePolicy2.setHorizontalStretch(0);
  sizePolicy2.setVerticalStretch(0);
  wordList->setSizePolicy(sizePolicy2);
  wordList->setFrameShape(QFrame::StyledPanel);
  wordList->setFrameShadow(QFrame::Sunken);
  wordList->setLineWidth(0);
  wordList->setTabKeyNavigation(false);
  wordList->setAlternatingRowColors(false);
  wordList->setSelectionMode(QAbstractItemView::SingleSelection);
  wordList->setMovement(QListView::Static);
  wordList->setFlow(QListView::LeftToRight);
  wordList->setProperty("isWrapping", QVariant(true));
  wordList->setLayoutMode(QListView::SinglePass);
  wordList->setViewMode(QListView::ListMode);
  wordList->setModelColumn(0);
  wordList->setWordWrap(true);
  wordList->setSortingEnabled(false);
  wordList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  wordList->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

  aux_wordArray = QString("a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z, ");
  setProperty("activeDelKey",true);
  setProperty("activeReturnKey",true);
  wordList->setFocus();
  wordList->installEventFilter(this);

  QMetaObject::connectSlotsByName(this);
}

/**
 * Sets a keys that can be inserted in front panel. Must been separated with character ','
 *
 * @param QString List of characters separated with ','
 */
void NotepadWidget::setWordArray(QString wordArray)
{
  QListWidgetItem *item;
  QStringList::iterator i;
  wordList->clear();
  QStringList list_words = wordArray.split(",", QString::SkipEmptyParts);
  for (i = list_words.begin(); i != list_words.end(); ++i)
  {
    item = new QListWidgetItem(wordList);
    item->setData(2,*i);
    item->setData(3,0);
    item->setText(*i);
  }

  if (activeReturnKey())
  {
    item = new QListWidgetItem(wordList);
    item->setData(3,3);
    item->setIcon(QIcon(QString::fromUtf8(":/notepad/icons/next.png")).pixmap(QSize(16,16)));
  }

  if(activeDelKey())
  {
  item = new QListWidgetItem(wordList);
  item->setData(3,1);
  item->setIcon(QIcon(QString::fromUtf8(":/notepad/icons/undo.png")).pixmap(QSize(16,16)));
  }

  item = new QListWidgetItem(wordList);
  item->setData(3,2);
  item->setIcon(QIcon(QString::fromUtf8(":/notepad/icons/no.xpm")).pixmap(QSize(16,16)));

  wordList->adjustSize();
  aux_wordArray = wordArray;
}

/**
 * Define if the delete functionality is enabled.
 *
 * @param bool
 */
void NotepadWidget::setActiveDelKey(bool value)
{
  delKey = value;
  setWordArray(aux_wordArray);
}

/**
 * Define if the return key is enabled
 *
 * @param bool
 */
void NotepadWidget::setActiveReturnKey(bool value)
{
  returnKey = value;
  setWordArray(aux_wordArray);
}

bool NotepadWidget::autoHide()
{
  return autoHide_;
}

void NotepadWidget::setAutoHide(bool _autoHide)
{
  autoHide_ = _autoHide;
}


/**
 * Implements a eventFilter to control the keys that will be pressed.
 *
 * @param QObject* Object that we want apply the event filter.
 * @param QEvent* Relased event
 */
bool NotepadWidget::eventFilter(QObject *target,QEvent *event)
{
  bool ret = false;
  if (target==wordList && event->type()==QEvent::KeyPress)
  {
    QKeyEvent *aux = static_cast<QKeyEvent*>(event);
    switch(aux->key())
    {
      case Qt::Key_Right:
      case Qt::Key_Up:
        if (wordList->currentRow()==wordList->count()-1)
        {
          wordList->setCurrentRow(0);
        }else{
          wordList->setCurrentRow(wordList->currentRow()+1);
        }
        ret = true;
      break;
      case Qt::Key_Left:
      case Qt::Key_Down:
        if (wordList->currentRow()<=0)
        {
          wordList->setCurrentRow(wordList->count()-1);
        }else{
          wordList->setCurrentRow(wordList->currentRow()-1);
        }
        ret = true;
      break;
      default:
        ret = false;
    }
  }
  return ret;
}

/**
 * This slot will be released when the word list object selection change.
 *
 * @param QListWidgetItem* Object that have focus.
 */
void NotepadWidget::on_wordList_itemActivated(QListWidgetItem * item)
{

  switch (qvariant_cast<int>(item->data(3)))
  {
    case 0:
      emit sendCharacter(static_cast<QChar>(qvariant_cast<QString>(item->data(2)).at(0)));
      break;
    case 1:
      emit deletePreviousCharacter();
      break;
    case 2:
      emit closeTextPad();
      break;
    case 3:
      emit sendReturn(QString::fromUtf8("\r\n"));
      break;
  }
  /*we Put the cursor at the end of file, it's important when will be show the vertical scroll bar,
   * thus we have always the cursor at the end of file and the user will can see where writes*/
  //QCoreApplication::sendEvent(notepad,new QKeyEvent(QEvent::KeyPress,16777233,Qt::NoModifier));
}

void NotepadWidget::hidden_textPad()
{
  this->close();
}

void NotepadWidget::show_textPad()
{
  if (autoHide())
  {
    this->show();
  }
}

NotepadWidget::~NotepadWidget()
{
  delete vboxLayout;
  delete wordList;

  vboxLayout = 0;
  wordList   = 0;

}
