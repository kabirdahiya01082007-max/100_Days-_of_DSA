#include <stdio.h>
#include <string.h>

#define MAX 100
#define EMPTY -1

int table[MAX];

int main() {
    int m, n;
    scanf("%d", &m);   // table size
    scanf("%d", &n);   // number of operations

    // Initialize table
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    while (n--) {
        scanf("%s %d", op, &key);

        int h = key % m;

        if (strcmp(op, "INSERT") == 0) {
            int i = 0;
            while (i < m) {
                int idx = (h + i * i) % m;

                if (table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
                i++;
            }
        }

        else if (strcmp(op, "SEARCH") == 0) {
            int i = 0, found = 0;

            while (i < m) {
                int idx = (h + i * i) % m;

                if (table[idx] == EMPTY)
                    break;

                if (table[idx] == key) {
                    found = 1;
                    break;
                }
                i++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}