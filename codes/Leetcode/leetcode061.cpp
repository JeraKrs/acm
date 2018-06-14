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
		ListNode* rotateRight(ListNode* head, int k) {
			ListNode* ans = new ListNode(0);
			ans->next = head; head = ans;

			int n = 0;
			ListNode* count = ans->next;
			while (count != NULL) { count = count->next; n++; }
			if (n == 0) return ans->next;
			else k %= n;

			ListNode* move = ans;
			while (k--) move = move->next;
			while (move->next != NULL) {
				head = head->next;
				move = move->next;
			}

			move->next = ans->next;
			ans->next = head->next;
			head->next = NULL;
			return ans->next;
		}
};
