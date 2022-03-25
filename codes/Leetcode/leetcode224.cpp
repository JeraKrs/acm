class Solution {
public:
    int64_t dfs(const string& nums, int& pos) {
        int64_t s = 0;
        int sign = 1;
        int64_t t = 0;

        while (pos < nums.size()) {
            char c = nums[pos++];
            if (c >= '0' && c <= '9') {
                t = t * 10 + c - '0';
            } else if (c == '(') {
                s += sign * dfs(nums, pos);
                sign = 1;
            } else if (c == '-') {
                s += sign * t;
                sign = -1;
                t = 0;
            } else if (c == '+') {
                s += sign * t;
                sign = 1;
                t = 0;
            } else if (c == ')') {
                break;
            }
        }
        s += sign * t;
        return s;
    }
    int calculate(string s) {
        int pos = 0;
        return dfs(s, pos);
    }
};
