#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])//тут можно ниче не менять, тут создается само окно и если убрать код то все поломается
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.showMaximized();
    w.showFullScreen();//единственное что я меняла, окно сразу развертывается на весь экран


    return a.exec();
}
