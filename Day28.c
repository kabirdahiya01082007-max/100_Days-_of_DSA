#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * prev;
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
            struct node * h1 = head, *h2 = head;
            while(h1->next != NULL){h2 = h1; h1 = h1->next;}
            h1->prev = h2;
            h1->next = x;
        }
    }
    struct node *h2 = head;
    while (h2->next != NULL){h2 = h2->next;}
    h2->next = head;
    head->prev = h2;
    struct node * h1 = head;
    printf("%d ", h1->data); h1 = h1->next;
    while(h1 != head){
        printf("%d ", h1->data); h1 = h1->next;
    }

    return 0;
}