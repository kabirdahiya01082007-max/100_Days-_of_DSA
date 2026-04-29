#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix = 0, maxLen = 0;

    // Hashing using arrays (simple)
    int sum[MAX * 2];
    int index[MAX * 2];

    for (int i = 0; i < MAX * 2; i++)
        index[i] = -1;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        if (prefix == 0) {
            maxLen = i + 1;
        }

        int key = prefix + MAX;  // shift for negative sums

        if (index[key] == -1) {
            index[key] = i;
        } else {
            int len = i - index[key];
            if (len > maxLen)
                maxLen = len;
        }
    }

    printf("%d", maxLen);

    return 0;
}