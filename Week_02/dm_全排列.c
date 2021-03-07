/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int count;

void Dfs(int* nums, int numsSize, int Depth, int* path, bool* used, int** res) {
	if (Depth == numsSize) {
		res[count] = (int*)malloc(sizeof(int)*numsSize);
		memcpy(res[count++], path, sizeof(int)*numsSize);
		return;
	}
	for (int i = 0; i < numsSize; i++) {
		if (used[i] == true) {
			continue;
		}
		path[Depth] = nums[i];
		used[i] = true;
		Dfs(nums, numsSize, Depth + 1, path, used, res);
		used[i] = false;
	}
}


int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = 1;
	for (int i = 2; i <= numsSize; i++) {
		*returnSize *= i;
	}
	*returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
	for (int i = 0; i < (*returnSize); i++) {
		(*returnColumnSizes)[i] = numsSize;
	}
	int** res = (int**)malloc(sizeof(int*)*(*returnSize));
	int*  path = (int*)malloc(sizeof(int)*numsSize);
	bool* used = (bool*)calloc(numsSize, sizeof(bool));

	count = 0;
	Dfs(nums, numsSize, 0, path, used, res);
	return res;
}