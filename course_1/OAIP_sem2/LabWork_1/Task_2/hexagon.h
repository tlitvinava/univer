#ifndef HEXAGON_H
#define HEXAGON_H

#include "figuremodel.h"

class Hexagon : public FigureModel{
public:
    explicit Hexagon(FigureModel *parent = nullptr);

    void draw(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
    double calculatePerimetr()override;
    double calculateSquare()override;
};

#endif // HEXAGON_H
