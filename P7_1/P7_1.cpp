#include <iostream>
using namespace std;

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    double add(double a, double b)
    {
        return a + b;
    }

    double add(int a, double b)
    {
        return a + b;
    }
};

int main()
{
    Calculator calc;

    int sum1 = calc.add(5, 10);
    double sum2 = calc.add(3.5, 4.5);
    double sum3 = calc.add(7, 2.5);

    cout << "Sum of integers: " << sum1 << endl;
    cout << "Sum of doubles: " << sum2 << endl;
    cout << "Sum of int and double: " << sum3 << endl;

    return 0;
}
