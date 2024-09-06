#include <iostream>

int main() {
    long double a, b, c, d, z;//работает
    std::cin >> a >> b >> c >> d;

    if (c >= d && a < d) {
        z = a + (b / c);
        std::cout << z;
    }
    else if (c < d && a >= d) {
        z = a - (b / c);
        std::cout << z;
    }
    else if (c == 0) {
        std::cout << "ERROR";
    }
    else {
        std::cout << 0;
    }
    return 0;
}
