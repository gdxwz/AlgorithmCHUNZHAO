int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
	qsort(g, gSize, sizeof(int), compare);
	qsort(s, sSize, sizeof(int), compare);
	int i, j, count = 0;
	for (i = 0, j = 0; i < gSize&&j < sSize; i++, j++)
	{
		while (j<sSize&&g[i]>s[j]) {
			j++;
		}
		if (j < sSize)
			count++;
	}
	return count;
}