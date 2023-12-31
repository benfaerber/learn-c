#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// int main(void) {
//     char words[] = {'a', 'b', 'c'};

//     char *rwords = words;

//     int i;
//     for (i = 0; i < 3; i++) {
//         printf(
//             "%p\n%c\n%c\n\n", 
//             rwords + i, 
//             words[i], 
//             *(rwords + i)
//         );
//     }
//     return 0;
// }

#define ASCII_CAPITAL_A 65
#define ASCII_CAPITAL_Z 90 
#define ASCII_CASE_OFFSET 32

#define IF if 
#define BEGIN {
#define END }
#define GIVE return

char lowercase(char letter) {
    IF (letter >= ASCII_CAPITAL_A && letter <= ASCII_CAPITAL_Z) 
    BEGIN 
        GIVE letter + ASCII_CASE_OFFSET;
    END 

    GIVE letter;
}

char flipcase(char letter) {
    int offset = 32;
    if (letter >= ASCII_CAPITAL_A && letter <= ASCII_CAPITAL_Z) {
        return letter + ASCII_CASE_OFFSET;
    }
    
    int lowerBound = letter >= ASCII_CAPITAL_A + ASCII_CASE_OFFSET;
    int upperBound = letter <= ASCII_CAPITAL_Z + ASCII_CASE_OFFSET;

    if (upperBound && lowerBound)
        return letter - offset;

    return letter;
}


int main(void) {
    int n = 5;
    char *vowels = (char *) malloc(n * sizeof(char));
    vowels[0] = 'A';
    *(vowels + 1) = 'E';
    vowels[2] = 'I';
    vowels[3] = 'O';
    vowels[4] = 'U';

    int i;
    for (i = 0; i < n; i++) {
        printf("%c%c - ", vowels[i], lowercase(vowels[i]));
        printf("%c%c - ", flipcase(vowels[i]), flipcase(lowercase(vowels[i])));

    }

    free(vowels);

    // Use after free
    for (i = 0; i < n; i++) {
        printf("\n(%c) %d", vowels[i], vowels[i]);

    }

}
