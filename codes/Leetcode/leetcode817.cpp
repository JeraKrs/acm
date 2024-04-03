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
    int numComponents(ListNode* head, vector<int>& nums) {
        int n = nums.size();
        int flags[10000];
        memset(flags, 0, sizeof(flags));
        for (int i = 0; i < n; ++i) flags[nums[i]] = 1;

        int ans = 0;
        int pre = 0;
        while (head) {
            if (pre == 0 && flags[head->val]) ++ans;
            pre = flags[head->val];
            head = head->next;
        }
        return ans;
    }
};
