#ifndef ___Class_GaussJordan
#define ___Class_GaussJordan

#include <iostream>
#include <iomanip>

class GaussJordan
{
    double**    coefficient; // matrix of coefficient
    double*     constant;    // matrix of constant terms
    int         varnum;      // the number of variables
    double*     ans;         // answers are assigned to this matrix

public:
    GaussJordan(int num, double** coef, double* con) // constructor
        : varnum(num), coefficient(coef), constant(con)
    {
        ans = new double[varnum];
    }

    ~GaussJordan() // destructor
    {
        delete[] ans;
    }

    void calc() // Calculation using Gauss Jordan elimination is executed in this function.
    {
        double** tempcoef  = new double*[varnum];   
        double*  tempconst = new double[varnum]; 

        for (int i = 0; i < varnum; i++)
            tempcoef[i] = new double[varnum];

        for (int i = 0; i < varnum; i++)
            for (int j = 0; j < varnum; j++)
                tempcoef[i][j] = coefficient[i][j];

        for (int i = 0; i < varnum; i++)
            tempconst[i] = constant[i];

        for (int i = 0; i < varnum; i++) {
            
            double pivot = tempcoef[i][i];

            for (int j = 0; j < varnum; j++)
                tempcoef[i][j] /= pivot;

            tempconst[i] /= pivot;

            for (int j = 0; j < varnum; j++) {
                
                if (j == i) continue;

                double magnification = tempcoef[j][i];
                for (int k = 0; k < varnum; k++) 
                    tempcoef[j][k] -= tempcoef[i][k] * magnification;

                tempconst[j] -= tempconst[i] * magnification;    
            }
        }

        for (int i = 0; i < varnum; i++)
            ans[i] = tempconst[i];

        for (int i = 0; i < varnum; i++)
            delete[] tempcoef[i];

        delete[] tempcoef;
    }

    void print()
    {
        std::cout << "----- answer -----\n";
        
        for (int i = 0; i < varnum; i++)
            std::cout << "x_" << i + 1 << " = " << std::fixed << std::setprecision(3) << ans[i] << '\n';
    }
};

#endif
