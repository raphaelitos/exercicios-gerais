#include "matrix_utils.h"

void matrix_read(int rows, int cols, int matrix[rows][cols]){
    int i = 0, j = 0;

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols]){
    int i = 0, j = 0;

    for(i = 0; i < rows; i++){
        printf("|");
        for(j = 0; j < cols; j++){
            printf("%d", &matrix[i][j]);
            if(j < cols - 1){
                printf(" ");
            }
        }
        printf("|\n");
    }
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2){
    return(rows1 == rows2 && cols1 == cols2);
    
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2){
    return(rows1 == rows2 && cols1 == cols2);
}

int possible_matrix_multiply(int cols1, int rows2){
   return cols1 == rows2; 
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1],
                int rows2, int cols2, int matrix2[rows2][cols2],
                int result[rows1][cols1]){
    
    int i = 0, j = 0;

    for(i = 0; i < rows1; i++){
        for(j = 0; j < cols1; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    matrix_print(rows1, cols1, matrix1);
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1],
                int rows2, int cols2, int matrix2[rows2][cols2],
                int result[rows1][cols1]){
    
    int i = 0, j = 0;

    for(i = 0; i < rows1; i++){
        for(j = 0; j < cols1; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    matrix_print(rows1, cols1, matrix1);

}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1],
                    int rows2, int cols2, int matrix2[rows2][cols2],
                    int result[rows1][cols2]){

    int i = 0, j = 0, idAux = 0, cedulaTemp = 0;

    for(i = 0; i < rows1; i++){
        for(j = 0; j < cols2; j++){
            cedulaTemp = 0;
            for(idAux = 0; idAux < cols1; idAux++){
                cedulaTemp += matrix1[i][idAux] + matrix2[idAux][j];
            }
            result[i][j] = cedulaTemp;
        }
    }
    matrix_print(rows1, cols2, result);

}

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){

    int i = 0, j = 0;

    for(i = 0; i < cols; i++){
        for(j = 0; j < rows; j++){
            result[i][j] = matrix[j][i];
        }
    }
    matrix_print(cols, rows, result[cols][rows]);
}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar){
    int i = 0, j = 0;
    
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            matrix[i][j] *= scalar;
        }
    }
    matrix_print(rows, cols, matrix);
}