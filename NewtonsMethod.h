#ifndef ___Class_NewtonsMethod
#define ___Class_NewtonsMethod

#include <iostream>
#include <cmath>

class NewtonsMethod  {
    double start;               //start point
    double tolerance;           //if |a - b| become smaller than this number, calculation stop.
    double (*function)(double); //target function
    double (*derfunc)(double);  //derivative function of target function

public:
    NewtonsMethod(double s, double t, double func(double), double der(double))
        : start(s), tolerance(t), function(func), derfunc(der)
    {
        std::cout << "start : " << start << "\ntolerance : " << tolerance << '\n';
    }

    double calc() 
    {
        double a = start;
        double b;

        while(1) {
            b = a - (function(a) / derfunc(a));
            
            if (fabs(a - b) < tolerance)
                break;

            a = b;
        }

        return b;
    }
};

#endif
