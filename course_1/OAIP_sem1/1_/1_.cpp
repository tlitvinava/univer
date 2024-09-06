#include <iostream>
void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 1\n";
}

int main()//работает, только добавь красоты
{
    title(3);
    int s = 0;
    const int n = 5;
    int arr[n][n] = { {9, 66, -1,3,13}, {3, -3, 30,6,11}, {1, 1, 1,7,20}, {4, 7, 8,11,7}, {5, -5, 0,45,-1} };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[i][j] < 0) {
                s += arr[i][j];
            }
        }
    }

    std::cout << s << std::endl;
    return 0;
}

