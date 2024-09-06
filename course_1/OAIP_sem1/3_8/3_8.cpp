#include <iostream>
#include <cmath>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 8\n";
}

bool f(int num) { //работает
    int num1, r, n = 0, res = 0;

    num1 = num;

    while (num1 != 0) {
        num1 /= 10;
        ++n;
    }

    num1 = num;

    while (num1 != 0) {
        r = num1 % 10;
        res =res+ pow(r, n);
        num1 /= 10;
    }

    return (res == num);
}

int main() {
    int num;
    title(-1);
    char again = 'y';
    do {
    std::cout << "Введите n:  ";
    while (!(std::cin >> num) || num <= 0) {
        std::cin.clear(); // очистка ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорирование оставшегося ввода
        std::cout << "Неверный ввод. Попробуйте еще раз: ";
    }

    for (int i = 1; i <= num; i++) {
        if (f(i))
            std::cout << i << std::endl;
    }
    std::cout << "Хотите ввести еще раз? ";
    std::cin >> again;
    } while (again == 'y');


    return 0;
}
