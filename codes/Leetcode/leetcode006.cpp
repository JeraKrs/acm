class Solution {
	public:
		string convert(string s, int numRows) {
			if (numRows == 1) return s;
			string ret = "";
			int gap = 2 * numRows - 2, len = s.length();

			for (int i = 0; i < numRows; i++) {
				int p = gap - 2 * i;
				for (int j = i; j < len; j += gap) {
					ret += s[j];
					if (p + j < len && i && i != numRows-1) ret += s[j+p];
				}
			}
			return ret;
		}
};
