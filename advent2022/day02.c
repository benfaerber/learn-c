#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MATCH_LOSE 0
#define MATCH_DRAW 3
#define MATCH_WIN 6

typedef enum _move {
    rock,
    paper,
    scissors,
} move;


move moveFromChar(char name) {
    switch (name) {
        case 'A':
        case 'X':
            return rock;
        case 'B':
        case 'Y':
            return paper;
        case 'C':
        case 'Z':
        default:
            return scissors;
    };
}

int moveToScore(move m) {
    switch (m) {
        case rock: return 1;
        case paper: return 2;
        case scissors: return 3;
    }
}

int matchOutcome(move moveElf, move moveMe) {
    if (moveElf == moveMe) {
        return MATCH_DRAW;
    }
    
    bool win = (moveMe == rock && moveElf == scissors)
        || (moveMe == paper && moveElf == rock)
        || (moveMe == scissors && moveElf == paper);

    return win ? MATCH_WIN : MATCH_LOSE;
}

#define LINE_SIZE 20

void pt1() {
    FILE* file = fopen("day02.txt", "r");
    char line[LINE_SIZE];
    int totalScore = 0;
    while (fgets(line, LINE_SIZE, file)) {
        move elfMove = moveFromChar(line[0]);
        char myMove = moveFromChar(line[2]);

        int outcome = matchOutcome(elfMove, myMove);
        int bonus = moveToScore(myMove);
        int score = outcome + bonus;
        totalScore += score;
    }

    printf("%d\n", totalScore);
}

void pt2() {

}

int main(void) {
    pt1();
}
