#include <iostream> 
#include <algorithm> 

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 3\n";
}

int main() {
        title(-1);
        int n, k;
        
            std::cout << "Введите размеры массива: " << '\n';
            std::cin >> n >> k;
            int** arr = new int* [n];
            for (int i = 0; i < n; ++i)
                arr[i] = new int[k];
            std::cout << "Введите элементы массива: " << '\n';
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < k; ++j)
                    std::cin >> arr[i][j];

            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    int sum_i = 0, sum_j = 0;
                    for (int l = 0; l < k; ++l) {
                        sum_i += arr[i][l];
                        sum_j += arr[j][l];
                    }
                    if (sum_i > sum_j) {
                        int* temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < k; ++j)
                    std::cout << arr[i][j] << ' ';
                std::cout << std::endl;
            }

            delete[] arr;

        return 0;
}


