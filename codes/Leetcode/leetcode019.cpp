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
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode* ans = head;

			ListNode* move = head;
			while (n--) move = move->next;
			if (move == NULL) return ans->next;

			while (move->next != NULL) { head = head->next, move = move->next; }
			head->next = head->next->next;
			return ans;
		}
};
