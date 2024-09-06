#include <iostream>

int main() {
    int n;
    std::cout << "Введите количество строк: ";
    std::cin >> n;

    std::string* matrix = new std::string[n];
    std::cout << "Введите строки матрицы:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> matrix[i];
    }

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += (int)matrix[i][j];
        }

        if (sum % 2 == 0) {
            int j = 0, k = matrix[i].size() - 1;
            while (j < k) {
                std::swap(matrix[i][j], matrix[i][k]);
                ++j;
                --k;
            }
        }
    }

    std::cout << "Полученная матрица:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << matrix[i] << '\n';
    }

    delete[] matrix;
    return 0;
}
