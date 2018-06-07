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
		ListNode* reverseKGroup(ListNode* head, int k) {
			ListNode first = ListNode(0);
			ListNode* ans = &first;
			ListNode* move = ans;

			while (head != NULL) {
				int t = k;
				ListNode* count = head;
				while (t && count != NULL) {
					count = count->next;
					t--;
				}

				if (t) {
					move->next = head;
					break;
				}

				ListNode* last = NULL;
				for (int i = 0; i < k && head != NULL; i++) {
					ListNode* tmp = head->next;
					head->next = last;
					last = head;
					head = tmp;
				}
				move->next = last;
				while (move->next != NULL) move = move->next;
			}
			return ans->next;
		}
};
