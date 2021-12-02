#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include<limits.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void printArr(int **arr1, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%2d ", arr1[i][j]);
        }
        /*printf("    ");*/
        /*for (int j = 0; j < n; j++){*/
            /*printf("%2d ", arr2[i][j]);*/
        /*}*/
        printf("\n");
    }
    printf("----------\n");
}

/*
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
update:
    for (i = 0; i < matSize; i++){
        for (j = 0; j < matColSize[0]; j++){
            printf("{%2d, %2d}\n", i, j);
            
            origi = i;
            origj = j;
            if (mat[i][j] == 0 || record[i][j] != -1){
                if (record[i][j] == -1)  record[i][j] = 0;
                i = origi, j = origj+1;
                while(j < matColSize[0] && mat[i][j] != 0 && (record[i][j] == -1 || record[i][j] > record[i][j-1]+1)){
                    record[i][j] = record[i][j-1]+1;
                    j++;
                }
                printArr(record, matSize, matColSize[0]);

                i = origi+1, j = origj;
                while(i < matSize && mat[i][j] != 0 && (record[i][j] == -1 || record[i][j] > record[i-1][j]+1)){
                    record[i][j] = record[i-1][j]+1;
                    i++;
                }
                printArr(record, matSize, matColSize[0]);

                i = origi, j = origj-1;
                while(j >= 0 && mat[i][j] != 0 && (record[i][j] == -1 || record[i][j] > record[i][j+1]+1)){
                    record[i][j] = record[i][j+1]+1;
                    j--;
                }
                printArr(record, matSize, matColSize[0]);

                i = origi-1, j = origj;
                while(i >= 0 && mat[i][j] != 0 && (record[i][j] == -1 || record[i][j] > record[i+1][j]+1)){
                    record[i][j] = record[i+1][j]+1;
                    i--;
                }
                printArr(record, matSize, matColSize[0]);


            }
            i = origi, j = origj;
        }
    }
    for (i = 0; i < matSize; i++){
        for (j = 0; j < matColSize[0]; j++){
            if (record[i][j] == -1){
                goto update;
            }
        }
    }
    return record;
}
*/
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    // sanity check
    if(matSize == 0)
        return mat;
    int row = matSize;
    int col = *matColSize;
    *returnSize = row;
    *returnColumnSizes = (int *)calloc(row, sizeof(int));
    int **dist = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++) {
        dist[i] = (int*)malloc(col * sizeof(int));
        memset(dist[i], INT_MAX - 100000, col * sizeof(int));
        (*returnColumnSizes)[i] = col;
    }

    // first pass, check for top and left
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if (mat[i][j] == 0)
                dist[i][j] = 0;
            else {
                if (i > 0) {
                    if (dist[i-1][j] + 1 < dist[i][j])
                        dist[i][j] = dist[i-1][j] + 1;
                }
                if (j > 0) {
                    if (dist[i][j - 1] + 1 < dist[i][j])
                        dist[i][j] = dist[i][j - 1] + 1;
                }
            }
        }
    }

    // second pass, check for bottom and right
    for (int i = row - 1; i >= 0; i--) {
        for(int j = col - 1; j >= 0; j--) {
            if(i < row - 1) {
                if (dist[i + 1][j] + 1 < dist[i][j])
                    dist[i][j] = dist[i + 1][j] + 1;
            }
            if(j < col - 1) {
                if(dist[i][j + 1] < dist[i][j])
                    dist[i][j] = dist[i][j + 1] + 1;
            }
        }
    }

    return dist;
}
void two_dim_array_init(const int m, const int n, ...) {
    // array: mxn
    int **image;
    int imageSize = m;
    int *imageColSize;

    image = (int**)malloc(sizeof(int*)*m);
    imageColSize = (int*)malloc(sizeof(int)*m);
    for (int i = 0; i < m; i++){
        image[i] = (int*)malloc(sizeof(int)*n);
        imageColSize[i] = n;
    }
    va_list args;
    va_start(args, n);
    for(int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j){
            image[i][j] = va_arg(args, int);
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    printf("--------\n");
    va_end(args);
    
    int **output = NULL;
    int returnSize;
    int *returnColumnSizes = NULL;
    output = updateMatrix(image, imageSize, imageColSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }
    printf("========\n");

    for (int i = 0; i < m; i++){
        free(image[i]);
    }
    free(imageColSize);
    free(image);
}
int main(){
    two_dim_array_init(3, 3, 0,0,0, 0,1,0, 0,0,0);
    two_dim_array_init(3, 3, 0,0,0, 0,1,0, 1,1,1);
    two_dim_array_init(3, 3, 1,1,1, 1,0,1, 1,1,1);
    /*two_dim_array_init(10,10,1,1,0,0,1,0,0,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1);*/

}
