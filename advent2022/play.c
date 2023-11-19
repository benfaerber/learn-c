#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void p_assert(char* label, bool expr) {
    printf("%s\n", label);
    assert(expr);
    printf(" - Passed!\n\n");
}


// Problem 1:
void last() {
    int coll[] = {1, 2, 3, 4}; 
    int len = sizeof(coll) / sizeof(coll[0]); 
    int last_item = coll[len - 1];
    p_assert("Problem 1: Last Item", last_item == 4);
}

// Problem 2:
void last_two() {
    int coll[] = {1, 2, 3, 4}; 
    int len = sizeof(coll) / sizeof(coll[0]); 
    if (len < 2) {
        return;
    }

    int ult_item = coll[len - 1];
    int pen_item = coll[len - 2];

    p_assert("Problem 2: Last 2 Items", ult_item == 4 && pen_item == 3);
}


int main(void) {
    last();
    last_two();
}
