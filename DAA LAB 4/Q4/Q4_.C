
#include <stdio.h>

void sort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i;
    int entry[100], exit[100];
    int i1 = 0, j = 0;
    int people = 0, maxPeople = 0;
    int maxTime = 0;

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter entry times:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &entry[i]);
    }

    printf("Enter exit times:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &exit[i]);
    }

    /* Sort entry and exit times */
    sort(entry, n);
    sort(exit, n);

    /* Find maximum number of people */
    while (i1 < n && j < n)
    {
        if (entry[i1] < exit[j])
        {
            people++;

            if (people > maxPeople)
            {
                maxPeople = people;
                maxTime = entry[i1];
            }

            i1++;
        }
        else
        {
            people--;
            j++;
        }
    }

    printf("\nMaximum people present = %d\n", maxPeople);
    printf("Time when maximum people were present = %d\n", maxTime);

    return 0;
}