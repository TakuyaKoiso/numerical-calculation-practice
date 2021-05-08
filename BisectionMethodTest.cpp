#include <iostream>
#include <cmath>
#include <iomanip>
#include "BisectionMethod.h"

using namespace std;

double function(double x)
{
    return (pow(x, 3.0) + x - 1.0);
}

int main()
{
    double (*func)(double) = function;

    BisectionMethod Test(0.0, 1.0, 0.0001, func);
    
    double ans = Test.calc();
    
    cout << "Answer : " << setprecision(5) << ans << '\n';
}
