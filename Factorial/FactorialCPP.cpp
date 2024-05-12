#include <iostream>
#include <locale.h>
#include "Algoritm1.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int N;
    cout << "Введите число N для вычисления факториала: ";
    cin >> N;
    cout << "Факториал введенного числа равен: " << fact(N) << endl; 
    return 0;
}