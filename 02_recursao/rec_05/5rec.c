#include <stdio.h>

int fatorial(int n);

int main(){
    
    int N = 0;
    scanf("%d", &N);
    printf("%d\n", fatorial(N));
    return 0;
}

int fatorial(int n){
    if(n <= 1){
        return 1;
    }
    return (n * fatorial(n - 1));
}