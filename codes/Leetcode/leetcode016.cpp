class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {
			int ret = 0, dist = -1;
			sort(nums.begin(), nums.end());

			int n = nums.size(), i = 0;
			while (i < n) {
				int a = nums[i];
				int j = i + 1, k = n - 1;; 

				while (j < k) {
					int b = nums[j], c = nums[k];
					int s = a + b + c;

					if (dist == -1 || abs(s - target) < dist) {
						dist = abs(s - target);
						ret = s;
					}

					if (s <= target) while (j < k && nums[j] == b) j++;
					if (s >= target) while (j < k && nums[k] == c) k--;
				}
				while (nums[i] == a && i < n) i++;
			}
			return ret;
		}
};
