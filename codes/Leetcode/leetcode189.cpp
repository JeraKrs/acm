class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        return gcd(b % a, a);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) {
            return;
        }
        k %= n;
        int g = gcd(n - k, n);
        int d = k;
        for (int i = 0; i < g; ++i) {
            int move = i;
            int value = nums[move];

            do {
                int next = (move + d) % n;
                int temp = nums[next];
                nums[next] = value;
                value = temp;
                move = next;
            } while (move != i);
        }
    }
};
