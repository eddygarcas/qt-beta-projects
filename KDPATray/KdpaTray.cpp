#include <QtGui>

#include "KdpaTray.h"
#include "ostream.h"
#include <QIODevice>

KdpaTray::KdpaTray()
{

    udpSocket = new QUdpSocket(this);
    timer = new QTimer(this);

    initIp = 0;
    finalIp = 0;
    interval = 1;
    createActions();
    createTrayIcon();

    trayIcon->show();

    resize(400, 300);
    setIcon(0);
    setWindowTitle(tr("CS Server alert config"));
    trayMessageTitle = tr("CS Server alert");
    trayMessageText = tr("Wellcome to Counter Strike server alarm. \nBy this program you can will be alerted when any server is active.\nInforms to you what is the active server, give it to you an internet address value.");

    showMessage();
    cSServerConfig.setupUi(this);
    connect(cSServerConfig.initialValue_2, SIGNAL(valueChanged(int)), this, SLOT(publishSubNetValue(int)));
    connect(cSServerConfig.initialValue_3, SIGNAL(valueChanged(int)), this, SLOT(publishNetValue(int)));
    connect(cSServerConfig.initialValue_4, SIGNAL(valueChanged(int)), this, SLOT(publishMaskValue(int)));
    connect(timer, SIGNAL(timeout()), this, SLOT(checkServers()));
    connect(timer, SIGNAL(stop()), this, SLOT(stopScanning()));

}

void KdpaTray::newKNota()
{

    show();

}

void KdpaTray::setVisible(bool visible)
{
    minimizeAction->setEnabled(visible);
    QWidget::setVisible(visible);
}

void KdpaTray::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible())
    {
        trayMessageTitle = tr("CS Server alert");
        trayMessageText = tr("The program will keep running in the "
            "system tray. To terminate the program, "
            "choose <b>Quit</b> in the context menu "
            "that pops up when clicking this program's "
            "entry in the system tray.");
        showMessage();
        hide();
        event->ignore();
    }
}

void KdpaTray::setIcon(int index)
{
    QIcon icon(":/tray/images/csico");
    trayIcon->setIcon(icon);
    setWindowIcon(icon);
}

void KdpaTray::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        //iconComboBox->setCurrentIndex((iconComboBox->currentIndex() + 1)
        //                              % iconComboBox->count());
        break;
    case QSystemTrayIcon::MiddleClick:
        //showMessage();
        break;
    default:
        ;
    }
}

void KdpaTray::showMessage()
{
    icon = QSystemTrayIcon::MessageIcon(QStyle::SP_MessageBoxInformation);

    trayIcon->showMessage(trayMessageTitle, trayMessageText, icon, 5 * 1000);

}

void KdpaTray::messageClicked()
{

}

void KdpaTray::configEnds()
{
    ipInitialServer.clear();
    ipFinalServer.clear();
    ipBase.clear();

    ipBase.append(QString::number(maskValue, 10));
    ipBase.append(".");
    ipBase.append(QString::number(netValue, 10));
    ipBase.append(".");
    ipBase.append(QString::number(subNetValue, 10));
    ipBase.append(".");

    ipInitialServer.append(ipBase);
    ipInitialServer.append(QString::number(initIp, 10));

    ipFinalServer.append(ipBase);
    ipFinalServer.append(QString::number(finalIp, 10));

    trayMessageTitle = tr("CS Server alert");
    trayMessageText.clear();
    trayMessageText.append(tr("Start scanning process from "));
    trayMessageText.append(ipInitialServer);
    trayMessageText.append(" to ");
    trayMessageText.append(ipFinalServer);
    trayMessageText.append(" at ");
    trayMessageText.append(QString::number(interval, 10));
    trayMessageText.append(" interval minutes");

    timer->start(interval * 10000);

    showMessage();
}

void KdpaTray::checkServers()
{
    bool findIt = false;
    QByteArray datagram;
    trayMessageTitle = tr("CS Server alert");
    trayMessageText.clear();
    trayMessageText.append(tr("Have been found next CS servers:\n\n"));

    for (int idx = initIp; idx < finalIp; idx++)
    {
        datagram = "Calling to CS server from CS Server alert";
        datagram.append(QString::number(idx, 10));

        std::cout << "Ping to: " << datagram.data() << std::endl;

        if (udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress(QString::fromRawData(ipBase.data(),ipBase.size()).append(QString::number(idx, 10))), 25015)
                != -1)
        {
            trayMessageText.append(ipBase);
            trayMessageText.append(QString::number(idx, 10));
            trayMessageText.append(":25015\n");
            findIt = true;
        }
        datagram.clear();
    }
    if (findIt)
        showMessage();
}
void KdpaTray::stopScanning()
{
    trayMessageText.clear();
    trayMessageText.append(tr("Scanning has been stoped\n"));
    showMessage();
}

void KdpaTray::publishInitalIP(int startIt)
{
    initIp = startIt;
}
void KdpaTray::publishSubNetValue(int _value)
{
    subNetValue = _value;
}
void KdpaTray::publishNetValue(int _value)
{
    netValue = _value;
}
void KdpaTray::publishMaskValue(int _value)
{
    maskValue = _value;
}

void KdpaTray::publishFinalIP(int finaIp)
{
    finalIp = finaIp;
}
void KdpaTray::publishPingInterval(int intervalPing)
{
    interval = intervalPing;
}

void KdpaTray::createActions()
{
    actionNewKNota = new QAction(tr("&Scanner config"), this);
    connect(actionNewKNota, SIGNAL(triggered()), this, SLOT(newKNota()));

    stopScan = new QAction(tr("S&top scanning"), this);
    connect(stopScan, SIGNAL(triggered()), timer, SLOT(stop()));

    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void KdpaTray::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(actionNewKNota);
    trayIconMenu->addAction(stopScan);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
}

