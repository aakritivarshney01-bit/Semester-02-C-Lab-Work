#include <stdio.h>
struct complex {
    float real;
    float imag;
};

struct complex add(struct complex c1, struct complex c2) {
    struct complex sum;

    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    return sum;
}

int main() {
    struct complex c1, c2, result;

    printf("Enter first complex number:\n");
    printf("Real part: ");
    scanf("%f", &c1.real);
    printf("Imaginary part: ");
    scanf("%f", &c1.imag);

    printf("\nEnter second complex number:\n");
    printf("Real part: ");
    scanf("%f", &c2.real);
    printf("Imaginary part: ");
    scanf("%f", &c2.imag);

    result = add(c1, c2);

    printf("\nSum = %.2f + %.2fi\n", result.real, result.imag);

    return 0;
}
