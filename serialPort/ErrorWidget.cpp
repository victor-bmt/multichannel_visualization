#include "ErrorWidget.h"

ErrorWidget::~ErrorWidget()
{
    if(ok)
        delete ok;
    if(text)
        delete text;
    if(layout)
        delete layout;
}

void ErrorWidget::setLabel(const QString& label)
{
    if (text)
        delete text;
    if (layout)
        delete layout;

    text = new QLabel(label);

    layout = new QVBoxLayout;
    layout->addWidget(text);
    layout->addWidget(ok);

    setLayout(layout);

    return;
}

void ErrorWidget::slotSerialError(QSerialPort::SerialPortError error)
{
    //qDebug() << error;

    switch(error)
    {
        case (QSerialPort::NoError):
        {
            break;
        }

        case (QSerialPort::PermissionError):
        {
            setLabel("<CENTER><B>Ошибка доступа</B></CENTER>"
                    "<CENTER>Завершите все процессы, связанные с MSP430 и попробуйте снова</CENTER>");
            show();
            break;
        }

        case (QSerialPort::DeviceNotFoundError):
        {
            setLabel("<CENTER><B>Устройство не найдено</B></CENTER>"
                    "<CENTER>Сначала подключите MSP430 к ПК</CENTER>");

            show();
            break;
        }

        case (QSerialPort::ResourceError):
        {
            setLabel("<CENTER><B>Ошибка ресурса</B></CENTER>"
                    "<CENTER>Возможно MSP430 отключилось от ПК</CENTER>");

            show();
            break;
        }

        default:
        {
            setLabel("<CENTER><B>Неизвестная ошибка</B></CENTER>"
                    "<CENTER>Перезапустите приложение</CENTER>");

            show();
        }
    }

    return;
}

void ErrorWidget::slotNoChecks()
{
    setLabel("<CENTER>Выберите как минимум одну кривую для визуализации</CENTER>");

    show();

    return;
}
