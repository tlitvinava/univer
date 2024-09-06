#include "func_for_studenichnik2.h"

void title(int var) {
	setlocale(LC_ALL, "Russian");
	std::cout << "Выполнила: Литвинова Таисия\n";
	if (var != -1) {
		std::cout << "Вариант: " << var << '\n';
	}
	std::cout << "Задание 2\n";
}

bool check_string(const std::string& str) {
	for (char c : str) {
		if (std::isdigit(c)) {
			std::cout <<'\n' << "Ошибка. Введите ещё раз: ";
			return false;
		}
	}
	return true;
}

short check_choose() {
	short c = 0;
	while (true) {
		if (std::cin >> c) {
			if (c >= 1 || c <= 6) {
				return c;
			}
			else {
				std::cout << "Ошибка.Введите еще раз: ";
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка.Введите еще раз: ";
		}

	}
}

d check_mark() {
	d c = 0;
	while (true) {
		if (std::cin >> c) {
			if (c >= 0 && c <= 5) {
				//break;
				return c;
			}
			else {
				std::cout << "Ошибка.Введите еще раз: ";
			}
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка.Введите еще раз: ";
		}
	}
}

ld average(Studenichnik stud) {
	ld result = stud.mark_fis + stud.mark_lan + stud.mark_mat;
	return result / 3;
}

void sort(Studenichnik*& arr, int n) {//сортировка выбором
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (average(arr[j]) < average(arr[min])) {
				min = j;
			}
			std::swap(arr[min], arr[i]);
		}
	}
}

void add(Studenichnik& sh, int n) {
	std::cout << "\nСтудент #" << n << ":\n";
	std::cout << "Введите имя: ";
	do {
		std::cin >> sh.fname;
	} while (!check_string(sh.fname));
	std::cout << "\nВведите фамилию: ";
	do {
		std::cin >> sh.sname;
	} while (!check_string(sh.sname));
	std::cout << "\nВведите отчество: ";
	do {
		std::cin >> sh.otchestvo;
	} while (!check_string(sh.otchestvo));
	std::cout << "\nВведите балл за экзамен по математике: ";
	sh.mark_mat=check_mark();
	std::cout << "\nВведите балл за экзамен по физике: ";
	sh.mark_fis = check_mark();
	std::cout << "\nВведите балл за экзамен по языку: ";
	sh.mark_lan = check_mark();
	std::cout << std::endl;
}

void show(const Studenichnik& arr, int i) {
	std::cout << "\nИмя: " << arr.fname;
	std::cout << "\nФамилия: " << arr.sname;
	std::cout << "\nОтчество: " << arr.otchestvo;
	std::cout << "\nБалл по математике: " << std::setprecision(2) << arr.mark_mat;
	std::cout << "\nБалл по физике: " << std::setprecision(2) << arr.mark_fis;
	std::cout << "\nБалл по языку: " << std::setprecision(2) <<arr.mark_lan;
	std::cout << std::endl;
}

void add_more(Studenichnik* array, ll& n) {
	int index;
	std::cout << "Сколько студентов вы хотите добавить: ";
	std::cin >> index;

	for (int i = n; i < n + index; ++i) {
		add(array[i], i);
	}
	n += index;
}

void delete1(Studenichnik* array, ll& n, int index) {
	for (int i = index; i < n; ++i) {
		array[i] = array[i + 1];
	}
	--n;
}

void change(Studenichnik* array, ll& n, int index) {
	add(array[index], index);
}