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
			ListNode tmp = ListNode(0);
			tmp.next = head;
			head = &tmp;

			ListNode* mov = head;
			while (mov->next != NULL) {
				bool dup = false;
				ListNode* first = mov->next;
				ListNode* last = first->next;
				while (last != NULL && first->val == last->val) {
					dup = true;
					last = last->next;
				}

				if (dup)
					mov->next = last;
				else
					mov = mov->next;
			}

			return head->next;
		}
};
