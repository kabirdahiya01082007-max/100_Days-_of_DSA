#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char postfix[100];
    int i = 0;

    printf("Enter postfix expression (space separated): ");
    fgets(postfix, sizeof(postfix), stdin);

    while (postfix[i] != '\0') {
        
        // Skip spaces
        if (postfix[i] == ' ') {
            i++;
            continue;
        }

        // If digit (handle multi-digit numbers)
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(num);
        }
        else {
            int val1 = pop();
            int val2 = pop();
            int result;

            switch (postfix[i]) {
                case '+': result = val2 + val1; break;
                case '-': result = val2 - val1; break;
                case '*': result = val2 * val1; break;
                case '/': result = val2 / val1; break;
                default:
                    printf("Invalid operator\n");
                    return 1;
            }
            push(result);
            i++;
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}