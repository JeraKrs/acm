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
		TreeNode* build(int& p, int start, int end, vector<int>& preorder, vector<int>& inorder) {
			if (start > end) return NULL;

			TreeNode* ret = new TreeNode(preorder[p++]);
			if (start == end) return ret;

			int t = start;
			while (t <= end && inorder[t] != preorder[p-1]) t++;

			ret->left = build(p, start, t-1, preorder, inorder);
			ret->right = build(p, t+1, end, preorder, inorder);
			return ret;
		}

		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			int p = 0;
			return build(p, 0, inorder.size()-1, preorder, inorder);
		}
};
