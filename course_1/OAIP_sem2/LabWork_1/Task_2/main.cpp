#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <figuremodel.h>

int main(int argc, char *argv[])//ниче не меняем
{
    QApplication a(argc, argv);
    MainWindow w;
        //view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    w.show();
    return a.exec();
}
