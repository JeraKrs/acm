/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	public:
		ListNode* deleteDuplicates(ListNode* head) {
			ListNode* mov = head;
			if (mov == NULL) return head;

			while (mov != NULL) {
				while (mov->next != NULL && mov->next->val == mov->val) 
					mov->next = mov->next->next;
				mov = mov->next;
			}
			return head;
		}
};
