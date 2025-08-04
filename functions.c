#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 5, y = 10;
    printf("Sum of %d and %d is %d\n", x, y, add(x, y));
    return 0;
}
