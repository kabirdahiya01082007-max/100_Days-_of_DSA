// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

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
    int k; printf("Enter the no. of nodes to rotate by >"); scanf("%d", &k);
    struct node * h1 = head;
    for (int i = 0; i < n-k; i++){
        h1 = h1->next;
    }
    struct node * h2= head;
    while (h2->next!=NULL){
        h2 = h2->next;
    }
    h2->next = head;
    head = h1->next;
    h1->next = NULL;

    struct node * h3= head;
    while(h3= NULL){
        printf("%d ", h3->data); h3= h3->next;
    }
    return 0;
}