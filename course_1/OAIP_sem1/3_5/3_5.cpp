#include <iostream>
#include <cmath>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 5\n";
}


long double factorial(int n) { //работает
    if (n < 2) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() {

    setlocale(LC_ALL, "Russian");
    int n,m;
    long double s, y,x,s1;
    const double PI = 3.141592653589793;
    const double exp = 2.71828182845904523536;
    s = 1;
    title(3);
    char again = 'y';
    do{
    std::cout << "n: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cin.clear(); // очистка ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорирование оставшегося ввода
        std::cout << "Неверный ввод. Попробуйте еще раз: ";
    }
    std::cout << "Количество чисел: ";
    while (!(std::cin >> m) || m <= 0) {
        std::cin.clear(); // очистка ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорирование оставшегося ввода
        std::cout << "Неверный ввод. Попробуйте еще раз: ";
    }
    for (int i = 1; i <= m; i++) {
        std::cout << "x: ";
        while (!(std::cin >> x)||!(x>0.1&&x<1)) {
            std::cin.clear(); // очистка ошибок
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорирование оставшегося ввода
            std::cout << "Неверный ввод. Попробуйте еще раз: ";
        }

        for (int i = 0; i < n; i++) {
            s1 = (cos(PI / 4) / n * factorial(n - 1)) * x;
            s = s + s1;
        }
        y = powl(exp, x * cos(PI / 4)) * cos(x * sin(PI / 4));
        std::cout << s <<" "<< y<<'\n';
    }
    std::cout << "Хотите ввести еще раз? ";
    std::cin >> again;
    } while (again == 'y');

    return 0;
}
