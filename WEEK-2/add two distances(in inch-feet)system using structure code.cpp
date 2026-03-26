#include <stdio.h>
struct distance {
    int feet;
    int inch;
};

int main() {
    struct distance d1, d2, sum;

    printf("Enter first distance:\n");
    printf("Feet: ");
    scanf("%d", &d1.feet);
    printf("Inch: ");
    scanf("%d", &d1.inch);

    printf("\nEnter second distance:\n");
    printf("Feet: ");
    scanf("%d", &d2.feet);
    printf("Inch: ");
    scanf("%d", &d2.inch);

    
    sum.feet = d1.feet + d2.feet;
    sum.inch = d1.inch + d2.inch;

    if (sum.inch >= 12) {
        sum.feet += sum.inch / 12;
        sum.inch = sum.inch % 12;
    }

    printf("\nSum of distances = %d feet %d inch\n", sum.feet, sum.inch);

    return 0;
}
