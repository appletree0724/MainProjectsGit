#include "MainWindow.h"
#include <QApplication>
#include <QDebug>
#include <Qchart>
#include <QChartView>
#include <QScatterSeries>
#include <QScreen>
#include <QVector>
#include <QTime>

QT_CHARTS_USE_NAMESPACE

#include <vector>

#include "CustomerData.h"
#include "CustomerDataListModel.h"
#include "TimerTest.h"
#include "./XML/EquipmentInfo.h"
#include "./XML/EquipmentError.h"
#include "./XML/XmlManager_EquipmentInfo.h"
#include "./XML/DataAgent_Int.h"

#include "ChartForm.h"

using namespace std;

extern void Test();
extern void Clicked(const QPointF &point);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //    QScatterSeries *series = new QScatterSeries();
    //    series->setPen(QPen(Qt::blue,1,Qt::SolidLine)); //设置画笔
    //    //series->setColor(QColor(0,0,255));  //设置颜色

    //    QObject::connect(series, &QScatterSeries::clicked, &Clicked);

    //    *series << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
    //                << QPointF(16, 7) << QPointF(18, 5);  //添加数据

    //    QChart *chart = new QChart();
    //    chart->addSeries(series);
    //    chart->setTitle("Simple example");
    //    chart->createDefaultAxes();   //设置默认的坐标系，如果不设置程序是运行不了的
    //    chart->axisX()->setRange(0, 20);//设置图表坐标轴的范围，可以不设置，自动调节的
    //    chart->axisY()->setRange(0, 10);

    //    QChartView *chartView = new QChartView(chart);
    //    chartView->setRenderHint(QPainter::Antialiasing);  //抗锯齿渲染

//    QMainWindow window;
//    window.setCentralWidget(chartView);
//    window.resize(400, 300);
//    window.show();

    //MainWindow w;
    //w.setCentralWidget(chartView);
    //w.resize(800, 600);
    //w.show();

    ChartForm chartForm;
    chartForm.resize(800, 600);
    chartForm.show();

//    TimerTest timerTest;
//    timerTest.SendData(50);
//    timerTest.SendData(50);
//    timerTest.SendData(50);

    //vector<CustomerData> dataSource;
    //CustomerDataListModel model(dataSource);

    //qDebug() << "Finished!";

//    Test();

    return a.exec();
}

void Clicked(const QPointF &/*point*/)
{
//    qreal x = point.x();
//    qreal y = point.y();
}

void Test()
{
    QString xmlFilePath = "F:\\MyProjects\\DataChart\\Test\\EquipmentInfo.xml";

    XmlManager_EquipmentInfo xmlManager(xmlFilePath);

    EquipmentInfo equipmentInfo;
    equipmentInfo.Name = "Equipment";
    equipmentInfo.Address.B = 1;
    equipmentInfo.Address.L = 2;
    equipmentInfo.Address.H = 3;
    equipmentInfo.RandomError.Error_R = 4;
    equipmentInfo.RandomError.Error_A = 5;
    equipmentInfo.RandomError.Error_E = 6;
    equipmentInfo.SystemError.Error_R = 7;
    equipmentInfo.SystemError.Error_A = 8;
    equipmentInfo.SystemError.Error_E = 9;

    xmlManager.WriteToFile(equipmentInfo);
    qDebug() << "Xml has writen.";
}
