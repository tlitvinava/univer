#include <iostream> 
#include <cmath> //работает

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 6\n";
}

double f(double x) {
    return asin(x) - x + pow(x, 2) - 1; 
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    double s, min, res, x, r;
    title(3);

    char again = 'y';
    do {
    std::cout << "Введите количество частей: ";

    while (!(std::cin >> n) || n <= 0) {
        std::cin.clear(); // очистка ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорирование оставшегося ввода
        std::cout << "Неверный ввод. Попробуйте еще раз: ";
    }

    s = 1.0 / n;
    min = fabsl(f(0)); 
    res = 0; 


    for (int i = 0; i <= n; i++) { 
        x = i * s;
        r = fabsl(f(x)); 

        if (r < min) { 
            min = r; 
            res = x;
        }
    }

    std::cout << "Корень уравнения: " << res << std::endl;
    std::cout << "Хотите ввести еще раз? ";
    std::cin >> again;
    } while (again == 'y');

    return 0;
}

