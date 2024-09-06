#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLineEdit>

#include"figuremodel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    FigureModel *lastFigureModel=nullptr;
private slots:

    void updateAreaDisplay(QString newArea);
    void updatePerimetrDisplay(QString newP);
    void updateCenterDisplay(QString newX, QString newY);
    void infoFigure(FigureModel* figure);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;  // Объявление scene
    QLineEdit *lineEdit;


};
#endif // MAINWINDOW_H
