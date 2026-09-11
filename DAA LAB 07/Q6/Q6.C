

#include <stdio.h>

int main()
{
    int birth[50], death[50];
    int n, i, j;
    int count = 0, max = 0, bestYear = 0;
    int temp;

    printf("Enter number of scientists: ");
    scanf("%d", &n);

    printf("Enter birth and death years:\n");

    for (i = 0; i < n; i++)
        scanf("%d %d", &birth[i], &death[i]);

    /* Sort birth years */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (birth[i] > birth[j])
            {
                temp = birth[i];
                birth[i] = birth[j];
                birth[j] = temp;
            }
        }
    }

    /* Sort death years */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (death[i] > death[j])
            {
                temp = death[i];
                death[i] = death[j];
                death[j] = temp;
            }
        }
    }

    i = 0;
    j = 0;

    while (i < n && j < n)
    {
        /* Death comes first if years are equal */
        if (birth[i] < death[j])
        {
            count++;

            if (count > max)
            {
                max = count;
                bestYear = birth[i];
            }

            i++;
        }
        else
        {
            count--;
            j++;
        }
    }

    printf("\nYear with maximum scientists alive = %d", bestYear);
    printf("\nMaximum number of scientists alive = %d", max);

    return 0;
}