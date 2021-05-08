#include <iostream>
#include "BairstowsMethod.h"

using namespace std;\

int main()
{
    int order;

    cout << "Input an order of equation you want to solve : ";
    cin >> order;

    double* coefficient = new double[order + 1];

    for (int i = 0; i <= order; i++) {
        cout << "Input the coefficient of x^" << order - i << " : ";
        cin >> coefficient[i];
    }

    BairstowsMethod test(order, coefficient, 0.0001);

    test.calc();
    test.print();

    delete[] coefficient;
}
