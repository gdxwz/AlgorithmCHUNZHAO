//方法2：统计
int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int majorityElement(int* nums, int numsSize) {
	if (numsSize == 1) {
		return nums[0];
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	int cnt = 1;
	int ans;
	for (int i = 1; i < numsSize; i++) {
		if (nums[i - 1] == nums[i]) {
			cnt++;
			if (cnt > numsSize / 2) {
				ans = nums[i];
				break;
			}
		}
		else {
			cnt = 1;
		}
	}
	return ans;
}

//方法2：排序
int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int majorityElement(int* nums, int numsSize) {
	if (numsSize == 1) {
		return nums[0];
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	return nums[numsSize / 2];
}