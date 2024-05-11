#include <iostream> 

using namespace std;

int n = 0; 
int fac = 1; 
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    cout << "Введите число, факториал которого будем искать: ";
    cin >> n; 

    for (int i = 1; i < n + 1; i++)
    { 
        fac = fac * i;
    }
    cout << fac << endl;
    system("pause");
    return 0;
}