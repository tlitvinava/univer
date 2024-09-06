#include<iostream>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 4.2\n";
}
int main() {
    setlocale(LC_ALL, "Russian");//работает
    char again = 'y';
    int n, sum = 0;
    title(-1);
    do {
        std::cout << "Введите число: ";
        while (!(std::cin >> n) || n <= 0) {
            std::cin.clear(); // очистка ошибок
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорирование оставшегося ввода
            std::cout << "Неверный ввод. Попробуйте еще раз: ";
        }
        n = n / 2;
        sum = n * (n + 1);
        std::cout << sum << std::endl;
        std::cout << "Хотите ввести еще раз? ";
        std::cin >> again;
    } while (again == 'y');
    return 0;
}

