void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int i, j;
	int tmp;
	for (i = m, j = 0; (i < nums1Size) && (j < n); i++, j++)
	{
		nums1[i] = nums2[j];
	}
	for (i = 0; i < nums1Size; i++)
	{
		for (j = i + 1; j < nums1Size; j++)
		{
			if (nums1[i] > nums1[j]) {
				tmp = nums1[i];
				nums1[i] = nums1[j];
				nums1[j] = tmp;
			}
		}
	}
}