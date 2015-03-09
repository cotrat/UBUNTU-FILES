#include <stdlib.h>
#include <stdio.h>

/*

@miorel is exactly correct about backtracking. Just for fun I tried to solve this brute force in C/C++ using a simple recursive algorithm, with a one simple optimization:

We know that for any given problem size N, each queen will be in a separate column. So we don't even try other columns. So the idea is this:

Each queen will have its own column, so queen 1 goes in column 1, queen 2 in column 2, etc.
So the goal really is to pick a row for each queen. Starting with the first queen, let try each row in turn. We do this by placing a queen in a possible row, 
then making a recursive call to place the second, third, and fourth queen.
When checking if placing is compatible, we only need to check a) whether there is a queen in the same row and b) whether there are any diagonal queens.

*/

int solveQueens(int queenIndex, int sz, int * positions) {
    for (int i=0; i<sz; i++) {
        int valid = 1;
        for (int j=0; j<queenIndex; j++) {
            int diff = queenIndex-j;
            if ( 
                    (positions[j]==i)
                ||  (positions[j]+diff == i) 
                ||  (positions[j]-diff == i)
            ) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            positions[queenIndex]=i;
            if (queenIndex < sz-1) {
                // Recursive call
                int res = solveQueens(queenIndex+1, sz, positions);
                if (res) 
                    return 1;
            } else {
                return 1;
            }
        }
    }
    return 0;
}

void printQueens(int sz, int * positions) {
    for (int i=0; i<sz; i++) {
        printf("%c%d ", (char)(i+(int)'A'), positions[i]+1);
    }   
}

void queens(int sz) {
    int * positions = (int *)malloc(sizeof(int)*sz);
    if (solveQueens(0, sz, positions)) {
        printQueens(sz, positions);
    } else {
        printf("No solutions found\n");
    }
    free(positions);
}

int main() {
    queens(24);
    return 0;
}
