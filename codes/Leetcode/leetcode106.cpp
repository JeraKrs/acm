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
		TreeNode* build(int& p, int start, int end, vector<int>& inorder, vector<int>& postorder) {
			if (start > end) return NULL;
			TreeNode* ret = new TreeNode(postorder[p--]);
			if (start == end) return ret;

			int t = start;
			while (t <= end && inorder[t] != postorder[p+1]) t++;

			ret->right = build(p, t+1, end, inorder, postorder);
			ret->left = build(p, start, t-1, inorder, postorder);
			return ret;
		}

		TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
			int p = postorder.size() - 1;
			return build(p, 0, inorder.size()-1, inorder, postorder);
		}
};
