#ifndef FIGUREMODEL_H
#define FIGUREMODEL_H//основной класс от которого наследуются все фигуры

//#pragma once
#include <QGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QTransform>
#include <QPushButton>

class FigureModel : public QGraphicsItem {//наследуем все от график итем
private:
    bool setCenter = false;
    QTimer *timer;


public:
    int centerX = 0, centerY = 0;//создаем переменные для отслеживания движений мыши
    int mouseX, mouseY;
    double square=0;
    double perimetr=0;

    explicit FigureModel(QGraphicsItem *parent = nullptr);

    virtual void draw(QPainter *painter) = 0;//виртуальный метод - метод, который не прописывается в этом сппшнике, а только в наследниках(т к в этом классе мы пока что не знаем что рисовать и как)
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
        draw(painter);
    }
    QRectF boundingRect() const {
        // Возвращает ограничивающий прямоугольник
        return QRectF(-100,-100,625,450);
    }
    void move(int dx, int dy);//эти 3 функции для отслеживания мыши и что должно происходить в каждой из них
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual double calculateSquare()=0;//подсчет периметра и площади, но их реализацию я пока не писала
    virtual double calculatePerimetr()=0;


private slots://забей
    //void rotate();

};
#endif // FIGUREMODEL_H
