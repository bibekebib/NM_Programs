/***********************************
*********SECANT METHOD**************
***********************************/
#include <stdio.h>
#include <math.h>
/*Function whose root is to be determined*/
double f(double x)
{
    return cos(x) - x * exp(x);
}
/*Function that returns the root from Secant Method*/
double secant(double f(double x), double x1, double x2, double eps)
{
    int iter = 1;
    double x3;
    do
    {
        x3 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        x1 = x2;
        x2 = x3;
        iter++;
    } while (fabs(f(x3)) > eps);
    return x3;
}
/*Secant Method Function that tabulates the values at each iteration*/
double secantPrint(double f(double x), double x1, double x2, double eps)
{
    int iter = 1;
    double x3;
    printf("_______________________________________________________________________________________________\n");
    printf("iter\tx1\t\tx2\t\tf(x1)\t\tf(x2)\t\tError\n");
    printf("_______________________________________________________________________________________________\n");
    do
    {
        x3 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\n", iter, x1, x2, f(x1), f(x2), f(x3));
        x1 = x2;
        x2 = x3;
        iter++;
    } while (fabs(f(x3)) > eps);
    printf("______________________________________________________________________________________________\n");
    return x3;
}
int main()
{

    double x1, x2, x3, eps;
    printf("Enter the accuracy desired: \n");
    scanf("%lf", &eps);
    printf("Enter the intial guesses: \nx1 = ");
    scanf("%lf", &x1);
    printf("x2 = ");
    scanf("%lf", &x2);

    printf("\nOne of the roots is: %lf", secantPrint(f, x1, x2, eps));
    return 0;
}