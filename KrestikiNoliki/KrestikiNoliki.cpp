#include <iostream>
#include <cstdio>
#include <locale.h>
#include "Header1.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	cout << "Введите размер поля: ";
	cin >> size;
	KrestikiNoliki field(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			field[i][j] = ' ';
	}

	field.game(field);

	return 0;
}