#include <iostream>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 9\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n,a0,q,sum;
    q = -2;
    title(-1);
    char again = 'y';
    do {
    std::cout << "n: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cin.clear(); // очистка ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорирование оставшегося ввода
        std::cout << "Неверный ввод. Попробуйте еще раз: ";
    }
    std::cout << "a0: ";
    while (!(std::cin >> a0)) {
        std::cin.clear(); // очистка ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорирование оставшегося ввода
        std::cout << "Неверный ввод. Попробуйте еще раз: ";
    }
   
        sum = a0 * (pow(q, (n-1))-1) / (q-1);

    std::cout << sum << std::endl;
    std::cout << "Хотите ввести еще раз? ";
    std::cin >> again;
} while (again == 'y');

    return 0;
}


