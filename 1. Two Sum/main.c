/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    bool found = false;
    int* result = malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        if (found) {
            break;
        }
        for (int j = 0; j < numsSize; j++) {
            if (i == j) {
                continue;
            }
            if (nums[i] + nums[j] == target) {
                //printf("i,j= %d, %d", i, j);
                result[0] = i;
                result[1] = j;
                found = true;
                break;

            }
        }
    }

    return result;


}

int main()  
{
    int *result, nums[8] = {1,1,1,1,1,1,1,2}, target = 2, numsSize = 8, * returnSize = NULL;
    result = twoSum(nums, numsSize, target, returnSize);

    printf("%d,%d", result[0], result[1]);

    return 0;
}
