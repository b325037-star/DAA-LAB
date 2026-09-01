
#include <stdio.h>

int moves = 0;

void toh(int n, char l, char m, char r)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", l, r);
        moves++;
        return;
    }

    toh(n - 1, l, r, m);

    printf("Move disk %d from %c to %c\n", n, l, r);
    moves++;

    toh(n - 1, m, l, r);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    toh(n, 'L', 'M', 'R');

    printf("\nTotal Moves = %d", moves);

    return 0;
}