#include <QApplication>
#include "mainwindow.h"
#include <QIcon>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(500, 300); // Lock window size to 500x300
    w.show();
    return a.exec();
}
