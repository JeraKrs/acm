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
		vector<vector<int>> levelOrder(TreeNode* root) {
			vector<vector<int>> ans;
			if (root == NULL) return ans;

			queue<TreeNode*> que;
			que.push(root);

			while (!que.empty()) {
				vector<int> cur;
				int n = que.size();

				while (n--) {
					TreeNode* t = que.front();
					que.pop();
					cur.push_back(t->val);
					if (t->left != NULL) que.push(t->left);
					if (t->right != NULL) que.push(t->right);
				}
				ans.push_back(cur);
			}
			return ans;
		}
};
