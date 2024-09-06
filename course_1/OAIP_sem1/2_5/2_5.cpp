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
    title(3);
    setlocale(LC_ALL, " ");
    int n, m;
    std::cout << "n, m: ";
    std::cin >> n >> m;

    int** array = new int* [n];
    for (int i = 0; i < n; ++i)
        array[i] = new int[m];
    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> array[i][j];
        }
    }
    std::cout << "Матрица до перестановки:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << array[i][j] << ' ';
        }
        std::cout << '\n';
    }

    int max_i = 0, max_j = 0;//указывают индексы максимального элемента в массиве
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (array[i][j] > array[max_i][max_j]) {
                max_i = i;
                max_j = j;
            }
        }
    }

    long long* array1 = new long long[m];//создаем копию для пошагового перемещения строк

    for (int j = 0; j < m; ++j) {
        array1[j] = array[0][j];
        array[0][j] = array[max_i][j];
        array[max_i][j] = array1[j];
    }

    delete[] array1;


    long long m1;//создаем переменную для пошагового перемещения столбцов
    for (int i = 0; i < n; ++i) {
        m1 = array[i][0];
        array[i][0] = array[i][max_j];
        array[i][max_j] = m1;
    }

    std::cout << "Матрица после перестановки:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << array[i][j] << ' ';
        }
        std::cout << '\n';
    }

    delete[] array;

    return 0;
}







































/*#include <iostream>
#include <vector>

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 1\n";
}

int main()//работает, добавь красоты + проверка на ввод
{
    title(3);
    setlocale(LC_ALL, " ");
    int n, m;
    std::cout << "Введите размеры матрицы (n и m): ";
    std::cin >> n >> m;// размер матрицы

    std::vector<std::vector<double>> matrix(n, std::vector<double>(m));
    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "Матрица до перестановки:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    int max_i = 0, max_j = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] > matrix[max_i][max_j]) {
                max_i = i;
                max_j = j;
            }
        }
    }

    std::swap(matrix[0], matrix[max_i]);
    for (int i = 0; i < n; ++i) {
        std::swap(matrix[i][0], matrix[i][max_j]);
    }

    std::cout << "Матрица после перестановки:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;

}*/


