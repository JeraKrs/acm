class Solution {
public:
    bool dfs(int pos, const string& num, int cnt, long long first, long long second) {
        if (pos >= num.size()) {
            return cnt > 3;
        }
        
        long long cur = 0;
        int n = cnt <= 2 ? min(num.size(), pos+num.size()/2) : num.size();
        for (int i = pos; i < n; ++i) {
            cur = cur * 10 + num[i] - '0';
            if (cnt > 2 && cur > first + second) {
                return false;
            }
            if (cnt <= 2 || cur == first + second) {
                if (dfs(i+1, num, cnt + 1, second, cur)) {
                    return true;
                }
            }
            if (num[pos] == '0') break;
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        return dfs(0, num, 1, 0, 0);
    }
};
