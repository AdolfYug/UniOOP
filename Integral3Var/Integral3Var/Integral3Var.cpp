#include <iostream>
#include <conio.h>
#include <vector>
#include <math.h>

const int n = 3;
const int N = 100;

using namespace std;

double f(double x)
{
    return cos(x);
}

class Strategy
{
public:
    virtual ~Strategy() {}
    virtual string DoAlgorithm(const vector<string>& data) const = 0;
};

class Context
{
private:
    Strategy* strategy_;

public:
    Context(Strategy* strategy = nullptr) : strategy_(strategy)
    {
    }
    ~Context()
    {
        delete this->strategy_;
    }
    void set_strategy(Strategy* strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }
};

class Rectangular
{
public:

    double RectangularAlgoritm(double a, double b, int n)
    {
        double s1 = 0.0;
        double h = (b - a) / n;
        for (int i = 0; i < n; i++)
        {
            s1 += h * f(a + i * h);
        }
        return s1;
    }
};
class Trapezoidal
{
public:
    double TrapezoidalAlgoritm(double a, double b, int n)
    {
        double s2 = 0.0;
        double h = (b - a) / n;
        for (int i = 0; i < n; i++)
        {
            s2 += 0.5 * h * (f(a + i * h) + f(a + (i + 1) * h));
        }
        return s2;
    }
};
class Simpson
{
public:
    double SimpsonAlgoritm(double a, double b, int n)
    {
        double s3 = 0.0;
        double h = (b - a) / n;
        if (n % 2 != 0)
        {
            for (int i = 0; i < n - 1; i += 2)
            {
                s3 += h * (f(a + i * h) + 4 * f(a + (i + 1) * h) + f(a + (i + 2) * h)) / 3;
            }
        }
        else
        {
            s3 = 3 * h * (f(a) + 3 * f(a + h) + 3 * f(a + 2 * h) + f(a + 3 * h)) / 8;
            for (int i = 3; i < n - 1; i += 2)
            {
                s3 += h * (f(a + i * h) + 4 * f(a + (i + 1) * h) + f(a + (i + 2) * h)) / 3;
            }
        }
        return s3;
    }
};


int main()
{
    double a;
    double b; 

    cout << "Set x1 " << endl;
    cin >> a;
    cout << "Set x2 " << endl;
    cin >> b;

    double s1 = 0.0;
    for (int i = 0; i < N; i++)
    {
        s1 += ((b - a) / N) * f(a + i * ((b - a) / N));
    }

    double s2 = 0.0;
    for (int i = 0; i < N; i++)
    {
        s2 += 0.5 * ((b - a) / N) * (f(a + i * ((b - a) / N)) + f(a + (i + 1) * ((b - a) / N)));
    }

    double s3 = 0.0;
    if (n % 2 != 0)
    {
        for (int i = 0; i < N - 1; i += 2)
        {
            s3 += ((b - a) / N) * (f(a + i * ((b - a) / N)) + 4 * f(a + (i + 1) * ((b - a) / N)) + f(a + (i + 2) * ((b - a) / N))) / 3;
        }
    }
    else
    {
        s3 = 3 * ((b - a) / N) * (f(a) + 3 * f(a + ((b - a) / N)) + 3 * f(a + 2 * ((b - a) / N)) + f(a + 3 * ((b - a) / N))) / 8;
        for (int i = 3; i < N - 1; i += 2)
        {
            s3 += ((b - a) / N) * (f(a + i * ((b - a) / N)) + 4 * f(a + (i + 1) * ((b - a) / N)) + f(a + (i + 2) * ((b - a) / N))) / 3;
        }
    }

    cout << "(Rectangular)I = " << s1 << endl;
    cout << "(Trapezoidal)I = " << s2 << endl;
    cout << "(Simpson)I = " << s3 << endl; 

    return 0;
}