// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {

    int n;
    printf("Enter the no. of nodes > ");
    scanf("%d", &n);

    struct node *head = NULL, *x;

    for(int i=0;i<n;i++){
        x = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&x->data);
        x->next = NULL;

        if(head == NULL)
            head = x;
        else{
            struct node *temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = x;
        }
    }

    int m;
    printf("Enter the no. of nodes > ");
    scanf("%d", &m);

    struct node *head2 = NULL, *y;

    for(int i=0;i<m;i++){
        y = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&y->data);
        y->next = NULL;

        if(head2 == NULL)
            head2 = y;
        else{
            struct node *temp = head2;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = y;
        }
    }

    struct node *head3 = NULL, *z, *tail=NULL;

    while(head != NULL && head2 != NULL){

        z = (struct node*)malloc(sizeof(struct node));

        if(head->data <= head2->data){
            z->data = head->data;
            head = head->next;
        }
        else{
            z->data = head2->data;
            head2 = head2->next;
        }

        z->next = NULL;

        if(head3 == NULL){
            head3 = z;
            tail = z;
        }
        else{
            tail->next = z;
            tail = z;
        }
    }

    while(head != NULL){
        z = (struct node*)malloc(sizeof(struct node));
        z->data = head->data;
        z->next = NULL;

        tail->next = z;
        tail = z;

        head = head->next;
    }

    while(head2 != NULL){
        z = (struct node*)malloc(sizeof(struct node));
        z->data = head2->data;
        z->next = NULL;

        tail->next = z;
        tail = z;

        head2 = head2->next;
    }

    struct node *temp = head3;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}