#include <iostream>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 2\n";
}

void insert(double arr[], int start, int end) {//сортировка вставками
    for (int i = start + 1; i < end; i++) {
        double temp = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

void select(double arr[], int start, int end) {//сортировка выбором
    for (int i = start; i < end; i++) {
        int min = i;
        for (int j = i + 1; j < end; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
            double temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    title(-1);

    int size = 0,k,n;
    std::cout << "Введите размеры массива: "<<'\n';
    std::cin >> size;
    if (size % 2 != 0) {
         k = size / 2 + 1;
         n = k - 1;
    }
    else {
        k = size / 2;
        n= size/2-1;
    }
    std::cout << "Введите элементы массива: " << '\n';
    double* arr = new double[size];
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    insert(arr, 0, k);
    select(arr, n, size);

    for (int i = 0; i < size; i++) {

        std::cout << arr[i] << " ";
    }

    return 0;
}
