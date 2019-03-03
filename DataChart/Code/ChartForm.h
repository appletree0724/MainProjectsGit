#ifndef CHARTFORM_H
#define CHARTFORM_H

#include <QtWidgets>
#include <QWidget>
#include <QChartView>
#include <QChart>
#include <QMouseEvent>


namespace Ui {
class ChartForm;
}

QT_CHARTS_USE_NAMESPACE

class ChartForm : public QChartView
{
    Q_OBJECT

public:
    explicit ChartForm(QWidget *parent = 0);
    ~ChartForm();

protected:
    void mousePressEvent(QMouseEvent * event) override;

private:
    void InitChartView();

    void InitChart();

private:
    Ui::ChartForm *ui;
};

#endif // CHARTFORM_H
