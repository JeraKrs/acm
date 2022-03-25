class Solution {
public:
    int64_t dfs(int64_t sum, const string& s, int& i) {
        int sign = s[i++] == '*' ? 1 : 0;
        int64_t num = 0;
        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            } else if (s[i] == '+' || s[i] == '-') {
                if (sign) {
                    sum *= num;
                } else {
                    sum /= num;
                }
                i--;
                return sum;
            } else if (s[i] == '*' || s[i] == '/') {
                if (sign) {
                    sum *= num;
                } else {
                    sum /= num;
                }

                num = 0;
                sign = s[i] == '*' ? 1 : 0;
            }
            ++i;
        }
        if (sign) {
            sum *= num;
        } else {
            sum /= num;
        }
        return sum;
    }
    int calculate(string s) {
        int64_t sum = 0;
        int sign = 1;
        int64_t num = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            } else if (s[i] == '+' || s[i] == '-') {
                sum += sign * num;
                num = 0;
                sign = s[i] == '+' ? 1 : -1;
            } else if (s[i] == '*' || s[i] == '/') {
                sum += sign * dfs(num, s, i);
                sign = 1;
                num = 0;
            }
        }
        sum += sign * num;
        return sum;
    }
};
