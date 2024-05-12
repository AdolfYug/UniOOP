#include <iostream>
#include <cstdio>
#include <locale.h>
#include "Algoritm1.h"

using namespace std;

int main()
{
	int size;
	cout << "Enter size of field: ";
	cin >> size;
	KrestikiNoliki field(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			field[i][j] = ' ';
	}

	field.game(field);

	return 0;
}
