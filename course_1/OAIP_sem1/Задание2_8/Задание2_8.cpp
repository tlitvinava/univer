#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian");
    long double a, b, c, x, D, x1, x11, x22, x2, t, t1, t2,xt;
    std::cout << "a,b,c:  ";
    std::cin >> a >> b >> c;
    x = 1;

    if ((b == 0 && c == 0 && a!=0)||(a==1&&b==1&&c==0)||(b != 0 && c == 0 && a == 0)||(b != 0 &&b<0&& c == 0 && a != 0&&a<0)) {
        std::cout << "Корень уравнения: 0";
    }
    else if (a == 0 && b!=0 && c!=0) {
        xt = (-c) / b;
        x1 = sqrt(xt);
        if (xt < 0) {
            std::cout << "Уравнение не имеет решений\n";
        }
        else {
            x2 = -x1;
            if (x1 == 0 || x2 == 0) {
                x1 = fabsl(x1);
                std::cout << "Корень уравнения: " << x1;
            }
            else {
                std::cout << "Корни уравнения: " << x1 << " " << x2;
            }
        }
    }
    else if ((a == 0 && b == 0 && c == -1) || (a == 0 && b == 0 && c == 1) || (a == 1 && b == 1 && c == 1)) {
        std::cout << "Уравнение не имеет решений\n";
    }
    else if ((a == 0 && b == 0 && c != 0)||(a == 0 && b == 0 && c == 0)) {
        std::cout << "Бесконечное количество решений";
    }
    else {

        // Решение уравнения вида ax^4 + bx^2 + c = 0
        t = x * x;
        D = b * b - 4 * a * c;
        if (D < 0) {
            std::cout << "Уравнение не имеет решений\n";
        }
        else if (D == 0) {
            t1 = -b / (2 * a);
            x1 = sqrt(t1);
            std::cout << "Корень уравнения: " << x1;
        }
        else {
            t1 = (-b + sqrt(D)) / (2 * a);
            t2 = (-b - sqrt(D)) / (2 * a);
            if (t1 < 0) {
                x2 = sqrt(t2);
                x22 = -sqrt(t2);
                if (x2 == (-0) || x22 == (-0)) {

                    if (x2 == (-0)) {
                        x2 = fabsl(x2);
                    }
                    if (x22 == (-0)) {
                        x22 = fabsl(x22);
                    }
                }
                if (x2 == x22) {
                    std::cout << "Корень уравнения: " << x22 << "\n";
                }
                else {
                    std::cout << "Корни уравнения: " << x2 << ", " << x22 << "\n";
                }
            }
            else if (t2 < 0) {

                x1 = sqrt(t1);
                x11 = -sqrt(t1);
                if (x1 == (-0) || x11 == (-0)) {

                    if (x1 == (-0)) {
                        x1 = fabsl(x1);
                    }
                    if (x11 == (-0)) {
                        x11 = fabsl(x11);
                    }

                }
                if (x1 == x11) {
                    std::cout << "Корень уравнения: " << x11 << "\n";
                }
                else {
                    std::cout << "Корни уравнения: " << x1 << ", " << x11 << "\n";
                }
            }
            else {

                x1 = sqrt(t1);
                x11 = -sqrt(t1);
                x2 = sqrt(t2);
                x22 = -sqrt(t2);
                if (x1 == (-0) || x11 == (-0) || x2 == (-0) || x22 == (-0)) {

                    if (x1 == (-0)) {
                        x1 = fabsl(x1);
                    }
                    if (x11 == (-0)) {
                        x11 = fabsl(x11);
                    }
                    if (x2 == (-0)) {
                        x2 = fabsl(x2);
                    }
                    if (x22 == (-0)) {
                        x22 = fabsl(x22);
                    }

                    if (x1 == x11) {
                        std::cout << "Корни уравнения: " << x1 << "," << x2 << ", " << x22 << "\n";
                    }
                    else if (x2 == x22) {
                        std::cout << "Корни уравнения: " << x1 << "," << x11 << "," << x2 << "\n";
                    }

                }
                else {
                    std::cout << "Корни уравнения: " << x1 << ", " << x11 << "," << x2 << ", " << x22 << "\n";
                }
            }
        }

       
    }

    return 0;
}

