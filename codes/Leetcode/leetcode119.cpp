class Solution {
	public:
		vector<int> getRow(int rowIndex) {
			vector<int> ans;
			ans.push_back(1);
			for (int i = 0; i < rowIndex; i++) ans.push_back(0);
			for (int i = 1; i <= rowIndex; i++) {
				for (int j = i; j; j--) ans[j] += ans[j-1];
			}
			return ans;
		}
};
