#include <iostream>
using namespace std;


int main() {
    string n;
    unsigned long long K = 0, index, number, size = 0;
    cin >> n >> index;
    int array[10]{};


    for (int i = 0; i < n.size(); i++)
    {
        ++array[n[i] - '0'];
    }

    size = n.size();

    for (int i = 0; i < 10; i++)
    {
        if (array[i] != 0) {//i-номер ячейки в массиве//0- сравн вается со значением ячейки в массиве
            K++;
        }
    }

    cout << K << '\n';

    int* newArray = new int[size];//size - кол во элементов массива
    for (int i = 0; i < size; i++)
    {
        newArray[i] = n[n.size() - i - 1] - '0';
    }

    number = newArray[size - index];//в скобках номер элемента в массиве, newarray - массив, number - значение элемента массива

    for (int i = 0; i < size; i++)
    {
        if (newArray[i] == number)
            cout << i << ' ';
    }

    return 0;
}





