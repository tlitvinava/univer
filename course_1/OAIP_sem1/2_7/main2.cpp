#include <iostream>
#include "func_for_studenichnik2.h"

int main() {

	setlocale(LC_ALL, "Russian");
	title(3);
	ll n;
	std::cout << "Введите количество студентов: ";
	std::cin >> n;
	Studenichnik* array = new Studenichnik[100000];
	for (int i = 0; i < n; i++) {
		add(array[i], i);
	}
	short choose=0;
	int ind;
	Studenichnik* ans = new Studenichnik[n];
	std::string param;
	while (true) {
		std::cout << "Меню: "
			"\n\t1)Показать массив структур"
			"\n\t2)Добавить"
			"\n\t3)Удалить"
			"\n\t4)Корректировать массив"
			"\n\t5)Сортировать"
			"\n\t6)Закрыть";
		std::cout << std::endl;

		choose = check_choose();

		switch (choose) {
		case 1:
			for (int i = 0; i < n; ++i) {
				show(array[i], i);
			}
			break;

		case 2:
			add_more(array, n);
			break;

		case 3:
			std::cin >> ind;
			delete1(array, n, ind);
			break;

		case 4:
			std::cin >> ind;
			change(array, n, ind);
			break;

		case 5:
			sort(array, n);
			for (int i = 0; i < n; ++i) {
				show(array[i], i);
			}

			std::cout << "\n\n";
			break;

		case 6:
			// Вычисление среднего балла по университету
			ld middle = 0;
			for (int i = 0; i < n; i++) {
				middle += average(array[i]);
			}
			middle /= n;

			// Вывод студентов, средний балл которых выше среднего балла по университету
			std::cout << "Студенты, средний балл которых выше среднего балла по университету:\n";
			for (int i = n-1; i >= 0; i--) {
				if (average(array[i]) > middle) {
					std::cout << array[i].sname << ' ' << array[i].fname << ' ' << array[i].otchestvo<<'\n';
				}
			}
			delete[] array;
			return 0;
		}
	}

	return 0;
}


