#include <stdio.h>

int fibonacci(int n);

int main(){

    int N = 0;
    scanf("%d", &N);

    printf("%d", fibonacci(N));

    return 0;
}

int fibonacci(int n){
    if(!n){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}