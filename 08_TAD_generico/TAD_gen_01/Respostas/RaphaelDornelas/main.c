#include "tadgen.h"
#include <stdio.h>

int main(){
    Type tipo;
    int numElem;
    scanf("%d %d", &tipo, &numElem);

    tGeneric* vet = CriaGenerico(tipo, numElem);

    LeGenerico(vet);
    ImprimeGenerico(vet);
    DestroiGenerico(vet);

}