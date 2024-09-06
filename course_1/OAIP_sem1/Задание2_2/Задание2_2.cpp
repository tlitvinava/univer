#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian"); //работает
    double x, y, z;
    std::cout << "Введите первую сторону: ";
    std::cin >> x;
    std::cout << "Введите вторую сторону: ";
    std::cin >> y;
    std::cout << "Введите третью сторону: ";
    std::cin >> z;
    if (x + y > z && x + z > y && y + z > x) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
    return 0;
}
