#ifndef ___Class_BisectionMethod
#define ___Class_BisectionMethod

class BisectionMethod {
    double big;           //Bigger one of starging point
    double small;           //Smaller one of starging point
    double tolerance;   //If (b - a) become smaller than this number, calculation end.
    double (*function)(double);       //Target function
public:
    BisectionMethod(double a, double b, double tol, double func(double))
        :small(a), big(b), tolerance(tol), function(func)
    {
        std::cout << "small : " << small << "\nbig : " << big << "\ntolerance : " << tolerance << '\n';
    }

    double calc() {
    
        double a = small;
        double b = big;

        double mid = (big + small) / 2.0; //midpoint of a and b

        while ((b - a) > tolerance) {
            mid = (b + a) / 2.0;
           
            if (function(a) * function(mid) >= 0)
                a = mid;
            else
                b = mid;
        } 

        return mid; 
    }
};

#endif
