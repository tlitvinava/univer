#include <iostream>
#include <vector>//проверка на неотрицательные числа



void updateArray(std::vector<std::vector<std::vector<int>>>& array, int i, int j, int k) {
    if (i < array.size()) {
        if (j < array[i].size()) {
            if (k < array[i][j].size()) {
                std::cout << "Введите значение для элемента array[" << i << "][" << j << "][" << k << "]: ";
                std::cin >> array[i][j][k];
                updateArray(array, i, j, k + 1);
            }
            else {
                updateArray(array, i, j + 1, 0);
            }
        }
        else {
            updateArray(array, i + 1, 0, 0);
        }
    }
}

int main() {
    int x, y, z;

    std::cout << "Введите размеры массива (x y z): ";
    std::cin >> x >> y >> z;

    std::vector<std::vector<std::vector<int>>> array(x, std::vector<std::vector<int>>(y, std::vector<int>(z)));

    updateArray(array, 0, 0, 0);

    /*int ***array = new int**[x];// выделение памяти
    for(int i = 0; i < x; ++i) {
        array[i] = new int*[y];
        for(int j = 0; j < y; ++j) {
            array[i][j] = new int[z];
        }
    }*/

    std::vector<int> arr(n * n * n);//std::vector<int> - контейнер со значениями определенного типа данных 
    for (int i = 0; i < n * n * n; ++i) {//std::vector<std::string> — вектор строк.
        std::cin >> arr[i];//разобрать саму логику матриц
    }

    int max_sum = 0;
    int max_diag = 0;
    for (int diag = 0; diag < n; ++diag) {
        int sum = 0;
        for (int i = diag; i < n * n * n; i += n + 1) {
            sum += arr[i];
        }
        if (sum > max_sum) {
            max_sum = sum;
            max_diag = diag;
        }
    }

    std::cout << "Диагональ с наибольшей суммой чисел: " << max_diag + 1 << std::endl;
    std::cout << "Сумма чисел на этой диагонали: " << max_sum << std::endl;
    delete[] arr;

    return 0;
}






    updateArray(array, 0, 0, 0);

    return 0;
}



