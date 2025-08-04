#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Conditional
    if (num % 2 == 0)
        printf("Even Number\n");
    else
        printf("Odd Number\n");

    // Looping
    printf("Numbers from 1 to 5:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    return 0;
}
