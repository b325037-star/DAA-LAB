#include <stdio.h>

int main()
{
    int i, j;
    double n, temp;

    printf("Enter value of n: ");
    scanf("%lf", &n);

    char *fun[] = {
        "1",
        "log2(n)",
        "sqrt(n)",
        "n^0.51",
        "n",
        "nlog2(n)",
        "32nlog2(n)",
        "100n^2+6n",
        "n^2-324",
        "50n^3",
        "2^(n/3)"
    };

    double val[] = {
        1,
        log2(n),
        sqrt(n),
        pow(n,0.51),
        n,
        n*log2(n),
        32*n*log2(n),
        100*n*n+6*n,
        n*n-324,
        50*pow(n,3),
        pow(2,n/3)
    };

    for(i=0; i<10; i++)
    {
        for(j=0; j<10-i; j++)
        {
            if(val[j] > val[j+1])
            {
                temp = val[j];
                val[j] = val[j+1];
                val[j+1] = temp;

                char *t = fun[j];
                fun[j] = fun[j+1];
                fun[j+1] = t;
            }
        }
    }

    printf("Functions in increasing order:\n");

    for(i=0; i<11; i++)
        printf("%d. %s\n", i+1, fun[i]);

    return 0;
}