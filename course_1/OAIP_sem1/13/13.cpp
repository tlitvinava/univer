/*#include <iostream>/////////////////////проверить четный порядок
using namespace std;
int main() {
    while (true) {
        int n, B;
        std::cout << "Enter n \n";
        while (!(std::cin >> n) || (!(int(n)))) {
            std::cout << "Invalid or negative value, try again: ";
            std::cin.clear(); // возвращаем cin в обычный режим работы
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// отмена всего, что ввел пользователь
        }
        if (n % 2 != 0) {
            // Выделение памяти под двумерный массив
            int** ms = (int**)malloc(n * sizeof(int*));
            for (int i = 0; i < n; i++) {
                ms[i] = (int*)malloc(n * sizeof(int));
            }

            // Заполнение массива нулями
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ms[i][j] = 0;
                }
            }
        }


            // Построение магического квадрата с помощью метода Ло Шу
            int s = 0;     // распределение чисел от 1 до n*n начинается с середины первой строки
            int r = n / 2;

            for (int num = 1; num <= n * n; num++) {
                ms[s][r] = num;

                // Вычисление следующей позиции
                int news = (s - 1 + n) % n;
                int newr = (r + 1) % n;

                // Если следующая позиция уже занята, двигаемся вниз
                if (ms[news][newr] != 0) {
                    s = (s + 1) % n;
                }
                else {
                    s = news;
                    r = newr;
                }
            }

            // Печать магического квадрата
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << ms[i][j] << "\t";
                }
                cout << "\n";
                cout << "\n";
            }
            // Освобождение памяти
            for (int i = 0; i < n; i++) {
                delete[] ms[i];
            }
            delete[] ms;
        }
        if (n % 4 == 0) {
            int i, j;
            // построение магического квадрата двойного четного порядка(4,8,12..)
            // Создание двумерного динамического массива
            int** square2 = new int* [n];
            for (i = 0; i < n; i++)
                square2[i] = new int[n];

            //заполнение матрицы
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    square2[i][j] = (n * i) + j + 1;

            // замена местами элементов матрицы
            // верхний левый угол
            for (i = 0; i < n / 4; i++)
                for (j = 0; j < n / 4; j++)
                    square2[i][j] = (n * n + 1) - square2[i][j];

            // верхний правый
            for (i = 0; i < n / 4; i++)
                for (j = 3 * (n / 4); j < n; j++)
                    square2[i][j] = (n * n + 1) - square2[i][j];

            // нижний левый угол
            for (i = 3 * n / 4; i < n; i++)
                for (j = 0; j < n / 4; j++)
                    square2[i][j] = (n * n + 1) - square2[i][j];

            // нижний правый
            for (i = 3 * n / 4; i < n; i++)
                for (j = 3 * n / 4; j < n; j++)
                    square2[i][j] = (n * n + 1) - square2[i][j];

            // изменение центра
            for (i = n / 4; i < 3 * n / 4; i++)
                for (j = n / 4; j < 3 * n / 4; j++)
                    square2[i][j] = (n * n + 1) - square2[i][j];

            // вывод квадрата
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << square2[i][j] << "\t";
                }
                cout << "\n";
                cout << "\n";
            }

            // освобождение динамической памяти
            for (i = 0; i < n; i++)
                delete[] square2[i];
            delete[] square2;
        }
        if (n % 2 == 0 && (n % 4 != 0)) {
            int square3 = new int* [n];
            for (int i = 0; i < n; i++) {
                square3[i] = new int[n];
                for (int j = 0; j < n; j++) {
                    square3[i][j] = 0;
                }
            }

            int row = 0;
            int col = n / 2;
            int num = 1;

            while (num <= n * n) {
                square3[row][col] = num;
                num++;

                int newRow = (row - 1 + n) % n;
                int newCol = (col + 1) % n;

                if (square3[newRow][newCol] != 0) {
                    row = (row + 1) % n;
                }
                else {
                    row = newRow;
                    col = newCol;
                }
            }

            // Вывод квадрата на экран
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << square3[i][j] << "\t";
                }
                cout << "\n";
                cout << "\n";
            }

            // Освобождение памяти
            for (int i = 0; i < n; i++) {
                delete[] square3[i];
            }
            delete[] square3;

        }
        std::cout << "Do you want to continue? If yes, write any symbol. If not, write 0 to exit \n ";
        std::cin >> B;
        if (B == 0) {
            return 0;
        }
    }
}*/


