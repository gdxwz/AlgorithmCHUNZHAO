/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
const int dir_x[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
const int dir_y[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n, m;

void dfs(char** board, int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; ++i) {
		int tx = x + dir_x[i];
		int ty = y + dir_y[i];
		if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
			continue;
		}
		// 不用判断 M，因为如果有 M 的话游戏已经结束了
		cnt += board[tx][ty] == 'M';
	}
	if (cnt > 0) {
		// 规则 3
		board[x][y] = cnt + '0';
	}
	else {
		// 规则 2
		board[x][y] = 'B';
		for (int i = 0; i < 8; ++i) {
			int tx = x + dir_x[i];
			int ty = y + dir_y[i];
			// 这里不需要在存在 B 的时候继续扩展，因为 B 之前被点击的时候已经被扩展过了
			if (tx < 0 || tx >= n || ty < 0 || ty >= m || board[tx][ty] != 'E') {
				continue;
			}
			dfs(board, tx, ty);
		}
	}
}

char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes) {
	*returnColumnSizes = (int*)malloc(sizeof(int)*boardSize);
	for (int i = 0; i < boardSize; i++) {
		(*returnColumnSizes)[i] = *boardColSize;
	}
	n = boardSize;
	m = *boardColSize;
	*returnSize = boardSize;
	if (board[click[0]][click[1]] == 'M') {
		board[click[0]][click[1]] = 'X';
	}
	else {
		dfs(board, click[0], click[1]);
	}
	return board;
}