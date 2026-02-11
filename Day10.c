// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards

#include <stdio.h>

int main() {
    char c[100];
    printf("Enter string > ");
    scanf("%s", c);

    int i = 0;
    while (c[i] != '\0') i++;

    int flag = 1;
    for (int j = 0; j < i / 2; j++) {
        if (c[j] != c[i - 1 - j]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}