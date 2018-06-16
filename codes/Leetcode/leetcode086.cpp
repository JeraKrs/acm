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
		ListNode* partition(ListNode* head, int x) {
			ListNode tmp1 = ListNode(0);
			ListNode tmp2 = ListNode(0);
			ListNode* head1 = &tmp1;
			ListNode* head2 = &tmp2;

			ListNode* mov = head;
			ListNode* mov1 = head1;
			ListNode* mov2 = head2;
			while (mov != NULL) {
				if (mov->val < x) {
					mov1->next = mov;
					mov = mov->next;
					mov1 = mov1->next;
					mov1->next = NULL;
				} else {
					mov2->next = mov;
					mov = mov->next;
					mov2 = mov2->next;
					mov2->next = NULL;
				}
			}
			mov1->next = head2->next;

			return head1->next;
		}
};
