// Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

// Input:
// - First line: integer n representing number of rows and columns
// - Next n lines: n integers each representing the matrix elements

// Output:
// - Print "Identity Matrix" if the matrix satisfies the condition
// - Otherwise, print "Not an Identity Matrix"

// Example:
// Input:
// 3
// 1 0 0
// 0 1 0
// 0 0 1

// Output:
// Identity Matrix

#include <stdio.h>

int main() {
    int row;printf(">>>"); scanf("%d", &row);
    int m[row][row];
    for (int i = 0; i < row; i++) {for (int j = 0; j < row; j++){printf(">");scanf("%d", &m[i][j]);}}
    int y = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++){
            if (i == j && m[i][j] != 1){y++;}
            if (i != j && m[i][j] != 0){y++;}
        }
    }
    if (y == 0){printf("Indentity matrix");} else {printf("Not an Identity Matrix");}
    return 0;
}