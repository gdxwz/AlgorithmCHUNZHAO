double DFS(double x, int n) {
	if (n == 0) {
		return 1.0;
	}
	double y = DFS(x, n / 2);
	return (n % 2) ? y * y*x : y * y;
}

double myPow(double x, int n) {
	long long N = n;
	double result;
	int flag = 0;
	if (N < 0) {
		N = -N;
		flag = 1;
	}
	result = DFS(x, N);
	return flag ? 1 / result : result;

}