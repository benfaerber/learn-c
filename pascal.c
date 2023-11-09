#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 10;
    int i, j;
    
    /* TODO: complete the following line to allocate memory for holding three rows */
    int** pnumbers = (int **) malloc(rows * sizeof(int));

    /* TODO: allocate memory for storing the individual elements in a row */
    for (i = 0; i < rows; i++) {
        pnumbers[i] = (int *) malloc(i * sizeof(int));
        for (j = 0; j < i; j++) {
            pnumbers[i][j] = j;
        }
    } 
  
    for (i = 0; i < rows; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }

    // for (i = 0; i < rows; i++) {
    //     free(pnumbers[i]);
    // }

    // free(pnumbers);

  return 0;
}
