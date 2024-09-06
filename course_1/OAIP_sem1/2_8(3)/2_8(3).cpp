#include <iostream>
#include<cmath>


int main() {
    setlocale(LC_ALL, "");
    long double  p, q, x, D, Q, x1, x2, x3, w, z, m;
    std::cout << "p,q:  ";
    std::cin >> p >> q;
    const double PI = 3.141592653589793;
    x = 1;


    // Решение уравнения вида x^3 + px + q = 0 

    if (p != 0 && q != 0) {
        Q = ((q * q) / 4) + ((p * p * p) / 27);
        if (Q >= 0) {
            x1 = cbrtl(((-q) / 2) + sqrtl(Q)) + cbrtl(((-q) / 2) - sqrtl(Q));
            std::cout << "Корень уравнения: " << x1 << "\n";
        }
        if (Q < 0) {
            w = (1 / 3.0) * acosl(((3.0 * q) / (2.0 * p)) * sqrtl((-3.0) / p));
            x1 = 2.0 * sqrtl((-p) / 3.0) * cosl(w);
            z = w - ((2.0 * PI) / 3.0);
            x2 = 2.0 * sqrtl((-p) / 3.0) * cosl(z);
            m = w - ((4.0 * PI) / 3.0);
            x3 = 2.0 * sqrtl((-p) / 3.0) * cosl(m);
            std::cout << "Корни уравнения: " << x1 << ", " << x2 <<", "<<x3<<"\n";
        }
    }
    if (p == 0 && q != 0) {
        x1 = cbrtl(-q);
        std::cout << "Корень уравнения: " << x1 << "\n";
    }
    if (p != 0 && q == 0) {
        x1 = 0;
        if ((-p) > 0) {
            x2 = sqrtl(-p);
            x3 = (-1) * sqrtl(-p);
            std::cout << "Корни уравнения: " << x1 << ", " << x2 << ", " << x3 << "\n";
        }
        else {
            std::cout << "Корень уравнения: " << x1 << "\n";
        }
    }
    if (p == 0 && q == 0) {
        std::cout << "Корень уравнения: " << 0 << "\n";
    }

    return 0;

}
