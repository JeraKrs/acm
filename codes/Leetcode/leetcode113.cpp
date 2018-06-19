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
		void dfs(TreeNode* root, int sum, vector<int> cur, vector<vector<int>>& ans) {
			sum -= root->val;
			cur.push_back(root->val);

			if (root->left == NULL && root->right == NULL) {
				if (sum == 0) ans.push_back(cur);
				return;
			}

			if (root->left != NULL) dfs(root->left, sum, cur, ans);
			if (root->right != NULL) dfs(root->right, sum, cur, ans);
		}

		vector<vector<int>> pathSum(TreeNode* root, int sum) {
			vector<vector<int>> ans;
			if (root == NULL) return ans;

			vector<int> cur;
			dfs(root, sum, cur, ans);
			return ans;
		}
};
