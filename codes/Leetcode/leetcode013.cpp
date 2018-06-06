class Solution {
	public:
		int romanToInt(string s) {
			int p[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
			string q[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; 

			int ans = 0, t = 0, n = q[0].size();
			for (int i = 0; i < s.size();) {
				while (i + n > s.size()) n = q[++t].size();

				bool flag = true;
				for (int j = 0; j < n; j++) if (q[t][j] != s[i+j])
					flag = false;

				if (flag) {
					ans += p[t];
					i += n;
				} else {
					n = q[++t].size();
				}
			}
			return ans;
		}
};
