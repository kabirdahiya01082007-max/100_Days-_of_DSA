// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to find intersection
struct node* findIntersection(struct node* head1, struct node* head2) {
    if (!head1 || !head2) return NULL;

    struct node *p1 = head1;
    struct node *p2 = head2;

    while (p1 != p2 && p1!= NULL && p2 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

int main() {
    int n, m;

    struct node *head1 = NULL, *head2 = NULL;
    struct node *temp, *newNode;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (!head1) head1 = newNode;
        else {
            temp = head1;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (!head2) head2 = newNode;
        else {
            temp = head2;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    

    struct node* result = findIntersection(head1, head2);

    if (result)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}




