class Solution {
	public:
		string reverseString(string s) {
			int n = s.size();
			string ret = s;

			for (int i = 0; i < n; i++) 
				ret[i] = s[n-i-1];
			return ret;
		}
};
