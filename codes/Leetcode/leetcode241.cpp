class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int n = expression.size();
        for (int i = 0; i < n; ++i) {
            if (expression[i] < '0' || expression[i] > '9') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1, n-i-1));

                for (auto& lhs : left) {
                    for (auto& rhs : right) {
                        if (expression[i] == '+') {
                            ans.push_back(lhs + rhs);
                        } else if (expression[i] == '-') {
                            ans.push_back(lhs - rhs);
                        } else {
                            ans.push_back(lhs * rhs);
                        }
                    }
                }
            }
        }

        if (ans.size() == 0) {
            ans.push_back(atoi(expression.c_str()));
        }
        return ans;
    }
};
