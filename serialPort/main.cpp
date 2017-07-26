#include "CustomCOM.h"
#include "ErrorWidget.h"
#include "CheckWindow.h"
#include "ChartWindow.h"


int main(int argc, char** argv)
{

    QApplication app(argc, argv);

    CheckWindow checkWindow;
    checkWindow.setFixedSize(640, 240);

    ErrorWidget errorWidget;
    errorWidget.setFixedSize(550, 80);

    CustomCOM* pSerialPort = new CustomCOM(QSerialPort::Baud115200,
                                           &checkWindow);

    ChartWindow chartWindow;

    QObject::connect(&checkWindow, SIGNAL(signalNoChecks()),
                     &errorWidget, SLOT(slotNoChecks()));

    QObject::connect(&checkWindow, SIGNAL(signalChartsChecked(QBitArray)),
                     pSerialPort, SLOT(slotOpenCOM(QBitArray)));

    QObject::connect(pSerialPort, SIGNAL(error(QSerialPort::SerialPortError)),
                     &errorWidget, SLOT(slotSerialError(QSerialPort::SerialPortError)));

    QObject::connect(pSerialPort, SIGNAL(signalCOMready(QBitArray)),
                     &chartWindow, SLOT(slotShowCharts(QBitArray)));

    QObject::connect(pSerialPort, SIGNAL(signalXYforChart(QByteArray)),
                     &chartWindow, SLOT(slotShowPoints(QByteArray)));


    checkWindow.show();

    return app.exec();
}
