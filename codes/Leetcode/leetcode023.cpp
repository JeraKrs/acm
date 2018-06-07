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
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			ListNode head = ListNode(0);
			ListNode* ans = &head;
			ListNode* move = ans;

			priority_queue<pair<int, int>> que;
			for (int i = 0; i < lists.size(); i++) {
				if (lists[i] != NULL)
					que.push(make_pair(-lists[i]->val, i));
			}

			while (!que.empty()) {
				int t = que.top().second; que.pop();
				move->next = lists[t];
				lists[t] = lists[t]->next;
				if (lists[t] != NULL)
					que.push(make_pair(-lists[t]->val, t));
				move = move->next;
			}

			return ans->next;
		}
};
