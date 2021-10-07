#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *output = (int *) malloc(sizeof(int) * numsSize);
    int neg_arr[numsSize];
    int neg_index = 0;
    int i;
    for (i = 0; i < numsSize; i++){
        if (nums[i] < 0){
            neg_arr[neg_index++] = pow(nums[i],2);
        } else {
            break;
        }
    }
    neg_index--;
    int tmp_sqr = i+1 <= numsSize ? pow(nums[i],2) : 100000001;
    for (int j = 0; j < numsSize; j++){
        if (neg_index >= 0 && tmp_sqr <= neg_arr[neg_index]){
            output[j] = tmp_sqr;
            tmp_sqr = i+1 < numsSize ? pow(nums[++i],2) : 100000001;
        } else if (neg_index >= 0) {
            output[j] = neg_arr[neg_index--];
        } else if (i < numsSize){
            output[j] = tmp_sqr;
            tmp_sqr = i+1 < numsSize ? pow(nums[++i],2) : 100000001;
        }
        /*if (i >= numsSize || neg_index < 0){*/
            /*printf("%d. i: %d neg_index: %d\n", j, i, neg_index);*/
            /*printf("tmp_sqr: %d\n", tmp_sqr);*/
        /*}*/
    }
    return output;
}

void checkAns(const int ct, ...) {
    int *a;
    a = (int*)malloc(sizeof(int)*ct);    
    va_list args;
    va_start(args, ct);
    for(int i = 0; i < ct; ++i) {
        a[i] = va_arg(args, int);
    }
    va_end(args);

    int *output, outputSize;
    output = sortedSquares(a, ct, &outputSize);

    printf("origin: ");
    for (int i = 0; i < ct; i++){
        printf("%d ", a[i]);
    }
    printf("\nsorted: ");
    for (int i = 0; i < outputSize; i++){
        printf("%d ", output[i]);
    }
    printf("\n\n");
    
}

int main(){
    checkAns(5, -7, -3, 2, 3, 11);
    checkAns(5, -4, -1, 0, 3, 10);
    checkAns(1, -1);
    checkAns(1, 1);
    checkAns(1, 0);
}
