#include <iostream>


const double PI = 3.141592653589793;
const double expp = 2.71828182845904523536;

long long fl(int n) {
    long long res = 1;
    for (int i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}


long double powr(long double r, long double expp) {
    long double res = 1;
    for (int i = 0; i < expp; i++) {
        res *= r;
    }

    return res;
}

long double s(long double x) {
    if (x > 0) {
        return 1;
    }
    else if (x < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

long double sinx(long double x) {

    if (x < 0) {
        x = -x;
    }

    while (x > 100000000 * PI) {
        x -= 100000000 * PI;
    }
    while (x > 1000000 * PI) {
        x -= 1000000 * PI;
    }
   
    while (x > 1000 * PI) {
        x -= 1000 * PI;
         
    }

        long n = 0;
    while (x >= 2 * PI) {
        x -= 2 * PI;
       
        n++;
    }



    long double res = x;

    for (int i = 1; i <= 10; i++) {
        long double frst = powr(x, 1 + 2 * i) / fl(1 + 2 * i);
        if (i % 2 == 1) {
            res -= frst;
        }
        else {
            res += frst;
        }
        
    }
    std::cout << x;

    return res;
}

long double cosx(long double x) {

    if (x < 0) {
        x = -x;
    }

    while (x > 100000000 * PI) {
        x -= 100000000 * PI;
    }

    while (x > 1000000 * PI) {
        x -= 1000000 * PI;
    }

    while (x > 1000 * PI) {
        x -= 1000 * PI;
       
    }

    long n = 0;

    while (x >= 2 * PI) {
        x -= 2 * PI;
        n++;
    }

 
    long double res = 1;
 
    for (int i = 1; i <= 10; i++) {
        long double frst = powr(x, 2 * i) / fl(2 * i);
        if (i % 2 == 1) {
            res -= frst;
        }
        else {
            res += frst;
        }
        
    }
  
    return res;
}


long double lod(long double x) {
    long double k = 0;
    while (x >= 2) {
        x /= expp;
        k++;
    }

    long double res = 0;
    for (int n = 1; n <= 10; ++n) {
        res += powr(-1, n + 1) / n * powr(x - 1, n);
    }

    return res + k;

}


void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 7\n";
}



int main() {
    setlocale(LC_ALL, "");
    long double x, a, b, c, min1;
    const double PI = 3.141592653589793;
    const double exp = 2.71828182845904523536;
    title(-1);
    char again = 'y';
    do {
    std::cout << "x: ";
    while (!(std::cin >> x)) {
        std::cin.clear(); // очистка ошибок
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // игнорирование оставшегося ввода
        std::cout << "Неверный ввод. Попробуйте еще раз: ";
    }

    std::cout << "sin x: " << sin(x) << std::endl;
    std::cout << "cox x: " << cos(x) << std::endl;

    a = sinx(x);
    std::cout << "sin x: " << sinx(x) << std::endl;
    b = cosx(x);
    std::cout << "cox x: " << cosx(x) << std::endl;
    c = lod(x);
    std::cout << "ln|x| : " << lod(x) << std::endl;

    
    min1 = std::min({ a, b, c });

    std::cout << "Минимальное значение: " << min1 << std::endl;
    std::cout << "Хотите ввести еще раз? ";
    std::cin >> again;
} while (again == 'y');

    return 0;
}
