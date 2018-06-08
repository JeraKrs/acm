class Solution {
	public:
		int trap(vector<int>& height) {
			int n = height.size(), h;
			int* l = new int[n];
			int* r = new int[n];

			h = 0;
			for (int i = 0; i < n; i++) {
				h = max(h, height[i]);
				l[i] = h;
			}

			h = 0;
			for (int i = n-1; i >= 0; i--) {
				h = max(h, height[i]);
				r[i] = h;
			}

			int ans = 0;
			for (int i = 0; i < n; i++)
				ans += min(l[i], r[i]) - height[i];

			delete l;
			delete r;
			return ans;
		}
};
