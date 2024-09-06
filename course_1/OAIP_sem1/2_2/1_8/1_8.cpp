#include <iostream>
#include <string>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void sort(std::string str) {//разделения строки на числа и их сортировки

    int arr[1000];
    int n = 0;
    std::string temp = "";

    for (char c : str) {    // разделение строки на числа
        if (c == ' ') {
            arr[n] = stoi(temp);
            n++;
            temp = "";
        }
        else {
            temp += c;
        }
    }

    arr[n] = stoi(temp);
    n++;

    bubble(arr, n);

    print(arr, n);
}

int main() {
    std::string str;
    std::cout << "Введите строку чисел, разделенных пробелами: ";
    std::getline(std::cin, str);
    sort(str);
    return 0;
}
