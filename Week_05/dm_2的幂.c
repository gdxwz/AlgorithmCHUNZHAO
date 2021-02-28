bool isPowerOfTwo(int n) {
	int count = 0;
	while (n) {
		count += n % 2;
		n /= 2;
	}
	return count == 1 ? true : false;
}