/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int i;
	int j = numsSize;
	int* a = (int*)malloc(sizeof(int) * 2);
	for (i = 0; i < numsSize; i++)
	{
		if (j != numsSize) {           //找到两数之后不再循环
			break;
		}
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target) {
				a[0] = i;
				a[1] = j;
				break;
			}
		}
	}
	*returnSize = 2;
	return a;
}