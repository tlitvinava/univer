#include <iostream>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 4.1\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    long long  n,sum=0;//работает
    title(-1);
    char again = 'y';
   do{
        std::cout << "n: ";
        while (!(std::cin >> n) || n <= 0) {
            std::cin.clear(); // очистка ошибок
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорирование оставшегося ввода
            std::cout << "Неверный ввод. Попробуйте еще раз: ";
        }
        for (int i = 2; i <= n; i += 2) {
            sum = sum + i;
        }
        std::cout << sum<<'\n';
        std::cout << "Хотите ввести еще раз? ";
        std::cin >> again;
   } while (again == 'y');
    return 0;
}


