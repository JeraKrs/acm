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
		void visitTree(TreeNode* root, vector<int>& nums) {
			if (root == NULL) return;
			visitTree(root->left, nums);
			nums.push_back(root->val);
			visitTree(root->right, nums);
		}

		int countTree(TreeNode* root) {
			if (root == NULL) return 0;
			return countTree(root->left) + 1 + countTree(root->right);
		}

		void coverTree(TreeNode* root, int start, int end, vector<int>& nums) {
			if (root == NULL) return;

			int n = countTree(root->left);
			coverTree(root->left, start, start + n - 1, nums);
			root->val = nums[start + n];
			coverTree(root->right, start + n + 1, end ,nums);
		}

		void recoverTree(TreeNode* root) {
			vector<int> nums;
			visitTree(root, nums);

			int n = nums.size();
			sort(nums.begin(), nums.end());
			coverTree(root, 0, n-1, nums);
		}
};
