/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countbit(int num) {
	int count = 0;
	while (num != 0) {
		count++;
		num = num & (num - 1);
	}
	return count;
}

int* countBits(int num, int* returnSize) {
	int * ret = (int*)malloc(sizeof(int)* (num + 1));
	for (int i = 0; i < num + 1; i++) {
		ret[i] = countbit(i);
	}
	*returnSize = num + 1;
	return ret;
}