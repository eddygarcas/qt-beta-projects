/* -*- c++ -*- */
////////////////////////////////////////////////////////////////////////////////
/**
 *  @file   notepadwidget.h
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

#ifndef NOTEPADWIDGET_H
#define NOTEPADWIDGET_H

#include <QtGui/QWidget>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QListWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QListWidgetItem>
#include <QtCore/QModelIndexList>
#include <QtCore/QString>
#include <QtGui/QKeyEvent>
#include <QtCore/QtDebug>

/**Widget to insert text in front panel without keyboard only with up and down keys.*/
class NotepadWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString wordArray READ wordArray WRITE setWordArray)
    Q_PROPERTY(bool activeDelKey READ activeDelKey WRITE setActiveDelKey)
    Q_PROPERTY(bool activeReturnKey READ activeReturnKey WRITE setActiveReturnKey)
    Q_PROPERTY(bool autoHide READ autoHide WRITE setAutoHide)

public:
  /**
   * Widget constructor
   * 
   * @param *parent Widget parent
   */
  NotepadWidget(QWidget *parent = 0);
     
  /**
   * Sets a keys that can be inserted in front panel. Must been separated with character ','
   * 
   * @param QString List of characters separated with ','
   */
  void setWordArray(QString wordArray);
  /**
   * Gets a character string.
   * 
   * @return QString
   */
  QString wordArray(){ return aux_wordArray;}
    
  /**
   * Define if the delete functionality is enabled.
   * 
   * @param bool
   */
  void setActiveDelKey(bool value);
  /**
   * Return the status of delete funcionality.
   * 
   * @return bool
   */
  bool activeDelKey(){return delKey;}
  
  /**
   * Define if the return key is enabled
   * 
   * @param bool
   */
  void setActiveReturnKey(bool value);
  /**
   * Return the status of return key
   * 
   * @return bool1
   */
  bool activeReturnKey(){return returnKey;}
  
  /**
   * Implements a eventFilter to control the keys that will be pressed.
   * 
   * @param QObject* Object that we want apply the event filter.
   * @param QEvent* Relased event
   */
  bool eventFilter(QObject *target,QEvent *event);
  
  bool autoHide();
  
  void setAutoHide(bool _autiHide);
  
  /**
   * Class destructor
   */
  virtual ~NotepadWidget();

public slots:
  /**
   * This is slot will be released when the word list object selection change.
   * 
   * @param QListWidgetItem* Object that have focus.
   */
  void on_wordList_itemActivated(QListWidgetItem * item);

  void hidden_textPad();
  
  void show_textPad();

signals:
  
  void sendReturn(QString _fullText);

  void sendCharacter(QChar _character);
  
  void deletePreviousCharacter();

  void closeTextPad();
  
private:
  bool        delKey,returnKey,autoHide_;
  QString     aux_wordArray;
  QVBoxLayout *vboxLayout;
  QListWidget *wordList;
};


#endif // NOTEPADWIDGET_H
