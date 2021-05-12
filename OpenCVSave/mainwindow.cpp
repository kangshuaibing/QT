#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    time = new QTimer(this);
    time->start(10);

    connect(time, SIGNAL(timeout()), this, SLOT(readFrame()));

    counter = 0;

    cap.open(0);
    write.open("test.avi", 1, 25.0, Size(640, 480), true); //保存在当前目录，名为test的AVI视频
}

MainWindow::~MainWindow()
{
    delete ui;
}

//读取摄像头视频并保存
void MainWindow::readFrame()
{
   cap >> frame;
   counter++;
   if(frame.empty())
   {
        qDebug()<<"frame is empty";
        cap.release();
   }

   if (counter <= 100)  //只保存100帧
   {
       qDebug() << "counter = " << counter;
       write.write(frame);  //保存视频帧
   }
   ui->label->setPixmap(QPixmap::fromImage(mat2QImage(frame)));
}

//Mat to QImage
QImage MainWindow::mat2QImage(cv::Mat cvImg)
{
    QImage qImg;

    if (cvImg.channels() == 3)                             //3 channels color image
    {
        cv::cvtColor(cvImg, cvImg, CV_BGR2RGB);
        qImg = QImage((const unsigned char*)(cvImg.data),
                      cvImg.cols, cvImg.rows,
                      cvImg.cols*cvImg.channels(),
                      QImage::Format_RGB888);
    }

    else if (cvImg.channels() == 1)                    //grayscale image
    {
        qImg = QImage((const unsigned char*)(cvImg.data),
                      cvImg.cols, cvImg.rows,
                      cvImg.cols*cvImg.channels(),
                      QImage::Format_Indexed8);
    }

    else
    {
        qImg = QImage((const unsigned char*)(cvImg.data),
                      cvImg.cols, cvImg.rows,
                      cvImg.cols*cvImg.channels(),
                      QImage::Format_RGB888);
    }
    return qImg;
}
