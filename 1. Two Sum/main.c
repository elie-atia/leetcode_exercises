/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *result = malloc( (*returnSize) * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;

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
