/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50*/


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
    struct node * h1 = head;
    while(h1 != NULL){
        printf("%d ", h1->data); h1 = h1->next;
    }

    int t; printf("\nEnter the key to delete >"); scanf("%d", &t);
    struct node * h2 = head, *p;
    if(h2->data == t){
        head = h2->next;
        free(h2);
    }
    else {
        while(h2 != NULL && h2->data != t){
            p = h2;
            h2 = h2->next;
        }
        p->next = h2->next;
        free(h2);
    } 
    struct node * h3 = head;
    while(h3 != NULL){
        printf("%d ", h3->data); h3 = h3->next;
    }   
    return 0;
}