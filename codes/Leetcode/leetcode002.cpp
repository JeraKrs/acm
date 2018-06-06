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
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			int tmp = 0;
			ListNode* first = new ListNode(0);
			ListNode* move = first;

			while (true) {
				if (l1 != NULL) {
					tmp += l1->val;
					l1 = l1->next;
				}

				if (l2 != NULL) {
					tmp += l2->val;
					l2 = l2->next;
				}

				move->val = tmp % 10;
				tmp /= 10;

				if (l1 == NULL && l2 == NULL && tmp == 0) break;

				move->next = new ListNode(0);
				move = move->next;
			}

			return first;
		}
};
