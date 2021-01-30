int min(int a, int b) {
	return a > b ? b : a;
}

int nthUglyNumber(int n) {
	int* dp = (int*)malloc(sizeof(int)*n);
	int a = 0, b = 0, c = 0;
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = min(min(dp[a] * 2, dp[b] * 3), dp[c] * 5);
		if (dp[i] == dp[a] * 2) {
			a++;
		}
		if (dp[i] == dp[b] * 3) {
			b++;
		}
		if (dp[i] == dp[c] * 5) {
			c++;
		}
	}
	return dp[n - 1];
}