// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the count of subarrays having sum zero

// Example:
// Input:
// 6
// 1 -1 2 -2 3 -3

// Output:
// 6

// Explanation: A subarray is a continuous part of the array. 
// For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3],
//  and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.

#include <stdio.h>
int main() {
    int n; printf("Enter the no. of elements >"); scanf("%d", &n);
    int Arr[n];
    for (int i = 0; i<n; i++){printf("Enter element %d >", i+1); scanf("%d", &Arr[i]);}
    int count = 0, n1 = 0;
    while (n1 < n){
        for (int n2 = n1+1; n2<n; n2++){
            int sum = Arr[n1];
            for (int n3 = n1+1; n3 <= n2; n3++){
                sum += Arr[n3];
            }
            if (sum == 0){count++;}
        }
        n1++;
    }
    printf("%d", count);
    return 0;
}    