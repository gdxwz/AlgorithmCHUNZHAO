int hammingWeight(uint32_t n) {
	int count = 0;
	int mask = 1;
	while (n != 0) {
		count++;
		n = n & (n - 1);
	}
	return count;
}