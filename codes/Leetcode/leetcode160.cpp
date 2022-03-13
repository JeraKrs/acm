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
    int getListNode(ListNode* list) {
        int len = 0;
        while (list) {
            ++len;
            list = list->next;
        }
        return len;
    }
    ListNode *skipListNode(ListNode* list, int n) {
        while (n--) {
            list = list->next;
        }
        return list;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getListNode(headA);
        int lenB = getListNode(headB);

        if (lenA > lenB) {
            headA = skipListNode(headA, lenA - lenB);
        } else if (lenA < lenB) {
            headB = skipListNode(headB, lenB - lenA);
        }
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
