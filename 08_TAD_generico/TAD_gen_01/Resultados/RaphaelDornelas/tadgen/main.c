#include "tadgen.h"
#include <stdio.h>

int main(){
    int tipo;
    int numElem;
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: ");
    scanf("%d %d", &tipo, &numElem);

    tGeneric* vet = CriaGenerico(tipo, numElem);

    LeGenerico(vet);
    ImprimeGenerico(vet);
    DestroiGenerico(vet);
    return 0;
}