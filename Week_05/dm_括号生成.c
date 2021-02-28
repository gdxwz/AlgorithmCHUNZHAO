#define maxsize  14300
void generate(int left, int right, int n, char** ret, char* path, int index, int* returnSize) {
	if (left == n && right == n) {
		ret[*returnSize] = (char*)malloc(sizeof(char)*(2 * n + 1));
		strcpy(ret[(*returnSize)++], path);
	}
	if (left < n) {
		path[index] = '(';
		generate(left + 1, right, n, ret, path, index + 1, returnSize);
	}
	if (right < left) {
		path[index] = ')';
		generate(left, right + 1, n, ret, path, index + 1, returnSize);
	}
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize) {
	char** ret = (char**)malloc(sizeof(char*)*maxsize);
	char*  path = (char*)calloc((2 * n + 1), sizeof(char));
	*returnSize = 0;
	generate(0, 0, n, ret, path, 0, returnSize);
	return ret;
}