#include "figuremodel.h"//основной класс от которого наследуются все фигуры

#include <QPainter>
#include <QPolygon>

FigureModel::FigureModel(QGraphicsItem *parent) : QGraphicsItem(parent) {
    setCenter = false;
}

void FigureModel::move(int dx, int dy) {
    int newX = centerX + dx, newY = centerY + dy;
}

void FigureModel::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (!setCenter) {
        centerX = event->scenePos().x();
        centerY = event->scenePos().y();
        setCenter = true;
    }
}

void FigureModel::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    mouseX = event->scenePos().x() - centerX;
    mouseY = event->scenePos().y() - centerY;

    update();
}

