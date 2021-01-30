typedef struct arr {
	int num;
	int cnt;
}arr;

int cmp(void* a, void* b) {
	return *(int*)a - *(int*)b;
}

int cmps(const void* a, const  void* b) {
	return (*(arr *)b).cnt - (*(arr *)a).cnt;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
	int* ret = (int*)malloc(sizeof(int)*k);
	int index = 0;
	arr arr1[numsSize];
	*returnSize = k;
	qsort(nums, numsSize, sizeof(int), cmp);
	arr1[index].num = nums[0];
	arr1[index].cnt = 1;
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] == nums[i - 1]) {
			arr1[index].cnt++;
		}
		else {
			arr1[++index].num = nums[i];
			arr1[index].cnt = 1;
		}
	}
	qsort(arr1, index + 1, sizeof(arr), cmps);
	for (int i = 0; i < k; i++) {
		ret[i] = arr1[i].num;
	}
	return ret;
}