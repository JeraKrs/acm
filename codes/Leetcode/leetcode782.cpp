class Solution {
public:
    void swap_row(int a, int b, std::vector<std::vector<int>>& board) {
        std::vector<int> tmp = board[a];
        board[a] = board[b];
        board[b] = tmp;
    }

    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        
        // process row
        int odd = 0, even = 0, flags = 0;
        for (int i = 0; i < n; ++i) {
            if ((i&1) == 0) {
                if (board[i][0]&1) ++odd;
                else ++even;
            }
            if (board[i][0]) ++flags;
            else --flags;
        }

        if (flags < -1 || flags > 1) return -1;
        // 选定（0，0）的值
        if (flags) flags = flags > 0 ? 1 : 0;
        else flags = odd > even ? 1 : 0; 

        std::vector<int> odd_errs, even_errs;
        for (int i = 0; i < n; ++i) {
            if ((i&1) == 0 && board[i][0] != flags) {
                odd_errs.emplace_back(i);
            } else if ((i&1) && board[i][0] == flags) {
                even_errs.emplace_back(i);
            }
        }
        if (odd_errs.size() != even_errs.size()) return -1;
        int ans = odd_errs.size();

        for (int i = 0; i < odd_errs.size(); ++i) {
            swap_row(odd_errs[i], even_errs[i], board);
        }

        // check row
        for (int col = 1; col < n; ++col) {
            for (int row = 1; row < n; ++row) {
                if (board[row][col] == board[row-1][col]) {
                    return -1;
                }
            } 
        }

        // process col
        odd = 0, even = 0, flags = 0;
        for (int i = 0; i < n; ++i) {
            if ((i&1) == 0) {
                if (board[0][i]&1) ++odd;
                else ++even;
            }
            if (board[0][i]) ++flags;
            else --flags;
        }
        if (flags < -1 || flags > 1) return -1;
        
        if (flags) flags = flags > 0 ? 1 : 0;
        else flags = odd > even ? 1 : 0; 

        odd_errs.clear();
        even_errs.clear();
        for (int i = 0; i < n; ++i) {
            if ((i&1) == 0 && board[0][i] != flags) {
                odd_errs.emplace_back(i);
            } else if ((i&1) && board[0][i] == flags) {
                even_errs.emplace_back(i);
            }
        }
        if (odd_errs.size() != even_errs.size()) return -1;
        return ans + odd_errs.size();
    }
};
