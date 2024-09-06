#include <iostream>
#include <cmath>

int main() {
    setlocale(LC_ALL, "Russian");//работает
    long double x1, y1, r, x2, y2, R;
    std::cout << "Введите координаты и радиус первого круга: ";
    std::cin >> x1 >> y1 >> r;
    std::cout << "Введите координаты и радиус второго круга: ";
    std::cin >> x2 >> y2 >> R;

    long double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); 

    if (d <= abs(R - r)) {
        if (R >= r) {
            std::cout << "Да" << std::endl;
        }
        else {
            std::cout << "Да, но справедливо обратное для двух фигур" << std::endl;
        }
    }
    else if (d < R + r) {
        std::cout << "Фигуры пересекаются" << std::endl;
    }
    else {
        std::cout << "Ни одно условие не выполнено" << std::endl;
    }

    return 0;
}

