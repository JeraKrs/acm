class Solution {
public:
    int bitcount(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        int counts[100] = {0};
        int maxvalue = 0;

        for (int i = 1; i <= n; ++i) {
            int bitsum = bitcount(i);
            counts[bitsum]++;
            maxvalue = std::max(maxvalue, counts[bitsum]);
        }
        int ans = 0;
        for (int i = 0; i < 100; ++i) {
            if (counts[i] == maxvalue) ++ans;
        }
        return ans;
    }
};
