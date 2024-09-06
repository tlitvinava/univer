#ifndef STAR_H
#define STAR_H

#include "figuremodel.h"

class Star : public FigureModel{
public:
    int size = 5;
    explicit Star(int n, FigureModel *parent = nullptr);

    void draw(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double calculatePerimetr()override;
    double calculateSquare()override;
};

#endif // STAR_H
