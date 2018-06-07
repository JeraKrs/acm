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
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			ListNode tmp = ListNode(0);
			ListNode* ans = &tmp;
			ListNode* move = ans;

			while (l1 != NULL || l2 != NULL) {
				if (l1 == NULL || (l2 != NULL && l1->val >= l2->val)) {
					move->next = l2;
					l2 = l2->next;
				} else {
					move->next = l1;
					l1 = l1->next;
				}
				move = move->next;
			}
			return ans->next;
		}
};
