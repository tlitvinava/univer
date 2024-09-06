#include <iostream>

int main() {
    long long x, y, k; //работает
    long double a, b, c;
    std::cin >> x;
    std::cin >> y;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> k;
    if (x > y) {
        y = 0;
    }
    else if (x < y) {
        x = 0;
    }
    else if (x == y) {
        x = 0;
        y = 0;
    }
    std::cout << x << " " << y << std::endl;

    if (a > b && a > c) {
        a = a - k;
    }
    else if (b > a && b > c) {
        b = b - k;
    }
    else if (c > b && c > a) {
        c = c - k;
    }

    std::cout << a << " " << b << " " << c;
    return 0;
}
