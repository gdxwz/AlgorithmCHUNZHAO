/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preorder(struct TreeNode* root, int* ret, int* returnSize) {
	if (root == NULL) {
		return;
	}
	ret[(*returnSize)++] = root->val;
	preorder(root->left, ret, returnSize);
	preorder(root->right, ret, returnSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int* ret = (int*)malloc(sizeof(int) * 100);
	*returnSize = 0;
	preorder(root, ret, returnSize);
	return ret;
}