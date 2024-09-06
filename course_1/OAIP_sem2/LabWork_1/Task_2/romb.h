#ifndef ROMB_H
#define ROMB_H

#include "figuremodel.h"

class Romb : public FigureModel{
public:
    explicit Romb(FigureModel *parent = nullptr);

    void draw(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double calculatePerimetr()override;
    double calculateSquare()override;
};

#endif // ROMB_H
