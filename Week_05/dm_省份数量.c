int fa[1000];
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
int findCircleNum(int** M, int MSize, int* MColSize) {
	for (int i = 0; i < MSize; i++)   fa[i] = i;
	int ans = MSize;
	for (int i = 0; i < MSize; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (M[i][j] == 0) continue;
			if (find(fa[i]) != find(fa[j]))
			{
				fa[find(i)] = fa[find(j)];
				ans--;
			}
		}
	}
	return ans;
}
