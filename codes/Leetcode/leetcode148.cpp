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
		ListNode* merge_sort(ListNode* head, int n) {
			if (n <= 1) return head;

			int k = n >> 1;
			ListNode* move = head;
			for (int i = 1; i < k; i++) move = move->next;

			ListNode* first = head;
			ListNode* second = move->next;
			move->next = NULL;

			first = merge_sort(first, k);
			second = merge_sort(second, n-k);

			ListNode* ret = NULL;
			while (first != NULL || second != NULL) {
				if (first == NULL || (second != NULL && first->val > second->val)) {
					move = second;
					second = second->next;
				} else {
					move = first;
					first = first->next;
				}

				if (ret == NULL) head = ret = move;
				else {
					ret->next = move;
					ret = ret->next;
				}
			}
			return head;
		}

		ListNode* sortList(ListNode* head) {
			int n = 0;
			ListNode* move = head;
			while (move != NULL) n++, move = move->next;
			return merge_sort(head, n);
		}
};
