#ifndef CUSTOMCOM_H
#define CUSTOMCOM_H

#include <QObject>
#include <QtSerialPort>

class CustomCOM : public QSerialPort
{
    Q_OBJECT

public:

    CustomCOM(qint32 baudRate, QObject* parent = 0);

private:

    bool initCOM(const QString& description);

public slots:

    void slotOpenCOM(QBitArray);

    void slotCloseCOM();

private:

    // Очередной массив точек, передаваемый на чарт
    QByteArray XY;

private slots:

    // Формируем очередной массив точек, передаваемый на чарт
    // и отправляем сигнал с массивом при его заполнении
    void slotXY(void);

signals:

    // Отправляем сигнал с точками на чарт
    void signalXYforChart(const QByteArray);

    void signalCOMready(QBitArray);
};

#endif // CUSTOMCOM_H
