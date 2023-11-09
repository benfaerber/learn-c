#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n < 2) return 1; 
    return n * factorial(n - 1);
}

int main() {
    printf("Factorial 5 = %d\n", factorial(5));

    return 0;
}
