#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue for tree construction
struct Node* queue[100];
int front = 0, rear = 0;

// Enqueue
void enqueue(struct Node* node) {
    queue[rear++] = node;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n, val;
    scanf("%d", &n);

    if (n == 0) return 0;

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Create root
    struct Node* root = createNode(arr[0]);

    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* curr = dequeue();

        // Left child
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    // Print inorder
    inorder(root);

    return 0;
}