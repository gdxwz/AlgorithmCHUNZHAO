int findMin(int* nums, int numsSize) {
	int left = 0, right = numsSize - 1, mid;
	if (numsSize == 1) {
		return nums[0];
	}
	if (nums[0] < nums[right]) {
		return nums[0];
	}
	while (left <= right) {
		mid = (left + right) / 2;
		if (nums[mid] > nums[mid + 1]) {
			return nums[mid + 1];
		}
		if (nums[mid] < nums[mid - 1]) {
			return nums[mid];
		}
		if (nums[0] < nums[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}