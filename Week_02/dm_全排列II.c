/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void Dfs(int* nums, int numsSize, int Depth, int* path, bool* used, int** res, int* returnSize) {
	if (Depth == numsSize) {
		res[*returnSize] = (int*)malloc(sizeof(int)*numsSize);
		memcpy(res[(*returnSize)++], path, sizeof(int)*numsSize);
		return;
	}
	for (int i = 0; i < numsSize; i++) {
		if (used[i] == true || (i > 0 && (nums[i] == nums[i - 1]) && (used[i - 1] == false))) {
			continue;
		}
		path[Depth] = nums[i];
		used[i] = true;
		Dfs(nums, numsSize, Depth + 1, path, used, res, returnSize);
		used[i] = false;
	}
}

int cmp(void* a, void* b) {
	return *(int*)a - *(int*)b;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int** res = (int**)malloc(sizeof(int*) * 2001);
	int*  path = (int*)malloc(sizeof(int)*numsSize);
	bool* used = (bool*)calloc(numsSize, sizeof(bool));
	qsort(nums, numsSize, sizeof(int), cmp);
	*returnSize = 0;
	Dfs(nums, numsSize, 0, path, used, res, returnSize);
	*returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
	for (int i = 0; i < *returnSize; i++) {
		(*returnColumnSizes)[i] = numsSize;
	}
	return res;
}