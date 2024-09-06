#include <iostream>

void title(int var) {
    setlocale(LC_ALL, " ");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 1\n";
}

int main()//работает, но подключи заголовочный и красиво оформи
{
    title(3);
    int n, min, max, mini, maxi, t;
	int arr[10] = { 0,0,0,0,0,1,0,0,0,10};
    n = sizeof(arr) / sizeof(arr[0]); // Размер массива
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    

    // Находим минимальное и максимальное значение в массиве
    min = arr[0];
    max = arr[0];
    mini = 0;
    maxi = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            mini = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            maxi = i;
        }
    }

    // Меняем местами минимальный и максимальный элементы
    t = arr[mini];
    arr[mini] = arr[maxi];
    arr[maxi] = t;

    // Выводим массив после обмена
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}


