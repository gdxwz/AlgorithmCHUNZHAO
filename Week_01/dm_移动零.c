void moveZeroes(int* nums, int numsSize) {
	int i, j;
	for (i = 0, j = 0; j < numsSize; j++)
	{
		if (nums[j] != 0) {
			nums[i] = nums[j];
			if (i != j) {
				nums[j] = 0;
			}
			i++;
		}
	}
	// for(j=i;j<numsSize;j++)
	// {
	//     nums[j]=0;
	// }
}