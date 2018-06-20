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
		bool hasCycle(ListNode *head) {
			ListNode* one = head;
			ListNode* two = head;

			while (two != NULL) {
				one = one->next;
				two = two->next;

				if (two == NULL) return false;
				two = two->next;

				if (one == two) return true;
			}
			return false;
		}
};