#include <iostream>
using namespace std;
int main() {
    while (true) {
        int n, B;
        std::cout << "n: \n";
        while (!(std::cin >> n) || (!(int(n)))) {
            std::cout << "Invalid or negative value, try again: ";
            std::cin.clear(); // возвращаем cin в обычный режим работы
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// отмена всего, что ввел пользователь
        }
        if (n % 2 != 0) {
            // Выделение памяти под двумерный массив
            int** square = (int**)malloc(n * sizeof(int*));
            for (int i = 0; i < n; i++) {
                square[i] = (int*)malloc(n * sizeof(int));
            }


            // Инициализация элементов массива нулями
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    square[i][j] = 0;
                }
            }

            // Построение магического квадрата с помощью метода Ло Шу
            int s = 0;     // распределение чисел от 1 до n*n начинается с середины первой строки
            int r = n / 2;

            for (int num = 1; num <= n * n; num++) {
                square[s][r] = num;

                // Вычисление следующей позиции
                int news = (s - 1 + n) % n;
                int newr = (r + 1) % n;

                // Если следующая позиция уже занята, двигаемся вниз
                if (square[news][newr] != 0) {
                    s = (s + 1) % n;
                }
                else {
                    s = news;
                    r = newr;
                }
            }

            // Печать магического квадрата
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << square[i][j] << "\t";
                }
                cout << "\n";
                cout << "\n";
            }
            // Освобождение памяти
            for (int i = 0; i < n; i++) {
                delete[] square[i];
            }
            delete[] square;
        }
        if (n % 4 == 0) {
            int i, j;
            // построение магического квадрата двойного четного порядка(4,8,12..)
            // Создание двумерного динамического массива
            int** square2 = new int* [n];
            for (i = 0; i < n; i++)
                square2[i] = new int[n];

            //заполнение матрицы
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    square2[i][j] = (n * i) + j + 1;

            // замена местами элементов матрицы
            // верхний левый угол
            for (i = 0; i < n / 4; i++)
                for (j = 0; j < n / 4; j++)
                    square2[i][j] = (n * n + 1) - square2[i][j];

            // верхний правый
            for (i = 0; i < n / 4; i++)
                for (j = 3 * (n / 4); j < n; j++)
                    square2[i][j] = (n * n + 1) - square2[i][j];

            // нижний левый угол
            for (i = 3 * n / 4; i < n; i++)
                for (j = 0; j < n / 4; j++)
                    square2[i][j] = (n * n + 1) - square2[i][j];

            // нижний правый
            for (i = 3 * n / 4; i < n; i++)
                for (j = 3 * n / 4; j < n; j++)
                    square2[i][j] = (n * n + 1) - square2[i][j];

            // изменение центра
            for (i = n / 4; i < 3 * n / 4; i++)
                for (j = n / 4; j < 3 * n / 4; j++)
                    square2[i][j] = (n * n + 1) - square2[i][j];

            // вывод квадрата
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << square2[i][j] << "\t";
                }
                cout << "\n";
                cout << "\n";
            }

            // освобождение динамической памяти
            for (i = 0; i < n; i++)
                delete[] square2[i];
            delete[] square2;
        }
        if (n % 2 == 0 && (n % 4 != 0)) {
                // Выделение памяти под двумерный массив
                int** square3 = (int**)malloc(n * sizeof(int*));
                for (int i = 0; i < n; i++) {
                    square3[i] = (int*)malloc(n * sizeof(int));
                }


            int row = 0;
            int col = n / 2;
            int num = 1;

            while (num <= n * n) {
                square3[row][col] = num;
                num++;

                int newRow = (row - 1 + n) % n;
                int newCol = (col + 1) % n;

                if (square3[newRow][newCol] != 0) {
                    row = (row + 1) % n;
                }
                else {
                    row = newRow;
                    col = newCol;
                }
            }

            // Вывод квадрата на экран
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << square3[i][j] << "\t";
                }
                cout << "\n";
                cout << "\n";
            }

            // Освобождение памяти
            for (int i = 0; i < n; i++) {
                delete[] square3[i];
            }
            delete[] square3;

        }
        std::cout << "Do you want to continue? If yes, write any symbol. If not, write 0 to exit \n ";
        std::cin >> B;
        if (B == 0) {
            return 0;
        }
    }
}