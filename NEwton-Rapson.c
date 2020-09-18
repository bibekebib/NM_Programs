
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Defining equation to be solved.
   Change this equation to solve another problem. */
#define f(x) x *x *x + 2 * x *x + 50 * x + 7

/* Defining derivative of g(x).
   As you change f(x), change this function also. */
#define g(x) 3 * x *x + 4 * x + 50

void main()
{
    float x0, x1, f0, f1, g0, e;
    int step = 1, N;

    /* Inputs */
    printf("\nEnter initial guess:\n");
    scanf("%f", &x0);
    printf("Enter tolerable error:\n");
    scanf("%f", &e);
    // printf("Enter maximum iteration:\n");
    // scanf("%d", &N);
    /* Implementing Newton Raphson Method */
    printf("______________________________________________________________________________________________________________________\n");
    printf("\nStep\t\tx\t\tf(x)\t\tf'(x)\t\tx1\t\tf(x1)\t\tError\n");
    printf("______________________________________________________________________________________________________________________\n\n");
    do
    {
        g0 = g(x0);
        f0 = f(x0);
        if (g0 == 0.0)
        {
            printf("Mathematical Error.");
            exit(0);
        }

        x1 = x0 - f0 / g0;
        f1 = f(x1);

        printf("%d\t\t%f\t%f\t%f\t%f\t%f\t\t%f\n", step, x0, f0, g0, x1, f1, fabs(x1 - x0));

        x0 = x1;

        step = step + 1;

        // if (step > N)
        // {
        //     printf("Not Convergent.");
        //     exit(0);
        // }

        f1 = f(x1);

    } while (fabs(f1) >= e);
    printf("______________________________________________________________________________________________________________________\n");

    printf("\nRoot is: %f", x1);
}