// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)

// Output:
// - Print the number of times the key appears in the linked list

// Example:
// Input:
// 6
// 10 20 30 20 40 20
// 20

// Output:
// 3

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * next;
};

int main() {
    int n; printf("Enter the no. of nodes >"); scanf("%d", &n);
    struct node * head = NULL, *x;
    for (int i = 0; i < n; i++){
        x = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of node %d >", i+1); scanf("%d", &x->data);
        x->next = NULL;
        if (head == NULL){head = x;}
        else {
            struct node * h1 = head;
            while(h1->next != NULL){h1 = h1->next;}
            h1->next = x;
        }
    }
    int c; printf("Enter the number to count >"); scanf("%d", &c);
    int count = 0;
    struct node * h1 = head;
    while(h1 != NULL){
        if (h1->data == c){count++;}
        h1 = h1->next;
    }
    printf("%d", count);
    return 0;
}