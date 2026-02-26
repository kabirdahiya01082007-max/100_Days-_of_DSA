// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

// Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.

#include <stdio.h>

int main() {
    int n; printf("Enter the no. of elements >"); scanf("%d", &n);
    int Arr[n];
    for (int i = 0; i<n; i++){printf("Enter element %d >", i+1); scanf("%d", &Arr[i]);}
    int w, v, sum = 99999;
    for (int i = 0; i<n; i++){
        for (int j = i + 1; j < n; j++){
            int sum1 = Arr[i] + Arr[j];
            if ((sum1 >= 0 && sum1 < sum)||(sum1 <= 0 && sum1 > sum)){
                sum = sum1; w = Arr[i]; v = Arr[j];
            }
        }
    }
    printf("%d %d", w, v);
    return 0;
}