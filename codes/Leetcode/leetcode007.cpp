class Solution {
	public:
		int reverse(int x) {
			int flag = 1, ans = 0;
			if (x < 0) {
				flag = -1;
				x = -x;
			}

			while (x) {
				int temp = ans * 10 + x % 10 * flag;
				if (temp / 10 != ans) return 0;
				ans = temp;
				x /= 10;
			}
			return ans;
		}
};
