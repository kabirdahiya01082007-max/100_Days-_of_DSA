// Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

// Input:
// - First line: two integers m and n
// - Next m lines: n integers each

// Output:
// - Print the sum of the primary diagonal elements

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 15

// Explanation:
// 1 + 5 + 9 = 15

#include <stdio.h>

int main() {
    int row;printf("square matrix side >>>"); scanf("%d", &row);
    int m[row][row];
    for (int i = 0; i < row; i++) {for (int j = 0; j < row; j++){printf(">");scanf("%d", &m[i][j]);}}
    int y = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++){
            if (i == j){y += m[i][j];}
        }
    }
    printf("Sum is %d", y);
    return 0;
}