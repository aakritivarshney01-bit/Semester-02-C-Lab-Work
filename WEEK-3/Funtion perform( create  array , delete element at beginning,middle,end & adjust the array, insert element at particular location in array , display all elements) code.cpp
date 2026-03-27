#include <stdio.h>
#define MAX 25

void display(int arr[], int n);
int insertAtPos(int arr[], int n, int pos, int val);
int deleteAtPos(int arr[], int n, int pos);

int main() {
    int arr[MAX];
    int n, i, choice, pos, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while(1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at position\n");
        printf("2. Delete at beginning\n");
        printf("3. Delete at middle\n");
        printf("4. Delete at end\n");
        printf("5. Display array\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter position and value: ");
            scanf("%d %d", &pos, &val);
            n = insertAtPos(arr, n, pos, val);
        }
        else if(choice == 2) {
            n = deleteAtPos(arr, n, 1);
        }
        else if(choice == 3) {
            n = deleteAtPos(arr, n, (n/2)+1);
        }
        else if(choice == 4) {
            n = deleteAtPos(arr, n, n);
        }
        else if(choice == 5) {
            display(arr, n);
        }
        else if(choice == 6) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}

// -------- DISPLAY FUNCTION --------
void display(int arr[], int n) {
    int i;
    printf("Array elements are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// -------- INSERT FUNCTION --------
int insertAtPos(int arr[], int n, int pos, int val) {
    int i;

    if(n >= MAX) {
        printf("Array is full\n");
        return n;
    }

    if(pos < 1 || pos > n+1) {
        printf("Invalid position\n");
        return n;
    }

    for(i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }

    arr[pos-1] = val;
    n++;

    return n;
}

// -------- DELETE FUNCTION --------
int deleteAtPos(int arr[], int n, int pos) {
    int i;

    if(n == 0) {
        printf("Array is empty\n");
        return n;
    }

    if(pos < 1 || pos > n) {
        printf("Invalid position\n");
        return n;
    }

    for(i = pos-1; i < n-1; i++) {
        arr[i] = arr[i+1];
    }

    n--;
    return n;
}
