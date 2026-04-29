#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Queue structure (node + horizontal distance)
struct QNode {
    struct Node* node;
    int hd;
};

struct QNode queue[100];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct QNode dequeue() {
    return queue[front++];
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = createNode(arr[0]);

    struct Node* q[100];
    int f = 0, r = 0;

    q[r++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = q[f++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    // Map using array (shift by +50 to handle negative HD)
    int map[100][100]; // store values
    int size[100] = {0};

    int offset = 50;
    int minHD = 50, maxHD = 50;

    enqueue(root, 0);

    while (front < rear) {
        struct QNode temp = dequeue();
        struct Node* curr = temp.node;
        int hd = temp.hd + offset;

        map[hd][size[hd]++] = curr->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left)
            enqueue(curr->left, temp.hd - 1);

        if (curr->right)
            enqueue(curr->right, temp.hd + 1);
    }

    // Print vertical order
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < size[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}