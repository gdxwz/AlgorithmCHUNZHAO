/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void inorder(struct TreeNode* root, int* ret, int* returnSize) {
	if (root == NULL) {
		return;
	}
	inorder(root->left, ret, returnSize);
	ret[(*returnSize)++] = root->val;
	inorder(root->right, ret, returnSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int* ret = (int*)malloc(sizeof(int) * 100);
	*returnSize = 0;
	inorder(root, ret, returnSize);
	return ret;
}