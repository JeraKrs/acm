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
		ListNode* swapPairs(ListNode* head) {
			if (head == NULL) return NULL;

			ListNode tmp = ListNode(0);
			ListNode* ans = &tmp;
			ListNode* move = ans;

			ListNode* one = head;
			ListNode* two = head->next;
			while (one != NULL || two != NULL) {
				if (two != NULL) {
					ListNode* t = two->next;

					move->next = two;
					move = move->next;
					move->next = one;
					move = move->next;

					one = t;
					if (t != NULL) two = t->next;
					else two = NULL;
				} else {
					move->next = one;
					move = move->next;
					break;
				}
			}
			move->next = NULL;
			return ans->next;
		}
};
