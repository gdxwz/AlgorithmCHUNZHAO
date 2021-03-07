/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int** ret = (int**)malloc(sizeof(int*)*(1 << numsSize));
	*returnColumnSizes = (int*)malloc(sizeof(int)*(1 << numsSize));
	*returnSize = (1 << numsSize);
	int tsize = 0;
	int t[numsSize];
	for (int mask = 0; mask < (1 << numsSize); mask++) {
		tsize = 0;
		for (int i = 0; i < numsSize; i++) {
			if (mask&(1 << i)) {
				t[tsize++] = nums[i];
			}
		}
		int* tmp = (int*)malloc(sizeof(int)*tsize);
		memcpy(tmp, t, sizeof(int)*tsize);
		(*returnColumnSizes)[mask] = tsize;
		ret[mask] = tmp;
	}
	return ret;
}