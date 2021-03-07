void DFS(int i, int j, int n, int m, char** grid)
{
	if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0') {
		return;
	}
	grid[i][j] = '0';
	DFS(i + 1, j, n, m, grid);
	DFS(i - 1, j, n, m, grid);
	DFS(i, j + 1, n, m, grid);
	DFS(i, j - 1, n, m, grid);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
	int count = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			if (grid[i][j] == '1') {
				count++;
				DFS(i, j, gridSize, *gridColSize, grid);
			}
		}
	}
	return count;
}