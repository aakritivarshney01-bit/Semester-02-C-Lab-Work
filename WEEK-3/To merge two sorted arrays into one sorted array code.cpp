#include <stdio.h>
int main() {
    int a[50], b[50], c[100];
    int n1, n2, n3;
    int i, j, temp;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements of first array:\n");
    for(i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
        c[i] = a[i]; 
    }
    
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements of second array:\n");
    for(i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
        c[n1 + i] = b[i]; 
    }

    n3 = n1 + n2; // Total size of the combined array

    for(i = 0; i < n3 - 1; i++) {
        for(j = i + 1; j < n3; j++) {
            if(c[i] > c[j]) {
                // Swap elements
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    printf("\nMerged and Sorted array:\n");
    for(i = 0; i < n3; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}