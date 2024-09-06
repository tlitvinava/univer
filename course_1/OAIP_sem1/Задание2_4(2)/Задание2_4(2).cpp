#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");//работает
    double x, y, max;
    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << "Введите второе число: ";
    std::cin >> y;

    bool xmax = (x > y);
    max = (xmax) ? x : y;
    std::cout << "Максимальное число: " << max << std::endl;

    return 0;
}