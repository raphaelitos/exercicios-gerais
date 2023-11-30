#include "fila.h"
#include "movel.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void destroy(void *m){
    DestroiMovel((tMovel*)m);
}

int main(){
    char opcao[21];
    Fila *fila = FilaConstruct();
    int num = 0;
    scanf("%d\n", &num);
    for(int i = 0; i < num; i++){
        scanf("%s", opcao);
        if(!strcmp(opcao, "ENTRADA")){
            tMovel *movel = LeMovel();
            FilaPush(fila, movel);
        }
        else if(!strcmp(opcao, "PRODUZIR")){
            if(FilaSize(fila) == 0){
                printf("Fila vazia!\n");
            }
            else{
                tMovel *movel = (tMovel*)FilaPop(fila);
                ImprimeMovel(movel);
                DestroiMovel(movel);
            }

        }
    }
    
    FilaDestroy(fila, destroy);

    return 0;
}