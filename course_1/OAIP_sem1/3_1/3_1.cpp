/*#include <iostream>
#include <cmath>

int main() {//работает
    setlocale(LC_ALL, "Russian");
    int i;
    long long  a, b, N,N1;
    std::cout << "i: ";
    std::cin >> i;
    while (!(std::cin >> i)) {
        std::cin.clear(); // очистка ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорирование оставшегося ввода
        std::cout << "Неверный ввод. Попробуйте еще раз: ";
    }
    N = 0;
    while (i < 30) {
        if (i % 2 == 0) {
            a = i/2;
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
}*/

