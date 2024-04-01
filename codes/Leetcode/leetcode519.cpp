class Solution {
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        reset();
    }
    
    vector<int> flip() {
        int x = rand() % res;
        for (int i = 0; i < m; ++i) {
            int valid_place = n - records[i].size();
            if (x < valid_place) {
                auto iter = records[i].begin();
                for (int j = 0; j < n; ++j) {
                    if (iter != records[i].end() && j == *iter) {
                        iter++;
                    } else if (x-- == 0) {
                        records[i].insert(j);
                        res--;
                        return {i, j};
                    }
                }
            } else {
                x -= valid_place;
            }
        }
        return {0, 0};
    }
    
    void reset() {
        res = m * n;
        records.clear();
        records.resize(m);
    }
    int res;
    int m;
    int n;
    vector<set<int>> records;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
