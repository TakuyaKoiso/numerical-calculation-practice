#ifndef ___Class_GaussSeidel
#define ___Class_GaussSeidel

#include <iostream>
#include <cmath>
#include <iomanip>

class GaussSeidel
{
    double**    coefficient;    // matrix of coefficient
    double*     constant;       // matrix of constant tarm
    int         varnum;         // number of variable you want to solve
    int         roopmax;        // max number of roop count
    double      tolerance;      // max tolerance 
    double*     ans;            // Answers is assined to this variable.

public:
    GaussSeidel(double** coef, double* con, int num, int roop, double tol)
        :coefficient(coef), constant(con), varnum(num), roopmax(roop), tolerance(tol)
    {
        ans = new double[varnum];
    }

    ~GaussSeidel()
    {
        delete[] ans; 
    }

    void calc()
    {
        double* tempans = new double[varnum];

        for (int i = 0; i < varnum; i++)
            tempans[i] = 1.0;   // "tempans[:] is initialized by 1.0.

        double dq;
        int rnum = 0; // roopcount

        do{
            dq = 0;
            double temptempans;

            for (int i = 0; i < varnum; i++) {
                temptempans = tempans[i];
                tempans[i] = constant[i];

                for (int j = 0; j < varnum; j++) {
                    if (j == i) continue;

                    tempans[i] -= (coefficient[i][j] * tempans[j]);
                }

                tempans[i] /= coefficient[i][i];

                dq += fabs(tempans[i] - temptempans);
            }
            
            rnum++;
        } while ((dq > tolerance) && (rnum < roopmax));

        for (int i = 0; i < varnum; i++) {
            ans[i] = tempans[i];
        }

        delete[] tempans;
    }

    void print()
    {
        std::cout << "----- answer -----\n";

        for (int i = 0; i < varnum; i++)
            std::cout << "x_" << i << " = " << std::fixed << std::setprecision(3) << ans[i] << '\n';
    }
};

#endif
