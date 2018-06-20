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
		int dfs(TreeNode* root, int& ans) {
			if (root == NULL) return 0;

			ans = max(ans, root->val);

			int left = dfs(root->left, ans);
			ans = max(ans, root->val + left);

			int right = dfs(root->right, ans);
			ans = max(ans, root->val + right);

			ans = max(ans, left + right + root->val);
			return max(0, max(left, right)) + root->val;
		}

		int maxPathSum(TreeNode* root) {
			int ans = 0;
			if (root == NULL) return ans;

			ans = root->val;
			dfs(root, ans);
			return ans;
		}
};
