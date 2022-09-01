#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpixmap.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pm = QPixmap(QString(":/images/capture.png"));
    if (pm.isNull() == true)
    {
        qDebug("Image not found!\r\n");
    }
    else
    {
        int w = ui->label->width();
        int h = ui->label->height();

        ui->label->setPixmap(pm.scaled(w, h, Qt::KeepAspectRatio));
        ui->label->setStyleSheet("background-color: black");
        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

