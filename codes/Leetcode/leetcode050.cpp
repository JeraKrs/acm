class Solution {
	public:
		double myPow(double x, int n) {
			long long k = n;
			if (k < 0) { k = -k, x = 1/x; }
			double ans = 1;

			while (k) {
				if (k&1) ans *= x;
				x = x*x;
				k >>= 1;
			}
			return ans;
		}
};
