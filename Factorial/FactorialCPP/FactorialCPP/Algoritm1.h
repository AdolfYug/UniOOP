#define _ALGORITM1_H
#include <locale.h>
#include <iostream>

using namespace std;

long double fact(int N)
{
    if (N == 0)
        return 1;
    if (N < 0)
        return 0;
    else
        return N * fact(N - 1);
}
