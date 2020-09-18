
/* Program: Finding real roots of nonlinear
   equation using Fixed Point Iteration
*/
/* Header Files */
#include <stdio.h>

#include <math.h>

#define f(x) tan(x) - x - 1
/* Write f(x) as x = g(x) and
   define g(x) here */
#define g(x) tan(x) - 1

int main()
{
    int step = 1, N;
    float x0, x1, e;
    /* Inputs */
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    /* Implementing Fixed Point Iteration */
    printf("\nStep\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do
    {
        x1 = g(x0);
        printf("%d\t%f\t%f\t%f\t%f\n", step, x0, f(x0), x1, f(x1));

        step = step + 1;

        x0 = x1;

    } while (fabs(f(x1)) > e);

    printf("\nRoot is %f", x1);

    return (0);
}
