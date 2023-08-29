#include <stdio.h>
#include <stdlib.h>

#define NUM_MOVIMENTOS 4
#define OBSTACULO 1
#define JA_PASSEI 2

const char CIMA = 'C';
const char BAIXO = 'B';
const char DIREITA = 'D';
const char ESQUERDA = 'E';

typedef struct{
    int linha;
    int coluna;
}tCelula;

void LeMatriz(int linhas, int colunas, int matriz[linhas][colunas]);

void ResetaMat(int linhas, int colunas, int mat[linhas][colunas]);

void LePreferencia(char* preferencia);

int AcabouJogo(int linhas, int colunas, int mapa[linhas][colunas], tCelula posicaoAtual, tCelula posicaof);

int NaoTemPraOndeIr(int linhas, int colunas, int mapa[linhas][colunas], tCelula posicaoAtual);

int EhMesmaCelula(tCelula c1, tCelula c2);

char EscolheDirecao(char* preferencia, int linhas, int colunas, int mapa[linhas][colunas], tCelula posicao);

int DirecaoEhPossivel(char direcao, int linhas, int colunas, int mapa[linhas][colunas], tCelula posicao);

tCelula LeCelula();

tCelula NormalizaCelula(tCelula celula);

tCelula RealizaMovimentos(char* preferencia, int linhas, int colunas, int mapa[linhas][colunas], tCelula celulaAnterior);

tCelula AtualizaPosicao(tCelula posicao, char direcao);

void ImprimePosicao(tCelula posicao);

int main(){

    int M = 0, N = 0;
    scanf("%d %d\n", &M, &N);

    int mapa[M][N];
    LeMatriz(M, N, mapa);

    tCelula posicaoi = LeCelula(), posicaof = LeCelula();

    char preferencia[NUM_MOVIMENTOS];
    LePreferencia(preferencia);

    tCelula posicaoAtual = posicaoi;
    tCelula posicaoAnterior;

    while(!AcabouJogo(M, N, mapa, posicaoAnterior, posicaof)){
        ImprimePosicao(posicaoAtual);
        posicaoAnterior = posicaoAtual;
        posicaoAtual = RealizaMovimentos(preferencia, M, N, mapa, posicaoAnterior);
    }

    return 0;
}

void LeMatriz(int linhas, int colunas, int matriz[linhas][colunas]){
    int i = 0, j = 0;

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

tCelula LeCelula(){
    tCelula celulatemp;
    scanf("%d %d", &celulatemp.linha, &celulatemp.coluna);

    celulatemp = NormalizaCelula(celulatemp);

    return celulatemp;
}

tCelula NormalizaCelula(tCelula celula){
    celula.linha -= 1;
    celula.coluna -= 1;

    return celula;
}

void LePreferencia(char* preferencia){
    int i = 0;
    
    scanf("%*[^BCDE]"); 
    for(i = 0; i < NUM_MOVIMENTOS; i++){
        scanf("%c", &preferencia[i]);
    }
}

int AcabouJogo(int linhas, int colunas, int mapa[linhas][colunas], tCelula posicaoAtual, tCelula posicaof){
    return(EhMesmaCelula(posicaoAtual, posicaof)); 
}

int EhMesmaCelula(tCelula c1, tCelula c2){
    return (c1.linha == c2.linha && c2.coluna == c1.coluna);
}

tCelula RealizaMovimentos(char* preferencia, int linhas, int colunas, int mapa[linhas][colunas], tCelula celulaAnterior){
    tCelula celulaAtual;

    mapa[celulaAnterior.linha][celulaAnterior.coluna] = JA_PASSEI;
    char direcao = EscolheDirecao(preferencia, linhas, colunas, mapa, celulaAnterior);
    celulaAtual = AtualizaPosicao(celulaAnterior, direcao);

    return celulaAtual;
}

char EscolheDirecao(char* preferencia, int linhas, int colunas, int mapa[linhas][colunas], tCelula posicao){
    char direcao;
    int i = 0;

    for(i = 0; i < NUM_MOVIMENTOS; i++){
        if(DirecaoEhPossivel(preferencia[i], linhas, colunas, mapa, posicao)){
            direcao = preferencia[i];
            break;
        }
    }
    if(i == 4){
        exit(0);
    }
    return direcao;
}

int DirecaoEhPossivel(char direcao, int linhas, int colunas, int mapa[linhas][colunas], tCelula posicao){
    
    if(direcao == DIREITA){
        if(posicao.coluna == colunas - 1){
            return 0;
        }
        posicao.coluna++;
    } 
    else if(direcao == ESQUERDA){
        if(posicao.coluna == 0){
            return 0;
        }
        posicao.coluna--;
    }
    else if(direcao == BAIXO){
        if(posicao.linha == linhas - 1){
            return 0;
        }
        posicao.linha++;
    }
    else if(direcao == CIMA){
        if(posicao.linha == 0){
            return 0;
        }
        posicao.linha--;
    }
    
    return(mapa[posicao.linha][posicao.coluna] != OBSTACULO && mapa[posicao.linha][posicao.coluna] != JA_PASSEI);
}

tCelula AtualizaPosicao(tCelula posicao, char direcao){
    if(direcao == DIREITA){
        posicao.coluna++;
    } 
    else if(direcao == ESQUERDA){
        posicao.coluna--;
    }
    else if(direcao == BAIXO){
        posicao.linha++;
    }
    else if(direcao == CIMA){
        posicao.linha--;
    }

    return posicao;
}

void ImprimePosicao(tCelula posicao){
    printf("(%d,%d) ", posicao.linha + 1, posicao.coluna + 1);
}