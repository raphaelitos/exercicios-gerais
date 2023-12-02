#include "estabelecimento.h"
#include "vector.h"
#include <stdlib.h>
#include <string.h>

struct Estabelecimento{
    Vector *produtos;
};

tEstabelecimento *CriaEstabelecimento(){
    tEstabelecimento *e = (tEstabelecimento*)malloc(sizeof(tEstabelecimento));
    if(!e){
        printf("Erro na criacao de estabelecimento!\n");
        exit(0);
    }

    e->produtos = VectorConstruct();

    return e;
}

void DestroiEstabelecimento(tEstabelecimento *estabelecimento){
    if(!estabelecimento){
        printf("estabelecimento nulo enviado para liberacao!\n");
        return;
    }
    VectorDestroy(estabelecimento->produtos, DestroiProduto);
    free(estabelecimento);
}

void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto){
    VectorPushBack(estabelecimento->produtos, produto);
}

void LeEstabelecimento(tEstabelecimento *estabelecimento){
    
    if(estabelecimento == NULL){
        printf("Estabelecimento null enviado para leitura!\n");
        return;
    }
    
    char nome[101];
    scanf("%[^\n]", nome);

    FILE *arq = fopen(nome, "rb");
    if(!arq){
        printf("Falha ao abrir o arquivo!\n");
        exit(1);
    }

    int qtd;
    fread(&qtd, sizeof(int), 1, arq);

    for(int i = 0; i < qtd; i++){
        tProduto *p = LeProduto(arq);
        AdicionaProdutoEstabelecimento(estabelecimento, p);
    }
    fclose(arq);
}

void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento){
    if(estabelecimento == NULL){
        printf("Estabelecimento nulo enviado para impressao!\n");
        return;
    }
    int flag = 1;
    
    printf("Produtos em falta:\nCodigo;Nome;Preco\n");
    for(int i = 0; i < VectorSize(estabelecimento->produtos); i++){
        tProduto* aux = (tProduto*)VectorGet(estabelecimento->produtos, i);
        if(!TemEstoqueProduto(aux)){
            ImprimeProduto(aux);
            flag = 0;
        }
    }

    if(flag){
        printf("Nao ha produtos em falta!");
    }
}