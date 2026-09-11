#include <stdio.h>
int main()
{
    int n, totalCoins, moves;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    totalCoins = n * (n + 1) / 2;
    moves = totalCoins / 3;
    
    printf("Total number of coins = %d\n", totalCoins);
    printf("Minimum number of moves = %d\n", moves);

    return 0;
}