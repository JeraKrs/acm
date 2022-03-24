class Solution {
public:
    int bitcount(int n) {
        int c = 0;
        while (n) {
            if (n&1) {
                ++c;
            }
            n>>=1;
        }
        return c;
    }

    int sumcount(int n) {
        int s = 0;
        for (int i = 0; i < 9; ++i) {
            if (n&(1<<i)) {
                s += i + 1;
            }
        }
        return s;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        for (int i = 1; i < 512; ++i) {
            if (bitcount(i) == k && sumcount(i) == n) {
                vector<int> tmp;
                for (int j = 0; j < 9; ++j) {
                    if (i & (1<<j)) {
                        tmp.push_back(j+1);
                    }
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
