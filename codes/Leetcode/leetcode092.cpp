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
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			ListNode* first = new ListNode(0);
			first->next = head;
			head = first;

			for (int i = 1; i < m; i++) first = first->next;
			ListNode* last = head;
			for (int i = 0; i <= n; i++) last = last->next;

			ListNode* mov = first->next;
			for (int i = m; i <= n; i++) {
				first->next = mov->next;
				mov->next = last;
				last = mov;
				mov = first->next;
			}
			first->next = last;
			first = head->next;
			delete head;
			return first;
		}
};
