class Solution {
	public:
		string reverseString(string a) {
			int n = a.size();
			for (int i = 0; i + i < n; i++) {
				char t = a[i];
				a[i] = a[n-i-1];
				a[n-i-1] = t;
			}
			return a;
		}

		string addBinary(string a, string b) {
			a = reverseString(a), b = reverseString(b);
			int n = a.size(), m = b.size();
			string ans = "";
			int t = 0, k = 0;
			while (t || k < n || k < m) {
				if (k < n) t += a[k] - '0';
				if (k < m) t += b[k] - '0';
				ans += '0' + (t % 2);
				t /= 2;
				k++;
			}
			return reverseString(ans);
		}
};
