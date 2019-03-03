#include "ChartForm.h"
#include "ui_ChartForm.h"

#include <QScatterSeries>

ChartForm::ChartForm(QWidget *parent) :
    QChartView(parent),
    ui(new Ui::ChartForm)
{
    ui->setupUi(this);

    this->InitChartView();

    this->InitChart();
}

ChartForm::~ChartForm()
{
    delete ui;
}

void ChartForm::mousePressEvent(QMouseEvent *event)
{

}

void ChartForm::InitChartView()
{
    QChart *chart = new QChart();
    chart->setTheme(QChart::ChartThemeLight);
    chart->setAnimationOptions(QChart::AnimationOption::SeriesAnimations);
    //chart->setTitle("Simple example");
    //chart->createDefaultAxes();   //设置默认的坐标系，如果不设置程序是运行不了的
    //chart->axisX()->setRange(0, 20);//设置图表坐标轴的范围，可以不设置，自动调节的
    //chart->axisY()->setRange(0, 10);

    this->setChart(chart);

    this->setRenderHint(QPainter::Antialiasing);  //抗锯齿渲染
    this->setRubberBand(QChartView::RubberBand::RectangleRubberBand);
}

void ChartForm::InitChart()
{
    QScatterSeries *series = new QScatterSeries();
    series->setUseOpenGL();
    series->setName("Test");
    series->setMarkerSize(10);
    //series->setName("Test");
    //series->setPen(QPen(Qt::blue,1,Qt::SolidLine)); //设置画笔
//    //series->setColor(QColor(0,0,255));  //设置颜色

    *series << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
                << QPointF(16, 7) << QPointF(18, 5);  //添加数据

    this->chart()->addSeries(series);
    this->chart()->createDefaultAxes();
}
