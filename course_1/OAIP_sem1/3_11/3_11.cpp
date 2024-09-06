#include <iostream>
#include <cmath>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " <<var<< '\n';
    }
    std::cout << "Задание 1\n";
}

int main() {//работает
    setlocale(LC_ALL, "Russian");
    int i;
    long long  a, b, N, N1;
    i = 1;
    N = 0;
    title(-1);
    while (i < 31) {
        if (i % 2 == 0) {
            a = i / 2;
            b = pow(i, 3);
        }
        else {
            a = i;
            b = pow(i, 2);
        }

        N1 = (a - b) * (a - b);
        N = N + N1;
        i++;
    }
    std::cout << N;
}
