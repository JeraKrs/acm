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
		vector<int> postorderTraversal(TreeNode* root) {
			vector<int> ans;
			stack<TreeNode*> sta;

			while (root != NULL) {
				sta.push(root);
				root = root->left;

				while (!sta.empty() && root == NULL) {
					if (sta.top() == NULL) {
						sta.pop();
						ans.push_back(sta.top()->val);
						sta.pop();
					} else {
						root = sta.top()->right;
						sta.push(NULL);
					}
				}
			}
			return ans;
		}
};
