#include <iostream>
#include <cmath>
int main()
{
    setlocale(LC_ALL, "Russian"); //работает
    long double R, P, Q, r, S;
    std::cout << "Введите радиус: ";
    std::cin >> R;
    std::cout << "Введите сторону: ";
    std::cin >> P;
    std::cout << "Введите угол: ";
    std::cin >> Q;

    Q = Q * 3.14 / 180.0;
    S = P * P * sin(Q);
    r = S / (2 * P);
    if (r >= R) {
        std::cout << "Сможет";
    }
    else {
        std::cout << "Не сможет";
    }

        return 0;
}
