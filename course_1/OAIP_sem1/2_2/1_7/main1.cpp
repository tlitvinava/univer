#include <iostream>
#include "func_for_studenichnik.h"

const ll mins= 1108;

int main() {
	title(3);
	int n = 0;
	short c;
	Studenichnik* array = new Studenichnik[10000];
	Studenichnik stop;
	std::string parameter;

	std::cout << "1)Размер равен n"
		"\n2)Остановка по параметру"
		"\n3)Остановка без остановок\n";//???

	std::cin >> c;
	switch (c) {
	case 1:
		std::cout << "Введите количество студентов: ";
		std::cin >> n;

		for (int i = 0; i < n; ++i) {
			previous_enter(array, i);
		}
		break;

	case 2:
		int t;
		std::cout << "Выберите параметр: "
			"\n\t1)Имя"
			"\n\t2)Фамилия"
			"\n\t3)Отчество"
			"\n\t4)Группа"
			"\n\t5)Средний балл"
			"\n\t6)Доход на члена семьи";
		std::cin >> t;
		std::cout << "Введите параметр: ";
		std::cin >> parameter;

		while (true) {
			previous_enter(array, n++);
			if (check(array[n - 1], parameter, t))
			{
				break;
			}
		}

		break;

	case 3:
		while (true) {
			std::string str;
			add(array[n], n);
			std::cout << "Хотите продолжить? (да или нет)";
			std::cin >> str;
			n++;
			if (str == "нет") {
				break;
			}
		}
		break;
	}

	short choose;
	int ind;
	std::string param;
	while (true) {
		std::cout <<
			"Меню: "
			"\n\t1)Показать массив структур"
			"\n\t2)Добавить"
			"\n\t3)Найти элемент с параметром"
			"\n\t4)Удалить или поменять элемент"
			"\n\t5)Сортировать массив"
			"\n\t6)Закрыть";
		//std::cin >> choose;

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
			std::cout << "Введите параметр: ";
			std::cin >> param;
			find_element(array, n, param);
			break;
		case 4:
			std::cout << "Введите номер студента: ";
			std::cin >> ind;
			delete_or_change(array, n, ind);
			break;

		case 5://переписать как нибудь сортировку

			sort(array, n);
			//Sort(array, n);
			for (int i = 0; i < n; ++i) {
				show(array[i], i);
			}

			std::cout << "\n\n";
			break;

		case 6:
			sort(array, n);
			std::cout << "Студенты, у которых доход на члена семьи меньше двух минимальных зарплат:\n";
			for (int i = 0; i < n; i++) {
				if (array[i].doxod < mins) {
					show(array[i], i);
				}
			}

			delete[] array;
			return 0;
		}
	}


	return 0;
}