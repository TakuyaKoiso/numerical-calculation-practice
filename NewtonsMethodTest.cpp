#include <iostream>
#include <cmath>
#include <iomanip>
#include "NewtonsMethod.h"

using namespace std;

double function(double x)
{
    return (pow(x, 3.0) + x - 1.0);
}

double derfunc(double x)
{
    return (3.0 * (pow(x, 2.0)) + 1.0);
}

int main()
{
    double (*func)(double) = function;
    double (*der)(double) = derfunc;

    NewtonsMethod test(1.0, 0.0001, func, der);

    double answer = test.calc();

    cout << "answer : " << setprecision(5) << answer << '\n';
}
