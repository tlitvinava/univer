#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "Russian");// работает
	long double a, b, x, z, f,y;
	int n;
	std::cout << "Введите a: ";
	std::cin >> a;
	std::cout << "Введите b: ";
	std::cin >> b;
	std::cout << "Введите z: ";
	std::cin >> z;
	std::cout << "Введите n: \n Если n = 1 - f = 2 * x \n Если n = 2 - f = x * x * x \n Если n = 3 - f = x / 3 \n";
	std::cin >> n;

	 if (z >= 1) {
		x = sin(z) * sin(z);
		std::cout << "Так как z>=1, то x = sin(z) * sin(z)\n";
	 }
	 else if (z < 1) {
		x = 2 + z;
		std::cout << "Так как z<1, то x = 2 + z\n";
	 }

	switch (n) {
	case 1: 
		f = 2 * x;
		y = (2 * a * f + b * cos(sqrt(abs(x)))) / ((x * x) + 5);
		std::cout << y;
		break;
	case 2:
		f = x * x * x;
		y = (2 * a * f + b * cos(sqrt(abs(x)))) / ((x * x) + 5);
		std::cout << y;
		break;
	case 3:
		f = x / 3;
		y = (2 * a * f + b * cos(sqrt(abs(x)))) / ((x * x) + 5);
		std::cout << y;
		break;
	}
	return 0;
}

