int minnum(int a, int b) {
	return a > b ? b : a;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
	int dp[301][301] = { 0 };
	int max = 0;
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < *matrixColSize; j++) {
			if (matrix[i][j] == '1') {
				if (i == 0 || j == 0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = minnum(minnum(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]) + 1;
				}
				if (dp[i][j] > max) {
					max = dp[i][j];
				}
			}
		}
	}
	int area = max * max;
	return area;
}