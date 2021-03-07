int minDistance(char * word1, char * word2) {
	int dp[501][501];
	int len1 = strlen(word1);
	int len2 = strlen(word2);
	for (int i = 0; i < len1 + 1; i++) {
		dp[i][0] = i;
	}
	for (int j = 0; j < len2 + 1; j++) {
		dp[0][j] = j;
	}
	for (int i = 1; i < len1 + 1; i++) {
		for (int j = 1; j < len2 + 1; j++) {
			dp[i][j] = fmin(dp[i - 1][j - 1], fmin(dp[i - 1][j], dp[i][j - 1])) + 1;
			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = fmin(dp[i][j], dp[i - 1][j - 1]);
			}
		}
	}
	return dp[len1][len2];
}