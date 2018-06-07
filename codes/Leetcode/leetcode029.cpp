class Solution {
	public:
		int divide(int dividend, int divisor) {
			int sign = 1;
			long long my_dividend = dividend;
			long long my_divisor = divisor;
			if (my_dividend < 0) my_dividend = -my_dividend, sign = -sign;
			if (my_divisor < 0) my_divisor = -my_divisor, sign = -sign;

			int n = 0;
			long long nums[50], count[50];
			nums[0] = my_divisor, count[0] = 1;

			for (int i = 1; ; i++) {
				long long x = nums[i-1];
				if (nums[i-1] + nums[i-1] > my_dividend) break;
				nums[i] = nums[i-1] + nums[i-1];
				count[i] = count[i-1] + count[i-1];
				n++;
			}

			long long ans = 0;
			while (n >= 0) {
				if (my_dividend >= nums[n]) {
					ans += count[n];
					my_dividend -= nums[n];
				}
				n--;
			}

			ans = sign == -1 ? -ans : ans;
			if (ans == 2147483648) ans--;
			return ans;
		}
};
