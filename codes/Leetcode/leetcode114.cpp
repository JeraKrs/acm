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
		TreeNode* dfs(TreeNode* root) {
			if (root == NULL) return root;

			TreeNode* left = dfs(root->left);
			TreeNode* right = dfs(root->right);
			TreeNode* mov = root;

			root->left = NULL;
			while (left != NULL) {
				mov = mov->right = left;
				left = left->right;
			}
			while (right != NULL) {
				mov = mov->right = right;
				right = right->right;
			}
			return root;
		}

		void flatten(TreeNode* root) {
			dfs(root);
		}
};
