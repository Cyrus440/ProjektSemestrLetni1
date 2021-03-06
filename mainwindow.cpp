#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Wybierz "), "", tr("Obrazy (*.png *.jpg *.jpeg"));
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
}

