#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *e1, const void *e2)
{
    int i = *((int *) e1);
    int j = *((int *) e2);
    if (i > j)
        return 1;
    if (i < j)
        return -1;
    return 0;
}
int **threeSum(int *nums,
               int numsSize,
               int *returnSize,
               int **returnColumnSizes)
{
    if (numsSize < 3) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int max_size = 64;
    int **output = (int **) malloc(sizeof(int *) * max_size);
    *returnSize = 0;

    int twosum = -nums[0] - 1;
    int j, k;
    for (int i = 0; i < numsSize - 2; i++) {
        if (nums[i] == -twosum) {
            continue;
        }
        twosum = -nums[i];

        j = i + 1;
        k = numsSize - 1;

        while (j < k) {
            while (j != i + 1 && j < numsSize && nums[j] == nums[j - 1]) {
                j++;
            }
            while (k != numsSize - 1 && nums[k] == nums[k + 1]) {
                k--;
            }
            if (j >= k) {
                break;
            }
            if (nums[j] + nums[k] == twosum) {
                output[*returnSize] = (int *) malloc(sizeof(int) * 3);
                output[*returnSize][0] = nums[i];
                output[*returnSize][1] = nums[j];
                output[*returnSize][2] = nums[k];
                *returnSize += 1;
            }
            if (nums[j] + nums[k] > twosum) {
                k--;
            } else {
                j++;
            }
            if (*returnSize == max_size) {
                max_size += 1;
                output = (int **) realloc(output, sizeof(int *) * max_size);
            }
        }
    }

    returnColumnSizes[0] = (int *) malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        returnColumnSizes[0][i] = 3;
    }
    output = (int **) realloc(output, sizeof(int *) * (*returnSize));
    return output;
}

int main()
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    /*int nums[] = {0, 0, 0, 0};*/
    int **output;
    int returnSize;
    int *returnColumnSizes;

    output = threeSum(nums, sizeof(nums) / sizeof(int), &returnSize,
                      &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("%d %d %d\n", output[i][0], output[i][1], output[i][2]);
    }
}
