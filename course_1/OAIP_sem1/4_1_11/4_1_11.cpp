﻿// 4_1_11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {

    long double a = 43;
 //   std::cin >> a;
    long double t = 235215125;
//    std::cin >> t;
    long double v0 = 23;
//    std::cin >> v0;

    long double s1 = v0 * t;
    long double s2 = t*t;
    long double s3 = a * pow(t, 2);
    long double s4 = (a * pow(t, 2)) / 2;
    long double s5 = v0 * t + (a * pow(t, 2)) / 2;



    long double s = v0 * t + (a * pow(t, 2)) / 2 + 0.5;
    std::cout << std::showpoint << std::setprecision(20) << s2;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
