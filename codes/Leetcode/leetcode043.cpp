class Solution {
	public:
		string reverseString(string s) {
			int n = s.size();
			string ret = s;

			for (int i = 0; i < n; i++) 
				ret[i] = s[n-i-1];
			return ret;
		}

		string multiply(string num1, string num2) {
			num1 = reverseString(num1);
			num2 = reverseString(num2);
			int t;
			string ans = "";

			for (int i = 0; i < num1.size(); i++) {
				t = 0;
				for (int j = 0; j < num2.size(); j++) {
					if (i+j >= ans.size()) ans += '0';
					t += (num1[i]-'0') * (num2[j]-'0') + (ans[i+j]-'0');
					ans[i+j] = '0' + t % 10;
					t /= 10;
				}
				int k = i + num2.size();
				while (t) {
					if (k >= ans.size()) ans += '0';
					t += ans[k] - '0';
					ans[k++] = '0' + t % 10;
					t /= 10;
				}
			}
			int n = ans.size();
			while (n && ans[n-1] == '0') n--;
			ans = reverseString(ans.substr(0, max(n, 1)));
			return ans;
		}
};
