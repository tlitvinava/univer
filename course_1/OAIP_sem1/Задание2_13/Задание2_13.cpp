#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian"); //работает 
    long long k;
    std::cin >> k;
    long long l = k % 10;
    long long m = k % 100;
    if (k>1&&k<5 || l > 1 && l < 5 && (m < 11 || m>15)) {
        std::cout << "Мы нашли " << k << " гриба в лесу";
    }
    else if (l == 1 && m != 11 || k == 1) {
        std::cout << "Мы нашли " << k << " гриб в лесу";
    }
    else if ((l >= 5 && l <= 9) || k >= 11 && k <= 15 || l == 0 || m >= 11 && m <= 15) {
        std::cout << "Мы нашли " << k << " грибов в лесу";
    }
    return 0;
}
