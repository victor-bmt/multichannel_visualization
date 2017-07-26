#ifndef CUSTOMCHART_H
#define CUSTOMCHART_H

#include <QtWidgets>
#include <QtCharts>

using namespace QtCharts;

class CustomChart : public QChart
{
    Q_OBJECT

public:

    CustomChart(QGraphicsItem* parent = 0);

    ~CustomChart();

public slots:

    // Рисуем точки, пришедшие с сигналом от COM-порта
    void slotXYfromCOM(char);

private:

    qreal X_coordinate;
    QLineSeries* series_old;
    QLineSeries* series_new;
    QValueAxis* pX;
    QValueAxis* pY;
    bool firstTimeFlag;
};

#endif // CUSTOMCHART_H
