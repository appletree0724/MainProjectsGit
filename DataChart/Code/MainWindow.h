#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChart>
#include <QChartView>
#include <QFileDialog>
#include <QMap>
#include <QList>
#include <memory>

QT_CHARTS_USE_NAMESPACE

using namespace  std;

typedef QList<double> DataList;
typedef QList<DataList> DataTable;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent * event);

private:
    // 初始化图表
    void InitChartView();

    // 初始化命令
    void InitActions();

    // 装载数据
    void LoadData();

    //  绘制数据
    void DrawData(const QString& filePath);

    // 保存图表
    void SaveChart();

private:
    Ui::MainWindow *ui;

    QChartView * chartView;

    QMap<QString, shared_ptr<DataTable>> dataMap;
};

#endif // MAINWINDOW_H
