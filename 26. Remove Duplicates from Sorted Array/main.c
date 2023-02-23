#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <assert.h>


int removeDuplicates(int* nums, int numsSize) { //change the input array
	int wrt_ptr = 0;
	for (int i = 0; i < numsSize; i++) {
		if (i == numsSize - 1) { //if we reach the last items, write it.
			nums[wrt_ptr] = nums[i];
		}
		else if (nums[i] == nums[i + 1]) { //if the items already exists, pass to the next iteration.
			continue;
		}
		nums[wrt_ptr] = nums[i];
		wrt_ptr++;
	}
	return wrt_ptr;
}

int main()
{
	int nums[10] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 }; // Input array
	int expectedNums[5] = {0,1,2,3,4}; // The expected answer with correct length

	int k = removeDuplicates(nums,10); // Calls your implementation

	assert(k == sizeof(expectedNums) / sizeof(expectedNums[0]));
	for (int i = 0; i < k; i++) {
		assert(nums[i] == expectedNums[i]);
	}
	

	return 0;
}