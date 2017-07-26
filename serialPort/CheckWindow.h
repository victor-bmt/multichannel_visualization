#ifndef CHECKWINDOW_H
#define CHECKWINDOW_H

#include <QtWidgets>

class CheckWindow : public QWidget
{
    Q_OBJECT

public:

    CheckWindow(QWidget* parent = 0);

    ~CheckWindow();

private:

    QBitArray checkedCharts;

    QVBoxLayout* pMainLayout;
    QHBoxLayout* pButtonsLayout;
    QGridLayout* pCheckLayout;

    QGroupBox* pGroupCheck;

    QCheckBox* pCheck[8];

    QPushButton* pOk;
    QPushButton* pExit;

private slots:

    void slotOKclicked();

signals:

    void signalChartsChecked(QBitArray);

    void signalNoChecks(void);
};

#endif // CHECKWINDOW_H
