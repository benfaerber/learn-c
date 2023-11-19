#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    FILE *fptr;
    fptr = fopen("day1.txt", "r");
    char output[100];
    int current_elf;
    int max;
    while (fgets(output, 100, fptr)) {
        if (output[0] == '\n') {
            printf("%d\n", current_elf);
            if (current_elf > max) {
                max = current_elf;
            }
            current_elf = 0;
            continue;
        }    
        
        current_elf += atoi(output);
    }

    printf("Got: %d\n", max);
    return 0;
}
