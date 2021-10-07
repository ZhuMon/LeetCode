#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<stdbool.h>
#include<stdarg.h>

void recur(int **image, bool **record, int m, int n, int i, int j, int origColor, int newColor){
    if (0 > i || i >= m || 0 > j || j >= n){
        return;
    }
    if (record[i][j]){
        return;
    }
    if (image[i][j] == origColor){
        image[i][j] = newColor;
        record[i][j] = true;
    } else {
        record[i][j] = true;
        return;
    }
    
    recur(image, record, m, n, i+1, j, origColor, newColor);
    recur(image, record, m, n, i-1, j, origColor, newColor);
    recur(image, record, m, n, i, j+1, origColor, newColor);
    recur(image, record, m, n, i, j-1, origColor, newColor);
    
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    bool **record = NULL; // record whether pass
    record = (bool**)malloc(sizeof(bool*)*imageSize);
    for (int i = 0; i < imageSize; i++){
        record[i] = (bool*)malloc(sizeof(bool)*imageColSize[0]);
        bzero(record[i],sizeof(bool)*imageColSize[0]);
    }
    recur(image, record, imageSize, imageColSize[0], sr, sc, image[sr][sc], newColor);
    return image;
}

void int_array_init(const int sr, const int sc, const int newColor, const int m, const int n, ...) {
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
    output = floodFill(image, imageSize, imageColSize, sr, sc, newColor, &returnSize, &returnColumnSizes);

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
    int_array_init(1, 1, 2, 3, 3, 1,1,1,1,1,0,1,0,1);
    int_array_init(0, 0, 2, 2, 3, 0,0,0,0,0,0);
    return 0;
}
