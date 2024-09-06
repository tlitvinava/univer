#include <iostream> 
const int N1 = 100;

void title(int var) {
    setlocale(LC_ALL, "Russian");
    std::cout << "Выполнила: Литвинова Таисия\n";
    if (var != -1) {
        std::cout << "Вариант: " << var << '\n';
    }
    std::cout << "Задание 1\n";
}

void sort(long long arr[N1]) {
    for (int i = N1 - 1; i > 0; i--) {
        arr[i - 1] += (arr[i] / 10);
        arr[i] %= 10;
    }
}

void add_n(long long n, long long arr[N1]) {//умножение на число
    for (int i = 0; i < N1; i++) {
        arr[i] *= n;
    }

    sort(arr);
}

void sum(long long arr1[N1], long long arr2[N1]) {//сложение
    for (int i = 0; i < N1; i++) {
        arr1[i] += arr2[i];
    }
    sort(arr1);
}

void left(int n, long long arr[N1]) {//сдвиг по разряду
    for (int i = n; i < N1; i++) {//переносим цифру в след разряд слева
        arr[i - n] = arr[i];
    }
    for (int j = N1 - 1; j > N1 - 1 - n; j--) {//обнуляем текущий разряд
        arr[j] = 0;
    }
}


void match(long long arr1[N1], long long arr2[N1]) {
    for (int i = 0; i < N1; i++) {
        arr1[i] = arr2[i];
    }
}

int main() {
    title(-1);
    long long N, count = 0;
    std::cin >> N;

    long long num1[N1]{}, num2[N1]{}, res[N1]{}, num1_1[N1]{};


    if (N % 2 == 0) {
        long long Nm = N - 1, N2 = N / 2;//значения, которые нужны для формулы

        while (Nm != 0) {
            num2[N1 - 1 - count] = Nm % 10;// значения, необходимые для формулы высчитываем и записываем в массив символов
            count++;
            Nm /= 10;
        }
        count = 0;

        while (N2 != 0) {
            num1[N1 - 1 - count] = N2 % 10;// значения, необходимые для формулы высчитываем и записываем в массив символов
            num1_1[N1 - 1 - count] = num1[N1 - 1 - count];// значения, необходимые для формулы высчитываем и записываем в массив символов
            count++;
            N2 /= 10;
        }
    }
    else {
        long long Ns = (N - 1) / 2;//значения, которые нужны для формулы

        while (Ns != 0) {
            num2[N1 - 1 - count] = Ns % 10;// значения, необходимые для формулы высчитываем и записываем в массив символов
            count++;
            Ns /= 10;
        }
        count = 0;

        while (N != 0) {
            num1[N1 - 1 - count] = N % 10;// значения, необходимые для формулы высчитываем и записываем в массив символов
            num1_1[N1 - 1 - count] = num1[N1 - 1 - count];// значения, необходимые для формулы высчитываем и записываем в массив символов
            count++;
            N /= 10;
        }
    }

    // n * (n - 1) / 2 + 1; 
    for (int i = 0; i < N1; i++) {
        match(num1_1, num1);//из оригинала в копию переносим
        add_n(num2[N1 - 1 - i], num1_1);//обычное умножение на число
        left(i, num1_1);
        sum(res, num1_1);
    }


    res[N1 - 1] += 1;//+1 розетка сначала
    sort(res);

    bool flag = false;


    for (int i = 0; i < N1; i++) {// Вывод
        if (flag) {
            std::cout << res[i];
        }
        else if (res[i] != 0) {
            flag = true;
            std::cout << res[i];
        }
    }

    return 0;
}