class Solution {
	public:
		vector<int> grayCode(int n) {
			vector<int> ans;

			ans.push_back(0);
			int bias = 1;
			while (n--) {
				int k = ans.size();
				while (k) ans.push_back(ans[--k] + bias);
				bias *= 2;
			}
			return ans;
		}
};
