class Solution {
	public:
		string getPermutation(int n, int k) {
			bool* f = new bool[n+1];
			int* c = new int[n+1];
			c[0] = 1, f[0] = false;
			for (int i = 1; i <= n; i++) c[i] = c[i-1]*i, f[i] = false;

			string ans = "";
			for (int i = 0; i < n; i++) {
				int t = 1;
				while (k > c[n-i-1]) { k -= c[n-i-1]; t++; }

				for (int j = 1; j <= n; j++) {
					if (f[j] == false) t--;
					if (t == 0) {
						ans += ('0' + j);
						f[j] = true;
						break;
					}
				}
			}
			return ans;
		}
};
