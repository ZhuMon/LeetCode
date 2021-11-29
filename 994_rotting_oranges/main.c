#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>


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
// space = O(mn)
/*int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int row = gridSize, col = gridColSize[0];

    int **newgrid;
    newgrid = (int**)malloc(sizeof(int*)*row);
    for (int i = 0; i < row; i++){
        newgrid[i] = (int*)malloc(sizeof(int)*col);
        for (int j = 0; j < col; j++){
            newgrid[i][j] = grid[i][j];
        }
    }
    int times = 0;

    int four_dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int newi, newj;

    int **nowgrid, **anothergrid, **tmpgrid;
    nowgrid = grid;
    anothergrid = newgrid;

    int count0, count1 = -1;
    int last_count1 = count1;
    for (times = 0; times < row*col; times++){
        count1 = 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (nowgrid[i][j] == 2){
                    for (int d = 0; d < 4; d++){
                        newi = i+four_dir[d][0];
                        newj = j+four_dir[d][1];

                        if (newi >= 0 && newi < row && newj >= 0 && newj < col && nowgrid[newi][newj] == 1){
                            anothergrid[newi][newj] = 2;
                        }
                    }
                    anothergrid[i][j] = 2;
                } else if (nowgrid[i][j] == 1){
                    count1++;
                    count0 = 0;
                    for (int d = 0; d < 4; d++){
                        newi = i+four_dir[d][0];
                        newj = j+four_dir[d][1];

                        if (newi >= 0 && newi < row && newj >= 0 && newj < col && nowgrid[newi][newj] == 0){
                            count0++;
                        }
                    }
                    if (count0 == 4){
                        return -1;
                    }
                }
            }
        }
        printArr(anothergrid, row, col);
        if (count1 == 0){
            return times;
        }
        if (count1 == last_count1){
            return -1;
        }
        last_count1 = count1;
        tmpgrid = nowgrid;
        nowgrid = anothergrid;
        anothergrid = tmpgrid;
    }
    return -1;
}*/
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int row = gridSize, col = gridColSize[0];

    int fresh = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (grid[i][j] == 1){
                fresh++;
            }
        }
    }
    if (fresh == 0){
        return 0;
    }
    int times = 0;

    int four_dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int newi, newj;

    int rotten_val = 2, another_val = 3, tmp;

    int count0, count1 = -1;
    int last_count1 = count1;
    for (times = 0; times < row*col; times++){
        count1 = 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == rotten_val){
                    for (int d = 0; d < 4; d++){
                        newi = i+four_dir[d][0];
                        newj = j+four_dir[d][1];

                        if (newi >= 0 && newi < row && newj >= 0 && newj < col && grid[newi][newj] == 1){
                            grid[newi][newj] = another_val;
                        }
                    }
                    grid[i][j] = another_val;
                } else if (grid[i][j] == 1){
                    count0 = 0;
                    for (int d = 0; d < 4; d++){
                        newi = i+four_dir[d][0];
                        newj = j+four_dir[d][1];

                        if (newi >= 0 && newi < row && newj >= 0 && newj < col && grid[newi][newj] == 0){
                            count0++;
                        }
                    }
                    if (count0 == 4){
                        return -1;
                    }
                }
            }
        }
        printArr(grid, row, col);
        if (count1 == 0){
            return times+1;
        }
        if (count1 == last_count1){
            return -1;
        }
        last_count1 = count1;
        tmp = rotten_val;
        rotten_val = another_val;
        another_val = tmp;
    }
    return -1;
}
void two_dim_array_init(const int m, const int n, ...) {
    // array: mxn
    int **image;
    int row = m;
    int *cols;


    image = (int**)malloc(sizeof(int*)*m);
    cols = (int*)malloc(sizeof(int)*m);
    for (int i = 0; i < m; i++){
        image[i] = (int*)malloc(sizeof(int)*n);
        cols[i] = n;
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
    
    int output;
    output = orangesRotting(image, row, cols);

    printf("return: %d\n", output);
    printf("========\n");

    for (int i = 0; i < m; i++){
        free(image[i]);
    }
    free(cols);
    free(image);
}
int main(){
    two_dim_array_init(3,3,2,1,1, 1,1,0, 0,1,1);
    two_dim_array_init(3,3, 2,1,1, 0,1,1, 1,0,1);
    two_dim_array_init(1,2, 0,2);
    return 0;
}
