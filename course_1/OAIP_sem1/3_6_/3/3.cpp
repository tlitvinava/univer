#include <iostream>
#include <cmath>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 2\n";
}

int main() {//работает  
    long double e, n, dn, sum;
    title(-1);
    e = powl(10, -3);
    sum = 0;
    dn = 0;
    n = 1;
    do {
        dn = 1 / (powl(2, n)) + 1 / (powl(3, n));
        sum = sum + dn;
        n++;
    } while (dn >= e);
    std::cout << sum;
}