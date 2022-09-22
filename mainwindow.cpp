#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpixmap.h"


extern char imageData[];
extern char jpgData[];


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap *pm = new QPixmap();

    //QByteArray imgBytes(imageData, 11913);
    QByteArray imgBytes(jpgData, 5447);

    bool isLoaded = pm->loadFromData(imgBytes, "JPEG");
    //bool isLoaded = pm->loadFromData(imgBytes, "PNG");

    if (isLoaded == true)
    {
        //JPG 196, 216
        //PNG 265, 314
        int w = ui->label->width();
        int h = ui->label->height();

        ui->label->setPixmap(pm->scaled(w, h, Qt::KeepAspectRatio));
        ui->label->setStyleSheet("background-color: black");
        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->show();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

