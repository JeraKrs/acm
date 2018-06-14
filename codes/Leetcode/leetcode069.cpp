class Solution {
	public:
		int mySqrt(int x) {
			if (x < 2)  return x;

			int l = 1, r = x;
			while (l + 1 < r) {
				int mid = (1LL + l + r) >> 1;
				long long tmp = 1LL * mid * mid;
				if (tmp <= x) l = mid;
				else r = mid;
			}
			return l;
		}
};
