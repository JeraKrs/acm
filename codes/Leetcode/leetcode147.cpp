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
		ListNode* insertionSortList(ListNode* head) {
			ListNode* first = new ListNode(0);
			first->next = head;
			head = first;

			while (first->next != NULL) {
				ListNode* mini = first;
				ListNode* move = first->next;
				int ans = move->val;

				while (move->next != NULL) {
					if (move->next->val < ans) {
						ans = move->next->val;
						mini = move;
					}
					move = move->next;
				}

				move = mini->next;
				mini->next = move->next;
				move->next = first->next;
				first->next = move;
				first = first->next;
			}

			first = head->next;
			delete head;
			return first;
		}
};
