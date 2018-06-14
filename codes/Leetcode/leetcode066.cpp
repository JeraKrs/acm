class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			vector<int> ans;
			int n = digits.size();
			for (int i = n-1; i >= 0; i--) ans.push_back(digits[i]);

			int tmp = 1, m = 0;
			while (tmp) {
				if (m >= ans.size()) ans.push_back(0);
				tmp += ans[m];
				ans[m++] = tmp % 10;
				tmp /= 10;
			}

			n = ans.size();
			for (int i = 0; i + i < n; i++) {
				tmp = ans[i];
				ans[i] = ans[n-i-1];
				ans[n-i-1] = tmp;
			}
			return ans;
		}
};
