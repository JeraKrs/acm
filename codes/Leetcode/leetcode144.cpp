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
		vector<int> preorderTraversal(TreeNode* root) {
			vector<int> ans;
			stack<TreeNode*> sta;

			while (root != NULL) {

				ans.push_back(root->val);
				sta.push(root);
				root = root->left;

				while (!sta.empty() && root == NULL) {
					root = sta.top()->right;
					sta.pop();
				}
			}

			return ans;
		}
};
