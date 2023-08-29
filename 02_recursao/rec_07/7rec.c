#include <stdio.h>

int somaDigitos(int n);

int main(){
    
    int n = 0;
    scanf("%d", &n);
    
    printf("%d"\n, somaDigitos(n));

    return 0;
}

int somaDigitos(int n){
    if(n/10 == 0){ //caso em que se trata de um número menor que 10
        return n; 
    }

    return n % 10 + (somaDigitos(n/10));
}