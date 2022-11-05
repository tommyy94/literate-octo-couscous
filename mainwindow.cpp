#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpixmap.h"
#include "wireless.h"
#include "QDebug"


extern Wireless wl;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(&wl,
                     &Wireless::TransmitImageToGUI,
                     this,
                     &MainWindow::ReceiveImage);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::DisplayImage(Ui::MainWindow    *ui,
                              char              *img,
                              int                size)
{
    QPixmap *pm = new QPixmap();

    QByteArray imgBytes(img, size);

    bool isLoaded = pm->loadFromData(imgBytes, "JPG");

    if (isLoaded == true)
    {
        int w = ui->label->width();
        int h = ui->label->height();

        ui->label->setPixmap(pm->scaled(w, h, Qt::KeepAspectRatio));
        ui->label->setStyleSheet("background-color: black");
        ui->label->setAlignment(Qt::AlignCenter);
        ui->label->show();
    }
    else
    {
        qDebug() << "Image not loaded";
    }

    delete pm;
}


void MainWindow::ReceiveImage(char image[], int size)
{
    DisplayImage(ui, image, size);
}
