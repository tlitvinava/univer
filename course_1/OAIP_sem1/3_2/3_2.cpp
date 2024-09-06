#include <iostream>
#include <cmath>

int main(){//работает
    long double e, n, dn, sum;
    e = powl(10,-3);
    sum = 0;
    dn = 0;
    std::cout << "n: ";
    std::cin >> n;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверный ввод. Попробуйте еще раз: ";
        std::cin >> n;
    }
    do {
        dn = 1 / (powl(2, n)) + 1 / (powl(3, n));
        sum = sum + dn;
        n++;
    } while (dn >= e);
    std::cout << sum;
}