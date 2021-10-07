#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    
    int **record;
    record = (int**)malloc(sizeof(int*)*matSize);
    for (int i = 0; i < matSize; i++){
        record[i] = (int*)malloc(sizeof(int)*matColSize[0]);
        for (int j = 0; j < matColSize[0]; j++){
            record[i][j] = -1;
        }
    }
    
    int i, j, origi, origj;
    
    for (i = 0; i < matSize; i++){
        for (j = 0; j < matColSize[0]; j++){
            
            origi = i;
            origj = j;
            if (mat[i][j] == 0){
                record[i][j] = 0;
                j++;
                while(j < matColSize[0] && mat[i][j] != 0 && (record[i][j] == -1 || record[i][j] > record[i][j-1]+1)){
                    record[i][j] = record[i][j-1]+1;
                    j++;
                }
                i = origi+1, j = origj;
                while(i < matSize && mat[i][j] != 0 && (record[i][j] == -1 || record[i][j] > record[i-1][j]+1)){
                    record[i][j] = record[i-1][j]+1;
                    i++;
                }
                i = origi, j = origj-1;
                while(j >= 0 && mat[i][j] != 0 && (record[i][j] == -1 || record[i][j] > record[i][j+1]+1)){
                    record[i][j] = record[i][j-1]+1;
                    j--;
                }
                i = origi-1, j = origj;
                while(i >= 0 && mat[i][j] != 0 && (record[i][j] == -1 || record[i][j] > record[i+1][j]+1)){
                    record[i][j] = record[i-1][j]+1;
                    i--;
                }
            }
            i = origi, j = origj;
        }
    }
    return record;
}

int main(){
    /*int mat[3][3] = {{0,0,0},{0,1,0},{0,0,0}};*/
    int **mat;
    mat = (int**)malloc(sizeof(int*)*3);
    for (int i = 0; i < 3; i++){
        mat[i] = (int*)malloc(sizeof(int)*3);
    }
    int matColSize[] = {3,3,3}; 
    int **output;
    int *returnSize, **returnColumnSizes;
    output = updateMatrix(mat, 3, matColSize, returnSize, returnColumnSizes);


    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }
}
