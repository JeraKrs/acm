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
		void dfs(TreeNode* root, int far, int& ans) {
			if (root == NULL)  return;

			far = far * 10 + root->val;
			if (root->left == NULL && root->right == NULL) {
				ans += far;
				return;
			}

			dfs(root->left, far, ans);
			dfs(root->right, far, ans);
		}

		int sumNumbers(TreeNode* root) {
			int ans = 0;
			dfs(root, 0, ans);
			return ans;
		}
};
