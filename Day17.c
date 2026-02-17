// Problem: Write a program to find the maximum and minimum values present in a given array of integers.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the maximum and minimum elements

// Example:
// Input:
// 6
// 3 5 1 9 2 8

// Output:
// Max: 9
// Min: 1

#include <stdio.h>
int main() {
    int n, max, min;
    printf("Enter no. of elements >"); scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int x; printf("Enter element >"); scanf("%d", &x);
        if (i == 0) {max = x; min = x;}
        if (x > max){max = x;}
        else if (x < min){min = x;}
    }
    printf("MAX : %d    MIN : %d", max, min);
    return 0;
}