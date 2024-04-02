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
    void spiralMatrixRecursion(
        int row_start, int row_end, int col_start, int col_end,
        ListNode* head, std::vector<std::vector<int> >& ans) {
            if (head == NULL) return;

            for (int i = col_start; i <= col_end; ++i) {
                if (head == NULL) return;
                ans[row_start][i] = head->val;
                head = head->next;
            }

            for (int i = row_start + 1; i <= row_end; ++i) {
                if (head == NULL) return;
                ans[i][col_end] = head->val;
                head = head->next;
            }

            for (int i = col_end - 1; i >= col_start; --i) {
                if (head == NULL) return;
                ans[row_end][i] = head->val;
                head = head->next;
            }

            for (int i = row_end - 1; i > row_start; --i) {
                if (head == NULL) return;
                ans[i][col_start] = head->val;
                head = head->next;
            }
            spiralMatrixRecursion(
                row_start + 1, row_end - 1,
                col_start + 1, col_end - 1,
                head, ans);
         }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        std::vector<std::vector<int> > ans;
        ans.resize(m);
        for (int i = 0 ; i < m; ++i) ans[i].resize(n, -1);
        spiralMatrixRecursion(0, m-1, 0, n-1, head, ans);
        return ans;
    }
};
