#include "utils.h"

// imprime os números em sua ordem original quando o primeiro é menor ou
// igual ao segundo e em ordem inversa quando o primeiro é maior do que o segundo.



int TrocaInterios(int * n1, int * n2){
    
    if(*n1 <= *n2){
        return 0;
    }
    
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;

    return 1;

}