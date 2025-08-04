#include <stdio.h>

int main() {
    int a = 10, b = 3;
    printf("Addition: %d\n", a + b);
    printf("Subtraction: %d\n", a - b);
    printf("Multiplication: %d\n", a * b);
    printf("Division: %d\n", a / b);
    printf("Modulus: %d\n", a % b);

    printf("Relational: %d\n", (a > b));
    printf("Logical: %d\n", (a > 5 && b < 5));
    return 0;
}
