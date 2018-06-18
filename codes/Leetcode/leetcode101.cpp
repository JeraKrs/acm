/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		bool symmetric(TreeNode* first, TreeNode* second) {
			if (first == NULL && second == NULL) return true;
			if (first == NULL || second == NULL) return false;
			if (first->val != second->val) return false;

			return symmetric(first->left, second->right) && symmetric(first->right, second->left);
		}

		bool isSymmetric(TreeNode* root) {
			return symmetric(root, root);
		}
};
