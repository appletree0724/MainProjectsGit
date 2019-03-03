#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QScreen>
#include <QScatterSeries>
#include <QPixmap>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->InitChartView();

    this->InitActions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QChartView * chartView = (QChartView *)this->centralWidget();

    switch (event->key()) {
    case Qt::Key_Plus:
        chartView->chart()->zoomIn();
        break;
    case Qt::Key_Minus:
        chartView->chart()->zoomOut();
        break;
    case Qt::Key_Left:
        chartView->chart()->scroll(-10, 0);
        break;
    case Qt::Key_Right:
        chartView->chart()->scroll(10, 0);
        break;
    case Qt::Key_Up:
        chartView->chart()->scroll(0, 10);
        break;
    case Qt::Key_Down:
        chartView->chart()->scroll(0, -10);
        break;
    default:
        break;
    }
}

void MainWindow::InitChartView()
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

    QChart *chart = new QChart();
    chart->setTheme(QChart::ChartThemeLight);
    chart->setAnimationOptions(QChart::AnimationOption::SeriesAnimations);
    chart->addSeries(series);
    //chart->setTitle("Simple example");
    chart->createDefaultAxes();   //设置默认的坐标系，如果不设置程序是运行不了的
    //chart->axisX()->setRange(0, 20);//设置图表坐标轴的范围，可以不设置，自动调节的
    //chart->axisY()->setRange(0, 10);

    QChartView * chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);  //抗锯齿渲染
    chartView->setRubberBand(QChartView::RubberBand::RectangleRubberBand);

    this->setCentralWidget(chartView);
}

void MainWindow::InitActions()
{
    QAction * openDataFile = new QAction("导入数据");
    connect(openDataFile, &QAction::triggered, this, this->LoadData);
    ui->mainToolBar->addAction(openDataFile);

    QAction * saveChart = new QAction("保存图表");
    saveChart->setShortcuts(QKeySequence::SaveAs);
    connect(saveChart, &QAction::triggered, this, this->SaveChart);
    ui->mainToolBar->addAction(saveChart);
}

void MainWindow::LoadData()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "选择数据文件", "/", "数据文件(*.dat);;所有文件(*.*)");

    for(int i = 0; i < fileNames.size(); ++i)
    {
        QString fileName = fileNames.at(i);

        this->DrawData(fileName);
    }
}

void MainWindow::DrawData(const QString &filePath)
{
    QFile data(filePath);

    if(!data.open(QFile::ReadOnly))
        return;

    QTextStream reader(data.readAll(), QIODevice::ReadOnly);
    QTextStream lineReader;

    shared_ptr<DataTable> dataTable = make_shared<DataTable>();

    while(!reader.atEnd())
    {
        DataList dataList;

        QString dataS = reader.readLine();
        lineReader.setString(&dataS, QIODevice::ReadOnly);

        while(!lineReader.atEnd())
        {
            double data;
            lineReader >> data;
            dataList.push_back(data);
        }

        dataTable->push_back(dataList);
    }

    this->dataMap.insert(filePath, dataTable);
}

void MainWindow::SaveChart()
{
    QString chartSavePath = "F:\\MyProjects\\DataChart\\Test\\Chart_1.png";

    //QChartView * chartView = (QChartView*)this->centralWidget();

    QScreen * screen = QGuiApplication::primaryScreen();
    QPoint p = this->centralWidget()->pos();
    int w = this->centralWidget()->width();
    int h = this->centralWidget()->height();
    screen->grabWindow(this->chartView->winId(), p.x(), p.y(), w, h).save(chartSavePath, "PNG");
}
