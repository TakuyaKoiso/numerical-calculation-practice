#ifndef ___Class_BairstowsMethod
#define ___Class_BairstowsMethod

#include <iostream>
#include <cmath>
#include <iomanip>

class BairstowsMethod
{
    double* coefficient;
    double tolerance;
    double** ans;
    int order;

public:
    BairstowsMethod(int ord, double* coef, double tol)
        :order(ord), coefficient(coef), tolerance(tol)
    {
        ans = new double*[order];

        for (int i = 0; i < order; i++)
            ans[i] = new double[2];
    }

    ~BairstowsMethod()
    {
        for (int i = 0; i < order; i++)
            delete[] ans[i];

        delete[] ans;
    }

    void root2nd(double a, double b, double c, int temporder) // solutions of the quadratic equation (ax^2 + bx + c = 0) are assigned to "ans". a[:][0] are real, a[:][1] are imaginary part of solutions.
    {
        if ((b*b - 4*a*c) >= 0) {
            ans[temporder - 1][0] = (-b + sqrt(b*b - 4.0*a*c)) / (2.0 * a);
            ans[temporder - 1][1] = 0.0;
            ans[temporder - 2][0] = (-b - sqrt(b*b - 4.0*a*c)) / (2.0 * a);
            ans[temporder - 2][1] = 0.0;
        } else {
            ans[temporder - 1][0] = -b / (2.0 * a);
            ans[temporder - 1][1] = sqrt(-b*b + 4.0*a*c) / (2.0 * a);
            ans[temporder - 2][0] = -b / (2.0 * a);
            ans[temporder - 2][1] = -sqrt(-b*b + 4.0*a*c) / (2.0 * a);
        }
    }

    void bsolve(double* b, double* coef, double p, double q, int temporder)
    {
        b[0] = coef[0];
        b[1] = coef[1] - p * b[0];

        for (int i = 2; i <= temporder; i++) {
            b[i] = coef[i] - p * b[i - 1] - q * b[i - 2];
        }
    }

    void csolve(double* c, double* b, double p, double q, int temporder)
    {
        c[0] = b[0];
        c[1] = b[1] - p * c[0];

        for (int i = 2; i <= temporder; i++) {
            c[i] = b[i] - p * c[i - 1] - q * c[i - 2];
        }
    }

    void Bairstow(double* coef, int temporder)
    {
        double* b = new double[temporder + 1];
        double* c = new double[temporder + 1];
        double p = 1.0; //initialize p by 1.0
        double q = 1.0; //initialize q by 1.0
        double dp, dq;

        do{
            bsolve(b, coef, p, q, temporder);
            csolve(c, b, p, q, temporder);

            double e = pow(c[temporder - 2], 2) - c[temporder - 3] * (c[temporder - 1] - b[temporder - 1]);

            dp = (b[temporder - 1] * c[temporder - 2] - b[temporder    ] * c[temporder - 3]) / e;
            dq = (b[temporder    ] * c[temporder - 2] - b[temporder - 1] * (c[temporder - 1] - b[temporder - 1])) / e;

            p += dp;
            q += dq;

        } while (fabs(dp) > tolerance || fabs(dq) > tolerance); 

        root2nd(1.0, p, q, temporder);

        for(int i = 0; i < temporder - 1; i++) {
            coef[i] = b[i];
        }

        delete[] b;
        delete[] c;
    }

    void calc()
    {
        double* tempcoef = new double[order + 1];
        int temporder = order;

        for (int i = 0; i <= order; i++)
            tempcoef[i] = coefficient[i];

        while(temporder > 2) {
            Bairstow(tempcoef, temporder);
            temporder -= 2;
        }

        if (temporder == 2) {
            root2nd(tempcoef[0], tempcoef[1], tempcoef[2], temporder);
        }

        else if (temporder == 1) {
            ans[0][0] = -(tempcoef[1] / tempcoef[0]);
            ans[0][1] = 0.0;
        }

        delete[] tempcoef;
    }

    void print()
    {
        std::cout << "Real Part / Imaginary Part\n";
        for (int i = 0; i < order; i++) {
            std::cout << std::fixed << std::setprecision(3) << ans[i][0] << "  " << std::setprecision(3) << ans[i][1] << '\n';
        }
    }

    void answer(double sol[][2])
    {
        for (int i = 0; i < order; i++) {
            sol[i][0] = ans[i][0];
            sol[i][1] = ans[i][1];
        }
    }
    
};

#endif
