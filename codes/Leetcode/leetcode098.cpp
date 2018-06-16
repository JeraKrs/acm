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
		bool validBST(TreeNode* root, int& minVal, int& maxVal) {
			minVal = maxVal = root->val;

			int tmpMinVal, tmpMaxVal;
			if (root->left != NULL) {
				bool left =  validBST(root->left, tmpMinVal, tmpMaxVal);
				if (left == false || tmpMaxVal >= root->val)
					return false;
				minVal = min(minVal, tmpMinVal);
			}
			if (root->right != NULL) {
				bool right = validBST(root->right, tmpMinVal, tmpMaxVal);
				if (right == false || tmpMinVal <= root->val)
					return false;
				maxVal = max(maxVal, tmpMaxVal);
			}
			return true;
		}

		bool isValidBST(TreeNode* root) {
			if (root == NULL) return true;
			int minVal, maxVal;
			return validBST(root, minVal, maxVal);
		}
};
