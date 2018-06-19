class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> ans;
			vector<int> cur;
			for (int i = 0; i < numRows; i++) {
				cur.push_back(1);
				for (int j = i-1; j > 0; j--)
					cur[j] += cur[j-1];
				ans.push_back(cur);
			}
			return ans;
		}
};
