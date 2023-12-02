#include "produto.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Produto{
    int codigo;
    char nome[51];
    float preco;
    int qtd;
};

tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade){
    tProduto *p = (tProduto*)malloc(sizeof(tProduto));
    if(p == NULL){
        printf("Falha em alocar novo produto!\n");
        exit(0);
    }
    
    p->codigo = codigo;
    strcpy(p->nome, nome);
    p->preco = preco;
    p->qtd = quantidade;

    return p;
}

void DestroiProduto(tProduto *produto){
    free(produto);
}

tProduto *LeProduto(FILE *arquivo){
    if(arquivo == NULL){
        printf("Arquivo nulo mandado para a leitura de aluno\n");
        tProduto* nulo = NULL;
        return nulo;
    }
    
    int codigo, qtd;
    float preco;
    char nome[51];

    fread(&codigo, sizeof(int), 1, arquivo);
    fread(nome, sizeof(char), 50, arquivo);
    fread(&preco, sizeof(float), 1, arquivo);
    fread(&qtd, sizeof(int), 1, arquivo);
    
    tProduto *prod = CriaProduto(codigo, nome, preco, qtd);

    return prod;
}

int TemEstoqueProduto(tProduto *produto){
    if(produto) return(produto->qtd);
    
    printf("ERRO [TemEstoque]: produto NULL\n");
    return 0;
}

void ImprimeProduto(tProduto *produto){
    
    if(produto){
        printf("%d;%s;%.2f\n", produto->codigo, produto->nome, produto->preco);
        return;
    }
    printf("ERRO [ImprimeProduto]: produto NULL\n");
    return;
}