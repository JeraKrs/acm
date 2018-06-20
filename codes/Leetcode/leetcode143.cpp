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
		ListNode* reverse(ListNode* head) {
			ListNode* move = NULL;
			while (head != NULL) {
				ListNode* temp = head->next;
				head->next = move;
				move = head;
				head = temp;
			}
			return move;
		}

		void reorderList(ListNode* head) {
			if (head == NULL) return;

			int n = 0;
			ListNode* move = head;
			while (move != NULL) { n++, move = move->next; }

			int k = (n+1) >> 1;
			ListNode* first = head;
			ListNode* second = head;
			while (k--) second = second->next;

			second = reverse(second);

			int t = n >> 1; 
			move = NULL;
			while (t--) {
				if (move == NULL) move = first;
				else {
					move->next = first;
					move = move->next;
				}
				first = first->next;

				move->next = second;
				second = second->next;
				move = move->next;
			}

			if (n&1) {
				if (move == NULL) move = first;
				else {
					move->next = first;
					move = move->next;
				}
			}
			move->next = NULL;
		}
};
