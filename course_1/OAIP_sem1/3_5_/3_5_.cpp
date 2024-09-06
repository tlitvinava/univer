#include <iostream>
#include <cmath>

double factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

double taylor_series_sin(double x, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double term = pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
        sum += term;
    }
    return sum;
}

int main() {
    int n, m;
    std::cout << "Введите количество членов ряда: ";
    std::cin >> n;
    std::cout << "Введите количество чисел: ";
    std::cin >> m;



    for (int i = 0; i < m; i++) {
        double x;
        std::cout << "Введите число от 0.1 до 1: ";
        std::cin >> x;
        std::cout << "Значение функции, вычисленное с помощью ряда: " << taylor_series_sin(x, n) << std::endl;
        std::cout << "Значение функции, вычисленное с помощью стандартных функций: " << sin(x) << std::endl;
    }

    return 0;
}

/*#include<iostream>
#include<cmath>
using namespace std;

double Set(double x, int N)
{
    double y, S = 1, s = -1, f = 0;
    int n = 1;
    for (n = 1; n <= N; n++)
    {
        S *= (1 + x)*(1 + x);
        y = s * S / n;
        s = -s;
        f += y;
    }
    return f;
}
int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    int k, i = 1;
    cout << "k = ";
    cin >> k;
    double x;
    do
    {
        cout << i << " value of X in interval -2:-0.1 = ";
        cin >> x;
        if (x > -2 &&x < -0.1)
        {
            cout << x << " " << Set(x, n) << " " << log(1.0 / (2 + 2 * x + x*x)) << endl;
            i++;
        }
    } while (i <= k);

    return(0);
}*/
