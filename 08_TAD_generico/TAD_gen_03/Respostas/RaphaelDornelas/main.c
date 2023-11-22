#include "relatorio.h"
#include "aluno.h"
#include <stdio.h>

int main(){
    Vector *vet = VectorConstruct();
    int num = 0;
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        tAluno *a = CriaAluno();
        LeAluno(a);
        VectorPushBack(vet, a);
    }

    ImprimeRelatorio(vet);

    VectorDestroy(vet, DestroiAluno);

    return 0;
}