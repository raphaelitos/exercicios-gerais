#include "usuario.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Usuario {
    char nome[50]; /**< Nome do usuário. */
    char cpf[15]; /**< CPF do usuário. */
};

tUsuario *CriaUsuario(){
    tUsuario* userI = malloc(sizeof(tUsuario));
    if(userI == NULL){
        printf("Falha em criar usuario!\n");
        exit(0);
    }
    userI->nome[0] = '\0';
    userI->cpf[0] = '\0';
    
    return userI;
}

void DestroiUsuario(tUsuario *user){
    free(user);
}

void LeUsuario(tUsuario *user){
    scanf("%*[^A-Za-z]");
    scanf("%s %s", user->nome, user->cpf);
}

void ImprimeUsuario(tUsuario *user){
    printf("Nome: %s\nCPF: %s\n", user->nome, user->cpf);
}