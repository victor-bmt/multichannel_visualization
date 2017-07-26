#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QtWidgets>
#include <QtCharts>
#include "CustomChart.h"

using namespace QtCharts;

class ChartWindow : public QWidget
{
    Q_OBJECT

public:

    ChartWindow(QWidget* parent = 0);

    ~ChartWindow();

public slots:

    void slotShowCharts(QBitArray);

    void slotShowPoints(QByteArray);

private:

    QBitArray chartArray;

    QGridLayout* pMainLayout;

    CustomChart* pChart[8];

    QChartView* pChartView[8];

protected:

    virtual void closeEvent(QCloseEvent* event) Q_DECL_OVERRIDE;
};

#endif // CHARTWINDOW_H
