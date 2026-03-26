#include <stdio.h>
#include <stdlib.h> 

struct student {
    char name[50];
    int age;
    char gender[10];
    char email[50];
};

int main() {
    int n, i;
    struct student *ptr;

    printf("Enter number of students: ");
    scanf("%d", &n);

    ptr = (struct student*) malloc(n * sizeof(struct student));

    if(ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for(i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", ptr[i].name);

        printf("Age: ");
        scanf("%d", &ptr[i].age);

        printf("Gender: ");
        scanf("%s", ptr[i].gender);

        printf("Email: ");
        scanf("%s", ptr[i].email);
    }

    printf("\nStudent Details:\n");

    for(i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", ptr[i].name);
        printf("Age: %d\n", ptr[i].age);
        printf("Gender: %s\n", ptr[i].gender);
        printf("Email: %s\n", ptr[i].email);
    }

    free(ptr);

    return 0;
}