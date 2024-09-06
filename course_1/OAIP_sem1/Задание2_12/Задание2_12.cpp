#include <iostream>

int main() {
    double a, b, c, x, y;//работает
    std::cin >> a >> b >> c >> x >> y;
    if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0) {
        std::cout << "Incorrect input" << std::endl;
        return 0;
    }
    if ((a <= x && (b <= y || c <= y)) || (b <= x && (a <= y || c <= y)) || (c <= x && (a <= y || b <= y))) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
