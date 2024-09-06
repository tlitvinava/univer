#include <iostream>
#include <cmath>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 3\n";
}

int main() { //работает
    int m = 20, a = 0;
    long double h, b, y, x;
    const double PI = 3.141592653589793;
    title(-1);
    b = PI / 2;
    h = (b - a) / m;
    for (int i = 0; i <= m; i++) {
        x = a + i * h;
        y = sin(x) - cos(x);
        std::cout << y << '\n';
    }

}
