int maxnum(int a, int b) {
	return a > b ? a : b;
}

int jump(int* nums, int numsSize) {
	int step = 0;
	int end = 0;
	int maxPosition = 0;
	for (int i = 0; i < numsSize - 1; i++) {
		maxPosition = maxnum(maxPosition, i + nums[i]);
		if (i == end) {
			end = maxPosition;
			step++;
		}
	}
	return step;
}

