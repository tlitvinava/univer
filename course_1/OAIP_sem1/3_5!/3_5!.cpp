#include <iostream>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 1\n";
}

int main() {
    title(-1);
    int n, m;
    std::cin >> n >> m;
    int** array = new int* [n];
    for (int i = 0; i < n; ++i) {
        array[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            std::cin >> array[i][j];
        }
    }

    int local_min = 0;//счетчик
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool flag = true;//проверяет, является ли число лок минимумом
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && !(di == 0 && dj == 0)) {
                        if (array[i][j] >= array[ni][nj]) {
                            flag = false;//если не является лок минимумом, то прерывается
                            break;
                        }
                    }
                }
                if (!flag) break;
            }
            if (flag) ++local_min;
        }
    }

    std::cout << local_min << std::endl;


    delete[] array;

    return 0;
}
