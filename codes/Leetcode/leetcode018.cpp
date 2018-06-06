class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>> ans;

			int n = nums.size(), i = 0;
			sort(nums.begin(), nums.end());

			while (i < n) {
				int a = nums[i], j = i + 1;
				while (j < n) {
					int b = nums[j], k = j + 1, t = n - 1;

					while (k < t) {
						int c = nums[k], d = nums[t];
						int s = a + b + c + d;

						if (s == target) ans.push_back({a, b, c, d});
						if (s <= target) while (k < t && nums[k] == c) k++;
						if (s >= target) while (k < t && nums[t] == d) t--;
					}

					while (j < n && nums[j] == b) j++;
				}
				while (i < n && nums[i] == a) i++;
			}
			return ans;
		}
};
