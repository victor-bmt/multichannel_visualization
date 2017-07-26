#include "ChartWindow.h"

ChartWindow::ChartWindow(QWidget* parent /*= 0*/) :
    QWidget(parent)
{
    for (int i = 0; i < 8; ++i)
    {
        pChart[i] = nullptr;
        pChartView[i] = nullptr;
    }

    pMainLayout = nullptr;
}

ChartWindow::~ChartWindow()
{
    for (int i = 0; i < 8; ++i)
    {
        if (pChart[i])
            delete pChart[i];

        if (pChartView[i])
            delete pChartView[i];
    }

    if (pMainLayout)
        delete pMainLayout;
}

/*virtual*/ void ChartWindow::closeEvent(QCloseEvent* event) /*Q_DECL_OVERRIDE*/
{
    if (isVisible())
        hide();

    event->ignore();

    return;
}

void ChartWindow::slotShowCharts(QBitArray arr)
{
    chartArray.swap(arr);

    int counter = 0;

    for (int i = 0; i < chartArray.size(); ++i)
        if (chartArray[i])
        {
            ++counter;

            if (pChartView[i])
                delete pChartView[i];

            pChart[i] = new CustomChart;

            pChartView[i] = new QChartView (pChart[i], this);
            pChartView[i]->setRenderHint(QPainter::Antialiasing);
            pChartView[i]->setMinimumSize(320, 240);
        }

    if (pMainLayout)
        delete pMainLayout;

    pMainLayout = new QGridLayout(this);
    pMainLayout->setSpacing(5);

    switch (counter)
    {
    case(1):
    {
        int i = 0;
        while(chartArray[i] != true)
            ++i;

        pMainLayout->addWidget(pChartView[i], 0, 0);
        break;
    }

    case(2):
    {
        int k = 0;
        for(int i = 0; i < chartArray.size(); ++i)
        {
            if (chartArray[i] == true)
            {
                if (k == 0)
                    pMainLayout->addWidget(pChartView[i], 0, 0);
                else if (k == 1)
                    pMainLayout->addWidget(pChartView[i], 1, 0);

                ++k;
            }
        }

        break;
    }

    case(3):
    {
        int k = 0;
        for(int i = 0; i < chartArray.size(); ++i)
        {
            if (chartArray[i] == true)
            {
                if (k == 0)
                    pMainLayout->addWidget(pChartView[i], 0, 0);
                else if (k == 1)
                    pMainLayout->addWidget(pChartView[i], 1, 0);
                else if (k == 2)
                    pMainLayout->addWidget(pChartView[i], 2, 0);

                ++k;
            }
        }

        break;
    }

    case(4):
    {
        int k = 0;
        for(int i = 0; i < chartArray.size(); ++i)
        {
            if (chartArray[i] == true)
            {
                if (k == 0)
                    pMainLayout->addWidget(pChartView[i], 0, 0);
                else if (k == 1)
                    pMainLayout->addWidget(pChartView[i], 1, 0);
                else if (k == 2)
                    pMainLayout->addWidget(pChartView[i], 0, 1);
                else if (k == 3)
                    pMainLayout->addWidget(pChartView[i], 1, 1);

                ++k;
            }
        }

        break;
    }

    case(5):
    {
        int k = 0;
        for(int i = 0; i < chartArray.size(); ++i)
        {
            if (chartArray[i] == true)
            {
                if (k == 0)
                    pMainLayout->addWidget(pChartView[i], 0, 0);
                else if (k == 1)
                    pMainLayout->addWidget(pChartView[i], 1, 0);
                else if (k == 2)
                    pMainLayout->addWidget(pChartView[i], 0, 1);
                else if (k == 3)
                    pMainLayout->addWidget(pChartView[i], 1, 1);
                else if (k == 4)
                    pMainLayout->addWidget(pChartView[i], 2, 0, 1, 2);

                ++k;
            }
        }

        break;
    }

    case(6):
    {
        int k = 0;
        for(int i = 0; i < chartArray.size(); ++i)
        {
            if (chartArray[i] == true)
            {
                if (k == 0)
                    pMainLayout->addWidget(pChartView[i], 0, 0);
                else if (k == 1)
                    pMainLayout->addWidget(pChartView[i], 1, 0);
                else if (k == 2)
                    pMainLayout->addWidget(pChartView[i], 2, 0);
                else if (k == 3)
                    pMainLayout->addWidget(pChartView[i], 0, 1);
                else if (k == 4)
                    pMainLayout->addWidget(pChartView[i], 1, 1);
                else if (k == 5)
                    pMainLayout->addWidget(pChartView[i], 2, 1);

                ++k;
            }
        }

        break;
    }

    case(7):
    {
        int k = 0;
        for(int i = 0; i < chartArray.size(); ++i)
        {
            if (chartArray[i] == true)
            {
                if (k == 0)
                    pMainLayout->addWidget(pChartView[i], 0, 0);
                else if (k == 1)
                    pMainLayout->addWidget(pChartView[i], 1, 0);
                else if (k == 2)
                    pMainLayout->addWidget(pChartView[i], 2, 0);
                else if (k == 3)
                    pMainLayout->addWidget(pChartView[i], 0, 1);
                else if (k == 4)
                    pMainLayout->addWidget(pChartView[i], 1, 1);
                else if (k == 5)
                    pMainLayout->addWidget(pChartView[i], 2, 1);
                else if (k == 6)
                    pMainLayout->addWidget(pChartView[i], 3, 0, 1, 2);

                ++k;
            }
        }

        break;
    }

    default:
    {
        for (int i = 0; i < chartArray.size(); ++i)
        {
            if (i == 0)
                pMainLayout->addWidget(pChartView[i], 0, 0);
            else if (i == 1)
                pMainLayout->addWidget(pChartView[i], 1, 0);
            else if (i == 2)
                pMainLayout->addWidget(pChartView[i], 2, 0);
            else if (i == 3)
                pMainLayout->addWidget(pChartView[i], 3, 0);
            else if (i == 4)
                pMainLayout->addWidget(pChartView[i], 0, 1);
            else if (i == 5)
                pMainLayout->addWidget(pChartView[i], 1, 1);
            else if (i == 6)
                pMainLayout->addWidget(pChartView[i], 2, 1);
            else if (i == 7)
                pMainLayout->addWidget(pChartView[i], 3, 1);
        }
    }
    }

    setLayout(pMainLayout);

    showMaximized();
}

void ChartWindow::slotShowPoints(QByteArray byteArray)
{
    for (int i = 0; i < 8; ++i)
    {
        if (chartArray[i])
            pChart[i]->slotXYfromCOM(byteArray[i]);
    }

    return;
}
