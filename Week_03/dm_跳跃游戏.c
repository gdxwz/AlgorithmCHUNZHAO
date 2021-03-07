bool canJump(int* nums, int numsSize) {
	if (numsSize == 0) {
		return true;
	}
	int endcanreach = numsSize - 1;
	for (int i = numsSize - 1; i >= 0; i--) {
		if (nums[i] + i >= endcanreach) {
			endcanreach = i;
		}
	}
	return endcanreach == 0;
}