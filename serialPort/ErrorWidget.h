#ifndef ERRORWIDGET_H
#define ERRORWIDGET_H

#include <QtWidgets>
#include <QtSerialPort>

class ErrorWidget: public QWidget
{

    Q_OBJECT

public:

    ErrorWidget(QWidget* parent = 0):
        QWidget(parent), text(nullptr), ok(new QPushButton("OK")), layout(nullptr)
    {
        QObject::connect(ok, SIGNAL(clicked()), this, SLOT(close()));
    }

    ~ErrorWidget();

public slots:

    void slotSerialError(QSerialPort::SerialPortError error);

    void slotNoChecks();

private:
    QLabel* text;
    QPushButton* ok;
    QVBoxLayout* layout;

    void setLabel(const QString& label);
};

#endif // ERRORWIDGET_H
