#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>

#include "opencv2/opencv.hpp"

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QImage mat2QImage(cv::Mat cvImg);

private slots:
    void readFrame();

private:
    Ui::MainWindow *ui;

    QTimer *time;

    Mat frame;

    VideoCapture cap;
    VideoWriter write;

    int counter;  //记录帧数
};

#endif // MAINWINDOW_H
