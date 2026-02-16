// Problem: Given an array of integers, count the frequency of each distinct element and print the result.

// Input:
// - First line: integer n (size of array)
// - Second line: n integers

// Output:
// - Print each element followed by its frequency in the format element:count

// Example:
// Input:
// 5
// 1 2 2 3 1

// Output:
// 1:2 2:2 3:1

#include <stdio.h>

int main() {
    int n; printf("Enter the no. of elements >"); scanf("%d", &n);
    int Arr[n], v[n];
    for (int i = 0; i < n; i++){v[i] = 0; printf("Enter element >"); scanf("%d", &Arr[i]);}

    for (int i = 0; i < n; i++){
        if (v[i] == 1){continue;}
        int count = 1;
        for (int j = i+1; j<n; j++){
            if (Arr[i] == Arr[j]){
                count++;
                v[j] = 1;
            }
        }
        printf("%d:%d ", Arr[i], count);
    }
    return 0;
}