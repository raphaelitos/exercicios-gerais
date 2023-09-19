#include "matrix_utils.h"
#include <stdio.h>

void PrintMenu();

void ErrorMessage();

int main(){
    
    int rows1 = 0, cols1 = 0;
    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);

    int rows2 = 0, cols2 = 0;
    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    int option = 0;

    while(option != 6){
        PrintMenu();
        scanf("%d", &option);
        
        if(option == 1){
            int result[rows1][cols1];
            if(possible_matrix_sum(rows1, cols1, rows2, cols2)){
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            }
            else{
                ErrorMessage();
            }
        }
        
        else if(option == 2){
            int result[rows1][cols1];
            if(possible_matrix_sub(rows1, cols1, rows2, cols2)){
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            }
            else{
                ErrorMessage();
            }
        }
        
        else if(option == 3){
            int mult[rows1][cols2];
            if(possible_matrix_multiply(cols1, rows2)){
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, mult);
            }
            else{
                ErrorMessage();
            }
        }

        else if(option == 4){
            int scalar = 0, m = 0;
            if(scanf("%d %d", &scalar, &m) != 2){
                continue;
            }

            if(m == 1){
                scalar_multiply(rows1, cols1, matrix1, scalar);
            }
            else{
                scalar_multiply(rows2, cols2, matrix2, scalar);
            }
        }
        else if(option == 5){
            int trans1[cols1][rows1], trans2[cols2][rows2];
            
            transpose_matrix(rows1, cols1, matrix1, trans1);
            transpose_matrix(rows2, cols2, matrix2, trans2);
        }
    }

    return 0;
}


void PrintMenu(){
    printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    prinft("5 - Transposta de uma matriz\n6 - Encerra o programa\n");
    printf("Opcao escolhida: ");
}

void ErrorMessage(){
    printf("Erro: as dimensoes da matriz nao correspondem\n");
}