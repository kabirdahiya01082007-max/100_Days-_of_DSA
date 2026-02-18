// Problem: Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

// Example:
// Input:
// 5
// 1 2 3 4 5
// 2

// Output:
// 4 5 1 2 3

#include <stdio.h>
int main() {
    int n; printf("Enter the no. of elements >"); scanf("%d", &n);
    int Arr[n];
    for (int i = 0; i < n; i++){printf("Enter element >"); scanf("%d", &Arr[i]);}
    int y; printf("Enter index >"); scanf("%d", &y);
    int ch[n];
    for (int i = y+1; i < n; i++){ch[i-y-1] = Arr[i];}
    for (int i = 0; i <= y; i++){ch[i+y] = Arr[i];}
    for (int i = 0; i < n; i++){printf("%d, ", ch[i]);}
    return 0;
}