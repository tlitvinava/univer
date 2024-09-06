#ifndef ROCKET_H
#define ROCKET_H
#include "Line.h"//подключаем хедр линии т к тут происходит наследование

class Rocket : public Line {//это хедр самой ракеты, тут в этой строке создаем и называем класс ракеты и указываем наследование от линии и все функции что имеет линия переходят к ракете как например движение
public:
    bool engineStarted = false;
    Rocket();
    void paintEvent(QPaintEvent *event);
    void drawRocket(QPainter *painter);
    void drawFlame(QPainter *painter);
};

#endif // ROCKET_H
