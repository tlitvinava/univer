#include <iostream>

int main()
{
    setlocale(LC_ALL, "");//работает
    double x, y, max;
    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << "Введите второе число: ";
    std::cin >> y;

    max = (x > y) ? x : y;
    std::cout << "Максимальное число: " << max << std::endl;
    return 0;
}

