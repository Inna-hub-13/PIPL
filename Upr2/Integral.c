
// Write a program that calculates a definite integral
// Using sum of areas of trapeze -> S = (y1 + y2) * dx / 2;

#include <stdio.h>

double linear_func(double);
double square_func(double);

double find_integral(double, double, double, double(*)( double));

int main() {

    double integral1 = find_integral(0, 10, 0.01, linear_func);
    double integral2 = find_integral(0, 10, 0.01, square_func);

    printf("integral1 = %.3lf\n", integral1);
    printf("integral2 = %.3lf\n", integral2);

    return 0;
}



double linear_func(double x) {

    return 2 * x + 5;
}

double square_func(double x) {

    return 2 * x * x + 5 * x + 4;
}


double find_integral(double l, double u, double dx, 
                        double(*f)(double x)){
        
    double x1 = l;
    double x2 = x1 + dx;
    double y1 = f( x1);
    double y2 = f(x2);
    double S = 0;

    while(x2 < u){
        
        S += (y1 + y2) * dx / 2;
        x1 = x2;
        x2 = x1 + dx;
        y1 = f(x1);
        y2 = f(x2);
    }

    // for absolute accuracy
    if(x2 == u)
        return S;
    else{

        x2 = u - x1;
        y1 = f(x1);
        y2 = f(x2);
        S += (y1 + y2) * dx / 2;

        return S;
    }
}
