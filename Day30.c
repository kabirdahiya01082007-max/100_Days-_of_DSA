// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    int power;
    struct node * next;
};

int main() {
    int n; printf("Enter the no. of expressions >"); scanf("%d", &n);
    struct node * head = NULL, *x;
    for (int i = 0; i < n; i++){
        x = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of cofficient %d >", i+1); scanf("%d", &x->data);
        printf("Enter data of power of x %d >", i+1); scanf("%d", &x->power);
        x->next = NULL;
        if (head == NULL){head = x;}
        else {
            struct node * h1 = head;
            while(h1->next != NULL){h1 = h1->next;}
            h1->next = x;
        }
    }
    struct node * h1 = head;
    while(h1 != NULL){
        if (h1->power != 0 && h1->power != 1){
            printf("%dx^%d + ", h1->data, h1->power); h1 = h1->next;
        } else if (h1->power == 1){
            printf("%dx + ", h1->data); h1 = h1->next; 
        } else {
            printf("%d", h1->data); h1 = h1->next; 
        }   
    }
    return 0;
}