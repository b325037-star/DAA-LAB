
#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];  

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);


    for(i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                printf("Duplicate element found: %d\n", a[i]);
                return 0;
            }
        }
    }

    printf("All elements are unique.\n");

    return 0;
}