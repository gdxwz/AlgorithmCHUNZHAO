bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
	int left = 0, right = matrixSize;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (matrix[mid][0] == target) {
			return true;
		}
		if (matrix[mid][0] < target) {
			left = mid;
		}
		else {
			right = mid;
		}

	}
	for (int i = 0; i < *matrixColSize; i++) {
		if (matrix[left][i] == target) {
			return true;
		}
	}
	return false;
}