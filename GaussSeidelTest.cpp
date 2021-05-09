#include <iostream>
#include "GaussSeidel.h"

using namespace std;

int main()
{
    double** coefficient = new double*[3];

    for (int i = 0; i < 3; i++) {
        coefficient[i] = new double[3];
    }

    coefficient[0][0] = 1;
    coefficient[0][1] = -2;
    coefficient[0][2] = 3;
    coefficient[1][0] = 2;
    coefficient[1][1] = -1;
    coefficient[1][2] = 1;
    coefficient[2][0] = 1;
    coefficient[2][1] = 3;
    coefficient[2][2] = -5;

    double constant[3] = {5, 6, 2};

    GaussSeidel test(coefficient, constant, 3, 100, 0.0001);

    test.calc();
    test.print();

    for (int i = 0; i < 3; i++) 
        delete[] coefficient[i];

    delete[] coefficient;
}
