DAY_COUNT = 25;
from os.path import exists

for i in range(DAY_COUNT):
    
    name = "day" + ("0" + str(i) if i < 10 else str(i))
    if not exists(name + '.c'):
        with open(name + '.c', 'w') as c:
            c.write('''
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void pt1() {
    
}

void pt2() {

}

void main() {

}
                    ''')

        with open(name + '.txt', 'w') as txt:
            txt.write('')

