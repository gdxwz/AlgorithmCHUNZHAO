/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int i;
	for (i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i] == 9) {
			digits[i] = 0;
		}
		else {
			digits[i]++;
			*returnSize = digitsSize;
			return digits;
		}
	}
	int* newdigits = (int*)malloc(sizeof(int) * (digitsSize + 1));
	memset(newdigits, 0, sizeof(int) * (digitsSize + 1));
	newdigits[0] = 1;
	*returnSize = digitsSize + 1;
	return newdigits;
}