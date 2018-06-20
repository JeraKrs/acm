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
		ListNode *detectCycle(ListNode *head) {

			set<ListNode*> gra;
			while (head != NULL) {
				if (gra.count(head)) return head;
				gra.insert(head);
				head = head->next;
			}
			return head;
		}
};
