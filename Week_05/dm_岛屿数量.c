void DFS(int i, int j, int m, int* n, char** grid) {
	if (i < 0 || j < 0 || i >= m || j >= *n || grid[i][j] == '0') {
		return;
	}
	grid[i][j] = '0';
	DFS(i - 1, j, m, n, grid);
	DFS(i, j - 1, m, n, grid);
	DFS(i + 1, j, m, n, grid);
	DFS(i, j + 1, m, n, grid);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
	int count = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			if (grid[i][j] == '1') {
				count++;
				DFS(i, j, gridSize, gridColSize, grid);
			}
		}
	}
	return count;
}