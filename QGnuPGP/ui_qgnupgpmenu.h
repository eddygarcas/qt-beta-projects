/********************************************************************************
** Form generated from reading ui file 'qgnupgpmenu.ui'
**
** Created: Wed 1. Jul 10:51:36 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QGNUPGPMENU_H
#define UI_QGNUPGPMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QColumnView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
 #include <QStandardItemModel>

QT_BEGIN_NAMESPACE

class Ui_QGnuPGPMenuClass
{
public:
    QAction *action_Encypt;
    QAction *action_Descypt;
    QAction *action_Key_generator;
    QAction *action_Verify;
    QAction *action_Signature;
    QAction *action_Import_keys;
    QAction *actionPublic_key;
    QAction *actionAll_keys;
    QAction *actionNew;
    QAction *action_Exit;
    QAction *action_Hitory;
    QAction *action_About_QGnuPGP;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter_2;
    QWidget *gridLayoutWidget;
    QGridLayout *keyListLayout;
    QTreeView *keyTreeView;
    QSplitter *splitter;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *filesForHandlingLayout;
    QColumnView *filesForHandlingColumView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *applicationOutputsTabsLayout;
    QTabWidget *applicationOutputsTabs;
    QWidget *consoleTab;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *consoleOutput;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Run;
    QMenu *menuOptions;
    QMenu *menu_Export_keys;
    QMenu *menu_window;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *QGnuPGPMenuClass)
    {
    if (QGnuPGPMenuClass->objectName().isEmpty())
        QGnuPGPMenuClass->setObjectName(QString::fromUtf8("QGnuPGPMenuClass"));
    QGnuPGPMenuClass->resize(552, 402);
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/menu/icons/icons/script-32x32.png")), QIcon::Normal, QIcon::Off);
    QGnuPGPMenuClass->setWindowIcon(icon);
    action_Encypt = new QAction(QGnuPGPMenuClass);
    action_Encypt->setObjectName(QString::fromUtf8("action_Encypt"));
    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/menu/icons/icons/binary-48x48.png")), QIcon::Normal, QIcon::Off);
    action_Encypt->setIcon(icon1);
    action_Descypt = new QAction(QGnuPGPMenuClass);
    action_Descypt->setObjectName(QString::fromUtf8("action_Descypt"));
    QIcon icon2;
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/menu/icons/icons/encrypted-48x48.png")), QIcon::Normal, QIcon::Off);
    action_Descypt->setIcon(icon2);
    action_Key_generator = new QAction(QGnuPGPMenuClass);
    action_Key_generator->setObjectName(QString::fromUtf8("action_Key_generator"));
    QIcon icon3;
    icon3.addPixmap(QPixmap(QString::fromUtf8(":/menu/icons/icons/exec-48x48.png")), QIcon::Normal, QIcon::Off);
    action_Key_generator->setIcon(icon3);
    action_Verify = new QAction(QGnuPGPMenuClass);
    action_Verify->setObjectName(QString::fromUtf8("action_Verify"));
    action_Verify->setIcon(icon);
    action_Signature = new QAction(QGnuPGPMenuClass);
    action_Signature->setObjectName(QString::fromUtf8("action_Signature"));
    QIcon icon4;
    icon4.addPixmap(QPixmap(QString::fromUtf8(":/menu/icons/icons/signature-48x48.png")), QIcon::Normal, QIcon::Off);
    action_Signature->setIcon(icon4);
    action_Import_keys = new QAction(QGnuPGPMenuClass);
    action_Import_keys->setObjectName(QString::fromUtf8("action_Import_keys"));
    QIcon icon5;
    icon5.addPixmap(QPixmap(QString::fromUtf8(":/menu/icons/icons/add-key-48x48.png")), QIcon::Normal, QIcon::Off);
    action_Import_keys->setIcon(icon5);
    actionPublic_key = new QAction(QGnuPGPMenuClass);
    actionPublic_key->setObjectName(QString::fromUtf8("actionPublic_key"));
    QIcon icon6;
    icon6.addPixmap(QPixmap(QString::fromUtf8(":/menu/icons/icons/open-key-48x48.png")), QIcon::Normal, QIcon::Off);
    actionPublic_key->setIcon(icon6);
    actionAll_keys = new QAction(QGnuPGPMenuClass);
    actionAll_keys->setObjectName(QString::fromUtf8("actionAll_keys"));
    QIcon icon7;
    icon7.addPixmap(QPixmap(QString::fromUtf8(":/menu/icons/icons/key-48x48.png")), QIcon::Normal, QIcon::Off);
    actionAll_keys->setIcon(icon7);
    actionNew = new QAction(QGnuPGPMenuClass);
    actionNew->setObjectName(QString::fromUtf8("actionNew"));
    QIcon icon8;
    icon8.addPixmap(QPixmap(QString::fromUtf8(":/menu/icons/icons/man-48x48.png")), QIcon::Normal, QIcon::Off);
    actionNew->setIcon(icon8);
    action_Exit = new QAction(QGnuPGPMenuClass);
    action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
    action_Hitory = new QAction(QGnuPGPMenuClass);
    action_Hitory->setObjectName(QString::fromUtf8("action_Hitory"));
    QIcon icon9;
    icon9.addPixmap(QPixmap(QString::fromUtf8(":/menu/icons/icons/reports-48x48.png")), QIcon::Normal, QIcon::Off);
    action_Hitory->setIcon(icon9);
    action_About_QGnuPGP = new QAction(QGnuPGPMenuClass);
    action_About_QGnuPGP->setObjectName(QString::fromUtf8("action_About_QGnuPGP"));
    QIcon icon10;
    icon10.addPixmap(QPixmap(QString::fromUtf8(":/menu/icons/icons/readme-48x48.png")), QIcon::Normal, QIcon::Off);
    action_About_QGnuPGP->setIcon(icon10);
    centralwidget = new QWidget(QGnuPGPMenuClass);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    verticalLayout_4 = new QVBoxLayout(centralwidget);
    verticalLayout_4->setSpacing(1);
    verticalLayout_4->setMargin(1);
    verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
    splitter_2 = new QSplitter(centralwidget);
    splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
    splitter_2->setOrientation(Qt::Horizontal);
    gridLayoutWidget = new QWidget(splitter_2);
    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    keyListLayout = new QGridLayout(gridLayoutWidget);
    keyListLayout->setObjectName(QString::fromUtf8("keyListLayout"));
    keyListLayout->setContentsMargins(0, 0, 0, 0);
    keyTreeView = new QTreeView(gridLayoutWidget);
    keyTreeView->setObjectName(QString::fromUtf8("keyTreeView"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(keyTreeView->sizePolicy().hasHeightForWidth());
    keyTreeView->setSizePolicy(sizePolicy);

    keyListLayout->addWidget(keyTreeView, 0, 1, 1, 1);

    splitter_2->addWidget(gridLayoutWidget);
    splitter = new QSplitter(splitter_2);
    splitter->setObjectName(QString::fromUtf8("splitter"));
    splitter->setOrientation(Qt::Vertical);
    horizontalLayoutWidget = new QWidget(splitter);
    horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
    filesForHandlingLayout = new QHBoxLayout(horizontalLayoutWidget);
    filesForHandlingLayout->setObjectName(QString::fromUtf8("filesForHandlingLayout"));
    filesForHandlingLayout->setContentsMargins(0, 0, 0, 0);
    filesForHandlingColumView = new QColumnView(horizontalLayoutWidget);
    filesForHandlingColumView->setObjectName(QString::fromUtf8("filesForHandlingColumView"));

    filesForHandlingLayout->addWidget(filesForHandlingColumView);

    splitter->addWidget(horizontalLayoutWidget);
    filesForHandlingColumView->raise();
    verticalLayoutWidget = new QWidget(splitter);
    verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
    applicationOutputsTabsLayout = new QVBoxLayout(verticalLayoutWidget);
    applicationOutputsTabsLayout->setSpacing(0);
    applicationOutputsTabsLayout->setObjectName(QString::fromUtf8("applicationOutputsTabsLayout"));
    applicationOutputsTabsLayout->setContentsMargins(0, 0, 0, 0);
    applicationOutputsTabs = new QTabWidget(verticalLayoutWidget);
    applicationOutputsTabs->setObjectName(QString::fromUtf8("applicationOutputsTabs"));
    applicationOutputsTabs->setTabPosition(QTabWidget::South);
    applicationOutputsTabs->setTabShape(QTabWidget::Triangular);
    applicationOutputsTabs->setElideMode(Qt::ElideMiddle);
    consoleTab = new QWidget();
    consoleTab->setObjectName(QString::fromUtf8("consoleTab"));
    verticalLayout_5 = new QVBoxLayout(consoleTab);
    verticalLayout_5->setSpacing(0);
    verticalLayout_5->setMargin(0);
    verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
    consoleOutput = new QTextEdit(consoleTab);
    consoleOutput->setObjectName(QString::fromUtf8("consoleOutput"));

    verticalLayout_5->addWidget(consoleOutput);

    applicationOutputsTabs->addTab(consoleTab, QString());

    applicationOutputsTabsLayout->addWidget(applicationOutputsTabs);

    splitter->addWidget(verticalLayoutWidget);
    splitter_2->addWidget(splitter);

    verticalLayout_4->addWidget(splitter_2);

    QGnuPGPMenuClass->setCentralWidget(centralwidget);
    menubar = new QMenuBar(QGnuPGPMenuClass);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 552, 19));
    menu_File = new QMenu(menubar);
    menu_File->setObjectName(QString::fromUtf8("menu_File"));
    menu_Run = new QMenu(menubar);
    menu_Run->setObjectName(QString::fromUtf8("menu_Run"));
    menuOptions = new QMenu(menubar);
    menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
    menu_Export_keys = new QMenu(menuOptions);
    menu_Export_keys->setObjectName(QString::fromUtf8("menu_Export_keys"));
    QIcon icon11;
    icon11.addPixmap(QPixmap(QString::fromUtf8(":/menu/icons/icons/save-key-48x48.png")), QIcon::Normal, QIcon::Off);
    menu_Export_keys->setIcon(icon11);
    menu_window = new QMenu(menubar);
    menu_window->setObjectName(QString::fromUtf8("menu_window"));
    QGnuPGPMenuClass->setMenuBar(menubar);
    statusbar = new QStatusBar(QGnuPGPMenuClass);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    QGnuPGPMenuClass->setStatusBar(statusbar);
    toolBar = new QToolBar(QGnuPGPMenuClass);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    QGnuPGPMenuClass->addToolBar(Qt::TopToolBarArea, toolBar);

    menubar->addAction(menu_File->menuAction());
    menubar->addAction(menu_Run->menuAction());
    menubar->addAction(menuOptions->menuAction());
    menubar->addAction(menu_window->menuAction());
    menu_File->addAction(actionNew);
    menu_File->addSeparator();
    menu_File->addAction(action_Exit);
    menu_Run->addAction(action_Key_generator);
    menu_Run->addSeparator();
    menu_Run->addAction(action_Encypt);
    menu_Run->addAction(action_Descypt);
    menu_Run->addAction(action_Verify);
    menu_Run->addSeparator();
    menu_Run->addAction(action_Signature);
    menuOptions->addAction(menu_Export_keys->menuAction());
    menuOptions->addAction(action_Import_keys);
    menu_Export_keys->addAction(actionPublic_key);
    menu_Export_keys->addAction(actionAll_keys);
    menu_window->addAction(action_Hitory);
    menu_window->addSeparator();
    menu_window->addAction(action_About_QGnuPGP);
    toolBar->addAction(actionNew);
    toolBar->addSeparator();
    toolBar->addAction(action_Key_generator);
    toolBar->addSeparator();
    toolBar->addAction(action_Encypt);
    toolBar->addAction(action_Descypt);
    toolBar->addAction(action_Verify);

    retranslateUi(QGnuPGPMenuClass);

    applicationOutputsTabs->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(QGnuPGPMenuClass);
    } // setupUi

    void retranslateUi(QMainWindow *QGnuPGPMenuClass)
    {
    QGnuPGPMenuClass->setWindowTitle(QApplication::translate("QGnuPGPMenuClass", "MainWindow", 0, QApplication::UnicodeUTF8));
    action_Encypt->setText(QApplication::translate("QGnuPGPMenuClass", "&Encypt", 0, QApplication::UnicodeUTF8));
    action_Descypt->setText(QApplication::translate("QGnuPGPMenuClass", "&Descypt", 0, QApplication::UnicodeUTF8));
    action_Key_generator->setText(QApplication::translate("QGnuPGPMenuClass", "&Key generator", 0, QApplication::UnicodeUTF8));
    action_Verify->setText(QApplication::translate("QGnuPGPMenuClass", "&Verify", 0, QApplication::UnicodeUTF8));
    action_Signature->setText(QApplication::translate("QGnuPGPMenuClass", "&Signature", 0, QApplication::UnicodeUTF8));
    action_Import_keys->setText(QApplication::translate("QGnuPGPMenuClass", "&Import keys", 0, QApplication::UnicodeUTF8));
    actionPublic_key->setText(QApplication::translate("QGnuPGPMenuClass", "Public key", 0, QApplication::UnicodeUTF8));
    actionAll_keys->setText(QApplication::translate("QGnuPGPMenuClass", "All keys", 0, QApplication::UnicodeUTF8));
    actionNew->setText(QApplication::translate("QGnuPGPMenuClass", "New...", 0, QApplication::UnicodeUTF8));
    action_Exit->setText(QApplication::translate("QGnuPGPMenuClass", "&Exit", 0, QApplication::UnicodeUTF8));
    action_Hitory->setText(QApplication::translate("QGnuPGPMenuClass", "&Hitory", 0, QApplication::UnicodeUTF8));
    action_About_QGnuPGP->setText(QApplication::translate("QGnuPGPMenuClass", "&About QGnuPGP", 0, QApplication::UnicodeUTF8));
    applicationOutputsTabs->setTabText(applicationOutputsTabs->indexOf(consoleTab), QApplication::translate("QGnuPGPMenuClass", "Console", 0, QApplication::UnicodeUTF8));
    menu_File->setTitle(QApplication::translate("QGnuPGPMenuClass", "&File", 0, QApplication::UnicodeUTF8));
    menu_Run->setTitle(QApplication::translate("QGnuPGPMenuClass", "&Run", 0, QApplication::UnicodeUTF8));
    menuOptions->setTitle(QApplication::translate("QGnuPGPMenuClass", "&Options", 0, QApplication::UnicodeUTF8));
    menu_Export_keys->setTitle(QApplication::translate("QGnuPGPMenuClass", "&Export keys", 0, QApplication::UnicodeUTF8));
    menu_window->setTitle(QApplication::translate("QGnuPGPMenuClass", "&Window", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("QGnuPGPMenuClass", "toolBar", 0, QApplication::UnicodeUTF8));

    QStandardItemModel *keyStandardItemModel = new QStandardItemModel(keyTreeView);

    QStandardItem *parentItem = keyStandardItemModel->invisibleRootItem();
    QStandardItem *item_a = new QStandardItem(QString("Eduard Garcia Castello Keys"));
    QStandardItem *item_a1 = new QStandardItem(QString("Public Key"));
    QStandardItem *item_a2 = new QStandardItem(QString("Private Key"));
    parentItem->appendRow(item_a);
    parentItem = item_a;
    parentItem->appendRow(item_a1);
    parentItem->appendRow(item_a2);

    keyTreeView->setModel(keyStandardItemModel);

    } // retranslateUi

};

namespace Ui {
    class QGnuPGPMenuClass: public Ui_QGnuPGPMenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGNUPGPMENU_H
