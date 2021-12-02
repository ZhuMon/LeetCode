#include<stdio.h>
#include<stdlib.h>

#include<stdarg.h>
void int_array_init(int *a, const int ct, ...) {
    free(a);
    a = (int*)malloc(sizeof(int)*ct);    
    va_list args;
    va_start(args, ct);
    for(int i = 0; i < ct; ++i) {
        a[i] = va_arg(args, int);
    }
    va_end(args);
}

void two_dim_array_init(const int sr, const int sc, const int newColor, const int m, const int n, ...) {
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
    //output = floodFill(image, imageSize, imageColSize, sr, sc, newColor, &returnSize, &returnColumnSizes);

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
