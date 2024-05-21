#include <iostream>
#include <vector>
#include <cmath>

double f(double x)
{
    return sin(x);
}
using namespace std;

class IntegrationStrategy {
public:
    virtual double integrate(double a, double b, int n) = 0;
};

class RectangleIntegration : public IntegrationStrategy {
public:
    double integrate(double a, double b, int n) override {
        double result = 0.0;
        double h = (b - a) / n;
        for (int i = 0; i < n; i++)
        {
            result += h * f(a + i * h);
        }
        return result;
    }
};

class TrapezoidIntegration : public IntegrationStrategy {
public:
    double integrate(double a, double b, int n) override {
        double result = 0.0;
        double h = (b - a) / n;
        for (int i = 0; i < n; i++)
        {
            result += 0.5 * h * (f(a + i * h) + f(a + (i + 1) * h));
        }
        return result;
    }
};

class ParabolaIntegration : public IntegrationStrategy {
public:
    double integrate(double a, double b, int n) override {
        double result = 0.0;
        double h = (b - a) / n;
        if (n % 2 != 0)
        {
            for (int i = 0; i < n - 1; i += 2)
            {
                result += h * (f(a + i * h) + 4 * f(a + (i + 1) * h) + f(a + (i + 2) * h)) / 3;
            }
        }
        else
        {
            result = 3 * h * (f(a) + 3 * f(a + h) + 3 * f(a + 2 * h) + f(a + 3 * h)) / 8;
            for (int i = 3; i < n - 1; i += 2)
            {
                result += h * (f(a + i * h) + 4 * f(a + (i + 1) * h) + f(a + (i + 2) * h)) / 3;
            }
        }
        return result;
    }
};

class Integrator {
private:
    IntegrationStrategy* strategy;

public:
    Integrator(IntegrationStrategy* strat) : strategy(strat) {}

    void setStrategy(IntegrationStrategy* strat) {
        strategy = strat;
    }

    double integrateData(double a, double b, int n) {
        return strategy->integrate(a, b, n); 
    }
};

int main() {

    setlocale(LC_ALL, "RUSSIAN");

    double a;
    double b;
    double n;
    cout << "Введите нижнюю границу: " << endl;
    cin >> a;
    cout << "Введите верхнюю границу: " << endl;
    cin >> b;
    cout << "Введите количество шагов: " << endl;
    cin >> n;

    RectangleIntegration rectInt;
    TrapezoidIntegration trapInt;
    ParabolaIntegration paraInt;

    Integrator integrator(&rectInt);
    double result_rect = integrator.integrateData(a, b, n);

    integrator.setStrategy(&trapInt);
    double result_trap = integrator.integrateData(a, b, n);

    integrator.setStrategy(&paraInt);
    double result_para = integrator.integrateData(a, b, n);

    cout << "Результат интегрирования Прямоугольниками: " << result_rect << endl;
    cout << "Результат интегрирование Трапецией: " << result_trap << endl;
    cout << "Результат интегрирование Парабалой: " << result_para << endl;

    return 0;
}