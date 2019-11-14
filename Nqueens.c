#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    int size;
    int solutions;
} board;


void printboard(board *n, int *positions) {
    for(int row = 0; row < n->size; ++row) {
        for(int column = 0; column < n->size; ++column) {
            if(positions[row] == column) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}


int check(int *positions, int ocuppied_rows, int column) {
    for(int i = 0; i < ocuppied_rows; ++i) {
        if(positions[i] == column || positions[i] - i == column - ocuppied_rows || positions[i] + i == column + ocuppied_rows) {
            return 0;
        }
    }
    return 1;
}


void putqueen(board *n, int *positions, int target_row) {
    if(target_row == n->size) {
        printboard(n, positions);
        n->solutions++;
    } else {
        for(int column = 0; column < n->size; ++column) {
            if(check(positions, target_row, column)) {
                positions[target_row] = column;
                putqueen(n, positions, target_row + 1);
            }
        }
    }
}


void solve(board *n) {
    int *positions = (int*)malloc(n->size * sizeof(int));
    putqueen(n, positions, 0);
    printf("Found %d solutions\n", n->solutions);
    free(positions);
}


int main() {
	int i;
	board n;
	printf("Enter the number of queens : ");
	scanf("%d",&i);
	n.size=i;
    solve(&n);
    return 0;
}







