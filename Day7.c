#include <stdio.h>

int fib(int x){
    int a = 0, b = 1;

    if (x == 1) return a;
    else if (x == 2) return b;

    for (int i = 0; i < x - 2; i++){
        int c = a;
        a = b;
        b = c + b;
    }
    return b;
}

int main(){
    int x;
    printf("Enter the number >");
    scanf("%d", &x);

    printf("%d", fib(x));
    return 0;
}