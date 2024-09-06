#include <iostream>
#include <cmath>
#include <iomanip>

long double Distance(long double k, long double x, long double y) {
    long double r = 2 * 1e18;
    if (k < 0) {
        k = (-1) * k;
        x = (-1) * x;
        y = (-1) * y;
    }
    if (x >= 0 && x <= k) {
        r = std::min(r, fabsl(y));
        r = std::min(r, fabsl(y - k));
    }
    if (y >= 0 && y <= k) {
        r = std::min(r, fabsl(x));
        r = std::min(r, fabsl(x - k));
    }
    r = std::min(r, sqrtl(x * x + y * y));
    r = std::min(r, sqrtl((x - k) * (x - k) + (y * y)));
    r = std::min(r, sqrtl(x * x + (y - k) * (y - k)));
    r = std::min(r, sqrtl((x - k) * (x - k) + (y - k) * (y - k)));

    return r;
}

int main() {
    long double k, x, y;
    std::cin >> k >> x >> y;

    long double res = Distance(k, x, y);

    std::cout << std::setprecision(22) << res;

    return 0;
}

