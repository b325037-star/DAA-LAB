
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i;
    int fairHead = 0, biasedHead = 0;
    int x;

    printf("Enter number of tosses: ");
    scanf("%d", &n);

    srand(time(0));

    
    for(i = 0; i < n; i++)
    {
        x = rand() % 2;

        if(x == 0)
            fairHead++;
    }

    
    for(i = 0; i < n; i++)
    {
        x = rand() % 10;

        if(x < 7)
            biasedHead++;
    }

    printf("Fair Coin\n");
    printf("Heads = %d\n", fairHead);
    printf("Probability of Head = %.2f\n", (float)fairHead / n);

    printf("Biased Coin\n");
    printf("Heads = %d\n", biasedHead);
    printf("Probability of Head = %.2f\n", (float)biasedHead / n);

    return 0;
}