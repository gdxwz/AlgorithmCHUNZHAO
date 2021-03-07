/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

void preordervisit(struct Node* root, int* ret, int* returnSize) {
	if (root == NULL) {
		return;
	}
	for (int i = 0; i < root->numChildren; i++) {
		ret[(*returnSize)++] = root->children[i]->val;
		preordervisit(root->children[i], ret, returnSize);
	}
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) {
	int* ret = (int*)malloc(sizeof(int) * 10240);
	*returnSize = 0;
	if (root == NULL) {
		return NULL;
	}
	ret[(*returnSize)++] = root->val;
	preordervisit(root, ret, returnSize);
	return ret;
}