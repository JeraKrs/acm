class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			vector<vector<int>> ret;
			sort(nums.begin(), nums.end());

			int n = nums.size(), i = 0;
			while (i < n) {
				int a = nums[i];
				int j = i + 1, k = n - 1;; 

				while (j < k) {
					int b = nums[j], c = nums[k];
					int s = a + b + c;

					if (s == 0) ret.push_back({a, b, c});
					if (s <= 0) while (j < k && nums[j] == b) j++;
					if (s >= 0) while (j < k && nums[k] == c) k--;
				}
				while (nums[i] == a && i < n) i++;
			}
			return ret;
		}
};
