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
		int depTree(TreeNode* root) {
			if (root == NULL) return 0;
			return max(depTree(root->left), depTree(root->right)) + 1;
		}

		bool isBalanced(TreeNode* root) {
			if (root == NULL) return true;

			int margin = depTree(root->left) - depTree(root->right);
			if (margin >= 2 || margin <= -2) return false;

			return isBalanced(root->left) && isBalanced(root->right);
		}
};
