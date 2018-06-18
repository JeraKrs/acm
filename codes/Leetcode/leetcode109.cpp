/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
		TreeNode* buildTree(int start, int end, vector<int>& nums) {
			if (start > end) return NULL;
			int mid = (start + end) >> 1;
			TreeNode* ret = new TreeNode(nums[mid]);
			if (start == end) return ret;
			ret->left = buildTree(start, mid-1, nums);
			ret->right = buildTree(mid+1, end, nums);
			return ret;
		}

		TreeNode* sortedListToBST(ListNode* head) {
			vector<int> nums;
			while (head != NULL) {
				nums.push_back(head->val);
				head = head->next;
			}
			return buildTree(0, nums.size() - 1, nums);
		}
};
