// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom



#include <stdio.h>

int main() {
    printf("no. of elements >");int n; scanf("%d", &n);
    int arr[n], top = -1;
    
    int x = 0;
    for (int i = 0; i <= n-1; i++){
        scanf("%d", &arr[i]);
        top = i;
    }
    printf("pop >");int r; scanf("%d", &r);
    top = top - r;
    top = top +1;
    while (top--){printf("%d ", arr[top]);}

    return 0;
}