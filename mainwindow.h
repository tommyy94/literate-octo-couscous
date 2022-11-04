#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();  
    void DisplayImage(Ui::MainWindow *ui, char *image, int size);

public slots:
    void ReceiveImage(char image[], int size);

private:
    Ui::MainWindow  *ui;
    QObject          m_object;
};
#endif // MAINWINDOW_H
