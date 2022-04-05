class Solution {
public:

    void dfs(int pos, const string& num, int dep,
        long long res, long long mul, int target,
        vector<long long>& numbers, vector<char>& operators,
        vector<string>& ans) {

        if (pos >= num.size()) {
            if (res == target) {
                int idx = ans.size();
                ans.emplace_back(to_string(numbers[0]));
                for (int i = 1; i < dep; ++i) {
                    ans[idx] += operators[i];
                    ans[idx] += to_string(numbers[i]);
                }
            }
            return;
        }

        long long cur = 0;
        if (num[pos] == '0') {
            numbers[dep] = 0;
            operators[dep] = '+';
            dfs(pos+1, num, dep+1, res + numbers[dep], numbers[dep],
                target, numbers, operators, ans);

            if (dep) {
                operators[dep] = '-';
                dfs(pos+1, num, dep+1, res - numbers[dep], -numbers[dep],
                    target, numbers, operators, ans);

                operators[dep] = '*';
                dfs(pos+1, num, dep+1, res - mul + mul * numbers[dep],
                    mul * numbers[dep], target, numbers, operators, ans);
            }
            return;
        }
        for (int i = pos; i < num.size(); ++i) {
            cur = cur * 10 + (num[i] - '0');
            numbers[dep] = cur;
            operators[dep] = '+';
            dfs(i+1, num, dep+1, res + cur, cur, target, numbers, operators, ans);

            if (dep) {
                operators[dep] = '-';
                dfs(i+1, num, dep+1, res - cur, -cur, target, numbers, operators, ans);

                operators[dep] = '*';
                dfs(i+1, num, dep+1, res - mul + mul * cur, mul * cur, target, numbers, operators, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        vector<long long> numbers;
        vector<char> operators;

        numbers.resize(num.size());
        operators.resize(num.size());

        dfs(0, num, 0, 0, 0, target, numbers, operators, ans);
        return ans;
    }
};
