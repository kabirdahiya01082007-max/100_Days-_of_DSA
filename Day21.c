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
    return 0;
}