#include <stdio.h>

struct student {
    int roll;
    char name[50];
    char enrollment[30];
    char faculty_no[30];
    char class_name[30];
    int semester;
    float marks;
};

int main() {
    struct student s[10];
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        getchar();  // Clear newline from buffer

        printf("Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);

        printf("Enrollment number: ");
        fgets(s[i].enrollment, sizeof(s[i].enrollment), stdin);

        printf("Faculty number: ");
        fgets(s[i].faculty_no, sizeof(s[i].faculty_no), stdin);

        printf("Class: ");
        fgets(s[i].class_name, sizeof(s[i].class_name), stdin);

        printf("Semester: ");
        scanf("%d", &s[i].semester);

        printf("Marks: ");
        scanf("%f", &s[i].marks);

        getchar();  // Clear newline again
    }

    printf("\n\nStudent Information:\n");

    for(i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number: %d\n", s[i].roll);
        printf("Name: %s", s[i].name);
        printf("Enrollment Number: %s", s[i].enrollment);
        printf("Faculty Number: %s", s[i].faculty_no);
        printf("Class: %s", s[i].class_name);
        printf("Semester: %d\n", s[i].semester);
        printf("Marks: %.2f\n", s[i].marks);
    }

    return 0;
}