#include <iostream>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 1\n";
}

void bubble(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    title(-1);
    int size = 0, temp;
    std::cout << "Введите размеры массива: " << '\n';
    std::cin >> size;
    int* arr = new int[size];
    std::cout << "Введите элементы массива: " << '\n';
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    bubble(arr, size);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}

