#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian"); //работает
    long double a, b, c, x;
    int N, y;
    std::cout << "Введите a: ";
    std::cin >> a;
    std::cout << "Введите b: ";
    std::cin >> b;
    std::cout << "Введите c: ";
    std::cin >> c;
    std::cout << "Введите N: ";
    std::cin >> N;

    switch (N) { 

    case 2:
            y = (b * c) - (a * a);
            std::cout << y;
            break;
    case 56:
            y = b * c;
            std::cout << y;
            break;
    case 7:
            y = (a * a) + c;
            std::cout << y;
            break;
    case 3:
            y = a - (b * c);
            std::cout << y;
            break;

        default:
            x = a + b;
            y = x * x * x;;
            std::cout << y;
        break;
    }
    return 0;
}

