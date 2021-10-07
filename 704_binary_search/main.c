#include <stdio.h>

void printArr(int* nums, int numsSize){
    if (numsSize == 1){
        printf("%d\n", nums[0]);
        return;
    }
    for (int i = 0; i < numsSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int search(int* nums, int numsSize, int target){
    int middle = numsSize/2;
    printArr(nums, numsSize);
    if (numsSize < 2){
        if (nums[0] != target){
            printf("numsSize < 2\n");
            return -1;
        } else {
            return 0;
        }

    }
    
    
    if (nums[middle] == target){
        return middle;
    } else if (nums[middle] > target) {
        return search(nums, middle, target);
    } else {
        if (middle + 1 == numsSize){ // avoid bad access
            return -1;
        }
        int res = search(nums+middle+1, numsSize % 2 == 0 ? middle-1 : middle, target);
        return res == -1 ? res : res + middle + 1;
    }

}

void printRes(int *nums, int numsSize, int target){
    printArr(nums, numsSize);
    printf("target: %d\nindex: %d\n", target, search(nums, numsSize, target));

}

int main(){
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int numsSize = 6;
    /*int target = 2;*/

    /*printRes(nums, numsSize, target);*/
    int target = -2;
    /*printRes(nums, numsSize, target);*/
    target = 13;
    printRes(nums, numsSize, target);
}
