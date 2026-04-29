#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;
int count = 0;

// push_front
void push_front(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = front;

    if (front == NULL) {
        front = rear = temp;
    } else {
        front->prev = temp;
        front = temp;
    }
    count++;
}

// push_back
void push_back(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = rear;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    count++;
}

// pop_front
void pop_front() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", temp->data);

    front = front->next;
    if (front != NULL)
        front->prev = NULL;
    else
        rear = NULL;

    free(temp);
    count--;
}

// pop_back
void pop_back() {
    if (rear == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = rear;
    printf("%d\n", temp->data);

    rear = rear->prev;
    if (rear != NULL)
        rear->next = NULL;
    else
        front = NULL;

    free(temp);
    count--;
}

// front element
void getFront() {
    if (front == NULL) printf("-1\n");
    else printf("%d\n", front->data);
}

// rear element
void getBack() {
    if (rear == NULL) printf("-1\n");
    else printf("%d\n", rear->data);
}

// empty
void isEmpty() {
    printf("%s\n", (front == NULL) ? "true" : "false");
}

// size
void size() {
    printf("%d\n", count);
}

// display (final state)
void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') { // push_front
            scanf("%d", &x);
            push_front(x);
        }
        else if (op[0] == 'p' && op[5] == 'b') { // push_back
            scanf("%d", &x);
            push_back(x);
        }
        else if (op[0] == 'p' && op[1] == 'o' && op[4] == 'f') { // pop_front
            pop_front();
        }
        else if (op[0] == 'p' && op[1] == 'o' && op[4] == 'b') { // pop_back
            pop_back();
        }
        else if (op[0] == 'f') { // front
            getFront();
        }
        else if (op[0] == 'b') { // back
            getBack();
        }
        else if (op[0] == 'e') { // empty
            isEmpty();
        }
        else if (op[0] == 's') { // size
            size();
        }
    }

    // Final state
    display();

    return 0;
}