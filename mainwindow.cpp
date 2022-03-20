#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "C:\opencv\build\include\opencv2\core.hpp"
#include "C:\opencv\build\include\opencv2\highgui\highgui.hpp"
#include "C:\opencv\build\include\opencv2\opencv.hpp"
#include "C:\opencv\build\include\opencv2\imgcodecs\imgcodecs.hpp"
#include "C:\opencv\build\include\opencv2\imgproc\imgproc.hpp"
#include <iostream>
#include <QTimer>
using namespace cv;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout), this, SLOT(DisplayImage()));
    Timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayImage()
{
    cv::Mat img;
    img = imread("Elrond.png");
    cv::resize(img, img, Size(512,384), 0 , 0, INTER_LINEAR);
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    ui->display_image->setPixmap(QPixmap::fromImage(imdisplay));
}

/*void MainWindow::on_btn_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Wybierz "), "", tr("Obrazy (*.png *.jpg *.jpeg"));
    cv::Mat image = cv::imread(filename.toStdString(), IMREAD_UNCHANGED);
    if (QString::compare(filename, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->lbl_image->width(), Qt::SmoothTransformation);
            image = image.scaledToHeight(ui->lbl_image->height(), Qt::SmoothTransformation);
            ui->lbl_image->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            // Error handling
        }
    }
}*/


void MainWindow::on_pushButton_clicked()
{

}

