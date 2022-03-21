/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = NULL;
        ListNode* mov = NULL;
        while (head) {
            if (head->val != val) {
                if (ans) {
                    mov->next = head;
                    mov = mov->next;
                } else {
                    ans = head;
                    mov = ans;
                }
            }
            head = head->next;
            if (mov) {
                mov->next = NULL;
            }
        }
        return ans;
    }
};
