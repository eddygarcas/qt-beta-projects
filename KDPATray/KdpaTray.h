#ifndef WINDOW_H
#define WINDOW_H

#include <QSystemTrayIcon>
#include <QWidget>
#include <ui_KNotitaScreen.h>
#include "ui_CSServerConfig.h"
#include "io.h"
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QUdpSocket>

#include <QTimer>

class KdpaTray: public QWidget
{
    Q_OBJECT

public:
    KdpaTray();

    void setVisible(bool visible);

protected:

    void closeEvent(QCloseEvent *event);

private slots:

    void setIcon(int index);
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void showMessage();
    void messageClicked();
    void newKNota();
    void configEnds();
    void publishInitalIP(int);
    void publishFinalIP(int);
    void publishPingInterval(int);
    void checkServers();
    void stopScanning();
    void publishSubNetValue(int);
    void publishNetValue(int);
    void publishMaskValue(int);

private:

    void createActions();
    void createTrayIcon();

    QAction *stopScan;
    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QAction *actionNewKNota;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    Ui::CSServerConfig cSServerConfig;

    int initIp;
    int subNetValue;
    int maskValue;
    int netValue;
    int finalIp;
    int interval;

    QString ipInitialServer;
    QString ipFinalServer;
    QString ipBase;
    QSystemTrayIcon::MessageIcon icon;
    QString trayMessageText;
    QString trayMessageTitle;
    QUdpSocket *udpSocket;
    QTimer *timer;

};

#endif
