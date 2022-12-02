#include <QApplication>
#include <QScreen>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w=new MainWindow();
    w->setGeometry(200,200,600,400);
    w->show();
    return a.exec();
}
