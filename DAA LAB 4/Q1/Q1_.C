
#include <stdio.h>

int main()
{
    int n, i, j;
    int number[100];
    char colour[100];
    int temp;
    char tempc;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter number and colour (R/B/Y):\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d %c", &number[i], &colour[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            int x = 0, y = 0;

            if (colour[i] == 'R')
                x = 1;
            else if (colour[i] == 'B')
                x = 2;
            else
                x = 3;

            if (colour[j] == 'R')
                y = 1;
            else if (colour[j] == 'B')
                y = 2;
            else
                y = 3;

            if (x > y || (x == y && number[i] > number[j]))
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;

                tempc = colour[i];
                colour[i] = colour[j];
                colour[j] = tempc;
            }
        }
    }

    printf("\nSorted items:\n");

    for (i = 0; i < n; i++)
    {
        printf("(%d, %c) ", number[i], colour[i]);
    }

    return 0;
}