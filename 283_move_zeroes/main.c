#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include<stdbool.h>

void moveZeroes(int* nums, int numsSize){
    /*int f = 0, b = numsSize-1; // forward and back*/
    /*if (numsSize < 2)*/
        /*return;*/
     /*swap first zero and last non-zero*/
    /*int tmp;*/
    /*int swap_begin = -1;*/
    /*for (; f <= b;){*/
        
        /*if (nums[b] == 0) {*/
            /*b--;*/
        /*} else if (nums[f] == 0 || swap_begin != -1){*/
            /*tmp = nums[f];*/
            /*nums[f] = nums[b];*/
            /*nums[b] = tmp;*/
            /*if (swap_begin == -1){*/
                /*swap_begin = f;*/
            /*}*/
            /*f++;*/
            /*b--;*/
        /*} else {*/
            /*f++;*/
        /*}*/
        
    /*}*/
    /*printf("%d %d %d %d %d\n", nums[0], nums[1], nums[2], nums[3], nums[4]);*/
    // reverse part of nums without zero
    /*b++;*/
    /*for (int i = swap_begin; i < b; i++, b--){*/
        /*tmp = nums[i];*/
        /*nums[i] = nums[b];*/
        /*nums[b] = tmp;*/
    /*}*/
    if (numsSize < 2)
        return;
    int n, z; // non-zero, zero
    int tmp;
    for (n = 0, z = 1; z < numsSize; z++){
        if (nums[n] == 0 && nums[z] != 0){
            tmp = nums[z];
            nums[z] = nums[n];
            nums[n] = tmp;
            n++;
        } else if (nums[n] != 0) {
            n++;
        }

    }

}

bool checkAns(int *nums, int n){
    int nonzero=-1, zero=-1;
    for (int i = 0; i < n; i++){
        if (nums[i] != 0){
            nonzero = i;
        }
        if (zero == -1 && nums[i] == 0){
            zero = i;
        }
    }
    if (nonzero > zero){
        return false;
    }
    return true;
    
}

void int_array_init( const int ct, ...) {
    int *a;
    a = (int*)malloc(sizeof(int)*ct);    
    va_list args;
    va_start(args, ct);
    for(int i = 0; i < ct; ++i) {
        a[i] = va_arg(args, int);
    }
    va_end(args);
    int *b;
    b = (int*)malloc(sizeof(int)*ct);    
    memcpy(b, a, sizeof(int)*ct);
    moveZeroes(a, ct);
    if (!checkAns(a, ct)){
        for(int i = 0; i < ct; ++i) {
            printf("%d ", b[i]);
        }
        printf("\n");

        printf("FAIL: \n");
        for (int i = 0; i < ct; ++i){
            printf("%d ", a[i]);
        }
        printf("\n");
        printf("-------\n");
    }
}
int main(){
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    for (int m = 0; m < 2; m++)
                        int_array_init(5, i*1, j*2, k*3, l*4, m*5);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    for (int m = 0; m < 2; m++)
                        for (int n = 0; n < 2; n++)
                            int_array_init(6, i*1, j*2, k*3, l*4, m*5, n*6);
                    

}
