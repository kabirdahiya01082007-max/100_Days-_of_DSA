// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

// Input:
// - First line: integer n (number of operations)
// - Next n lines: operation type and value (if applicable)
//   - 1 value: push value
//   - 2: pop
//   - 3: display

// Output:
// - For display: print stack elements from top to bottom
// - For pop: print popped element or 'Stack Underflow'




#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int arr[n], top = -1;
    printf("1. push, 2. pop, 3. display. 4. Exit\n1");
    int x = 0;
    while (x != 4){
        printf("Choice >"); scanf("%d", &x);
        if(x == 4){break;}
        switch (x) {
            case 1:
                if (top >= n-1){
                    printf("Stack is full...");
                } else {
                    top++;
                    printf("Enter number >"); scanf("%d", &arr[top]);
                }
                break;
            case 2:
                if(top < 0){printf("Stack empty...");}
                else {
                    printf("%d\n", arr[top--]);
                }
                break;
            case 3 : {
                int j = top+1;
                while (j--){printf("%d ", arr[j]);}
                printf("\n");
                break;  
            }      
        } 
    }
    return 0;
}