#include <iostream>
#include <cmath>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 1\n";
}

int main() {
    title(-1);
    long long n, i, j, n1, down, up, d;
    std::cin >> n;

    n1 = std::ceil(std::sqrt(n));
    down = (n1 - 1) * (n1 - 1) + 1;
    up = n1 * n1;
    d = down + (up - down) / 2;

    if (n == 1) {
        i = 0;
        j = 0;
    }
    else if (n == d) {
        i = n1 - 1;
        j = n1 - 1;
    }
    else if (n < d) {
        i = n - down;
        j = n1 - 1;
    }
    else {
        i = n1 - 1;
        j = up - n;
    }

    std::cout << i << " " << j << "\n";
    return 0;
}