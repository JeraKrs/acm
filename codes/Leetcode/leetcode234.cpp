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
    int getLength(ListNode* head) {
        int c = 0;
        while (head) {
            ++c;
            head = head->next;
        }
        return c;
    }

    ListNode* revertList(ListNode* head) {
        ListNode* move = NULL;
        while (head) {
            ListNode* tmp = head->next;
            head->next = move;
            move = head;
            head = tmp;
        }
        return move;
    }
    bool isPalindrome(ListNode* head) {
        int m = getLength(head) / 2;
        ListNode* move = head;
        int d = m;
        while (d--) {
            move = move->next;
        }
        move = revertList(move);

        while (m--) {
            if (head->val != move->val) {
                return false;
            }
            head = head->next;
            move = move->next;
        }
        return true;
    }
};
