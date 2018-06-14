class Solution {
	public:
		int climbStairs(int n) {
			int a = 0, b = 1;
			while (n--) {
				int t = a + b;
				a = b;
				b = t;
			}
			return b;
		}
};
