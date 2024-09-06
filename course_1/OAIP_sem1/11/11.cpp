#include <iostream>

int main()
{
	int n, m;
	char a, b;
	std::cout << "n, m: ";
	std::cin >> n >> m;

	a = '.';
	b = '*';

	int** arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(m * sizeof(int));
	}



}