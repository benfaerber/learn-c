#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void pt1() {
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
}

#define MAX_NTH 3
#define LINE_COUNT 100

void pt2() {
    FILE *fptr;
    fptr = fopen("day1.txt", "r");
    char output[LINE_COUNT];
    int current_elf;
    int max[MAX_NTH];
    while (fgets(output, LINE_COUNT, fptr)) {
        if (output[0] == '\n') {
            for (int i = 0; i < MAX_NTH; i++) {
                int current_max = max[i];
                if (current_elf > current_max) {
                    max[i] = current_elf;
                    if (i != 0) {
                        max[i-1] = current_max;
                    }
                }
            }
            current_elf = 0;
            continue;
        }    
        
        current_elf += atoi(output);
    }

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += max[i];
    }
    printf("Got: %d\n", sum);
}


int main(void) {
    // pt1();
    pt2();
}
