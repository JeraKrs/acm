class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while (n != 1) {
            if (s.find(n) != s.end()) {
                return false;
            }
            s.insert(n);
            int m = 0;
            while (n) {
                int d = n % 10;
                m += d*d;
                n /= 10;
            }
            n = m;
        }
        return true;
    }
};
