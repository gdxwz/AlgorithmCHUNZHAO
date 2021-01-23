void rotate(int* nums, int numsSize, int k) {
	int* newnum = (int*)malloc(sizeof(int) * numsSize);
	int i, j;
	for (j = 0, i = 0; i < numsSize; i++, j++)
	{
		newnum[(j + k) % numsSize] = nums[i];
	}
	memcpy(nums, newnum, sizeof(int) * numsSize);
	//  for(i=0;i<numsSize;i++)
	//  {
	//      nums[i]=newnum[i];
	//  }
}