class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int sign = 1;
        long long num = numerator;
        long long den = denominator;
        if (numerator < 0) {
            num = -1LL * numerator;
            sign *= -1;
        }
        if (denominator < 0) {
            den = -1LL * denominator;
            sign *= -1;
        }
        
        string ans = (sign < 0 && num ? "-" : "");
        ans += to_string(num / den);
        num = num % den;
        map<long long, int> g;

        if (num) {
            ans += '.';
            while (num) {

                if (g.find(num) != g.end()) {
                    ans.insert(g[num], "(");
                    ans += ')';
                    break;
                }
                g[num] = ans.size();

                int x = (num * 10) / den;
                int y = (num * 10) % den;
                ans += to_string(x);
                num = y;
            }
        }
        return ans;
    }
};
