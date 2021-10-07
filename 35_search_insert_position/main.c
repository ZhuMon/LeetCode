#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target){
    int b = 0, e = numsSize-1;
    int mid;
    while (b <= e){
        mid = b + (e-b)/2;
        if (nums[mid] == target){
            return mid;
        } else if (nums[mid] > target){
            e = mid - 1;
        } else {
            b = mid + 1;
        }

    }
    return (b == numsSize || nums[b] >= target) ? b : b+1;
}

bool check_ans(int *nums, int len, int target, int output){
    for (int i = 0; i < len; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    if (nums[output] == target){
        printf("PASS\n");
        return true;
    } else if (nums[output] > target && output-1 > -1 && nums[output-1] < target){
        printf("PASS\n");
        return true;
    } else if (nums[output] > target && output == 0){
        printf("PASS\n");
        return true;
    } else if (output == len && nums[output-1] < target){
        return true;
    } else {
        printf("FAIL, index: %d\n", output);
        return false;
    }

}

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

int main(){
    int *nums;
    int numsSize = 2;
    int target = 0;
    int index;

    nums = (int*)malloc(sizeof(int)*numsSize);    
    int_array_init(nums, numsSize, 1, 3);
    index = searchInsert(nums, numsSize, target);
    check_ans(nums, numsSize, target, index);

    numsSize = 1;
    target = 0;
    int_array_init(nums, numsSize, 1);
    index = searchInsert(nums, numsSize, target);
    check_ans(nums, numsSize, target, index);
    
    numsSize = 1;
    target = 1;
    int_array_init(nums, numsSize, 1);
    index = searchInsert(nums, numsSize, target);
    check_ans(nums, numsSize, target, index);

    numsSize = 4;
    target = 7;
    int_array_init(nums, numsSize, 1, 3, 5, 6);
    index = searchInsert(nums, numsSize, target);
    check_ans(nums, numsSize, target, index);
}
