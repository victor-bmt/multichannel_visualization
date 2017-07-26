#include "CustomChart.h"

CustomChart::CustomChart(QGraphicsItem* parent /*= 0*/) :
    QChart(parent), X_coordinate(0), firstTimeFlag(true)
{
    setTheme(QChart::ChartThemeDark);

    pX = new QValueAxis;
    pX->setRange(0.0, 640.0);

    pY = new QValueAxis;
    pY->setRange(0, 270);

    setAxisX(pX);
    setAxisY(pY);

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(1);

    series_old = new QLineSeries;
    series_old->setPen(pen);

    addSeries(series_old);

    series_old->attachAxis(pX);
    series_old->attachAxis(pY);

    series_new = new QLineSeries;
    series_new->setPen(pen);

    addSeries(series_new);

    series_new->attachAxis(pX);
    series_new->attachAxis(pY);
}

CustomChart::~CustomChart()
{
    delete series_new;
    delete series_old;
    delete pY;
    delete pX;
}

// Новый график рисуется поверх старого, поэтому
// используется два множества точек series_old и series_new
// Иначе последняя точка будет соединяться с первой, перечеркивая
// весь график
void CustomChart::slotXYfromCOM(char ch)
{
    if ((X_coordinate == 0) && !firstTimeFlag)
        series_old->removePoints(0, 5);

    else if (X_coordinate <= 630 && !firstTimeFlag)
        series_old->remove(0);

    qreal Y_coordinate = ch & 255;

    /*qDebug() << "x = " << X_coordinate
             << "y = " << Y_coordinate;*/

    series_new->append(X_coordinate, Y_coordinate);


    X_coordinate += 2;
    if (X_coordinate > 640)
    {
        X_coordinate = 0;
        firstTimeFlag = false;

        series_old->clear();
        QLineSeries* pDummy = series_new;
        series_new  = series_old;
        series_old = pDummy;
    }

    return;
}
