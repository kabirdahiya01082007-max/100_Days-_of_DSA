// Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

// Input:
// - First line: two integers m and n representing the number of rows and columns
// - Next m lines: n integers each representing the elements of the matrix

// Output:
// - Print "Symmetric Matrix" if the given matrix is symmetric
// - Otherwise, print "Not a Symmetric Matrix"

// Example:
// Input:
// 3 3
// 1 2 3
// 2 4 5
// 3 5 6

// Output:
// Symmetric Matrix

// Explanation:
// The matrix is square (3 × 3) and for every i and j, element[i][j] = element[j][i].

#include <stdio.h>

int main() {
    int n; printf("Enter no. of rows >"); scanf("%d", &n);
    int m; printf("Enter no. of columns >"); scanf("%d", &m);
    int a[n][m];
    for (int i = 0; i < n; i++){for (int j = 0; j < m; j++){printf("Enter element %d, %d >", i+1, j+1); scanf("%d", &a[i][j]);}}
    int d = 0;
    for (int i = 0; i < n; i++){for (int j = 0; j < m; j++){if (a[i][j] != a[j][i]){d++;}}}
    if (d == 0) {
        printf("The matrix is symmetric");
    } else {
        printf("the matrix is not symmetric");
    }

    return 0;
}