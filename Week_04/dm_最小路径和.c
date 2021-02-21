int minnum(int a, int b) {
	return a > b ? b : a;
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
	int dp[200][200] = { 0 };
	dp[0][0] = grid[0][0];
	for (int i = 1; i < *gridColSize; i++) {
		dp[0][i] = dp[0][i - 1] + grid[0][i];
	}
	for (int i = 1; i < gridSize; i++) {
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	}
	for (int i = 1; i < gridSize; i++) {
		for (int j = 1; j < *gridColSize; j++) {
			dp[i][j] = minnum(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
		}
	}
	return dp[gridSize - 1][(*gridColSize) - 1];
}