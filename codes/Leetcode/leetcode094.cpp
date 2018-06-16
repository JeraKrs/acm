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
		vector<int> inorderTraversal(TreeNode* root) {
			vector<int> ans, tmp;
			if (root == NULL) return ans;

			tmp = inorderTraversal(root->left);
			for (int i = 0; i < tmp.size(); i++) ans.push_back(tmp[i]);
			ans.push_back(root->val);
			tmp = inorderTraversal(root->right);
			for (int i = 0; i < tmp.size(); i++) ans.push_back(tmp[i]);
			return ans;
		}
};
