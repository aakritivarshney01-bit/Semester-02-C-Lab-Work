#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50}; 
    int *ptr = arr;                     
    int index;
    
    printf("The array are :{10,20,30,40,50}\n");

    printf("Enter the index (0 to 4): ");
    scanf("%d", &index);

    if(index >= 0 && index < 5) {
        printf("Element at index %d is %d\n", index, *(ptr + index));
    } 
	else {
        printf("Invalid index! Please enter 0 to 4.\n");
    }

    return 0;
}
