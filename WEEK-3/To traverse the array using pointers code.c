#include <stdio.h>

int main() {
    int arr[10], n, i;
    int *ptr;  // pointer to integer

    printf("Enter number of elements (max 10): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Pointer points to the first element of the array
    ptr = arr;

    printf("\nTraversing array using pointers:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d = %d\n", i + 1, *(ptr + i));
    }

    return 0;
}
