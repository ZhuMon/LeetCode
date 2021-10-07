#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
void rotate(int* nums, int numsSize, int k){
    int *output;
    /*output = (int*)malloc(sizeof(int)*k);*/

    /*memcpy(output, nums+(numsSize-k), k*sizeof(int));*/
    /*memcpy(nums+(numsSize-k), nums, (numsSize-k)*sizeof(int));*/
    /*memcpy(nums, output, k*sizeof(int));*/
    /*free(output);*/

    output = (int*)malloc(sizeof(int)*numsSize);

    memcpy(output, nums+(numsSize-k), k*sizeof(int));
    memcpy(output+k, nums, (numsSize-k)*sizeof(int));
    memcpy(nums, output, numsSize*sizeof(int));
}


void int_array_init(const int k, const int ct, ...) {
    int *a;
    a = (int*)malloc(sizeof(int)*ct);    
    va_list args;
    va_start(args, ct);
    for(int i = 0; i < ct; ++i) {
        a[i] = va_arg(args, int);
    }
    va_end(args);

    printf("origin: ");
    for(int i = 0; i < ct; ++i){
        printf("%d ", a[i]);
    }
    printf("\nrotate: ");
    rotate(a, ct, k);
    for(int i = 0; i < ct; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int_array_init(3, 7, 1, 2, 3, 4, 5, 6, 7);
    int_array_init(2, 4, -1, 100, 3, 99);
}
