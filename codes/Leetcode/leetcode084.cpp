class Solution {
	public:
		int largestRectangleArea(vector<int>& heights) {
			int n = heights.size();
			int* l = new int[n];
			int* r = new int[n];

			int* t = new int[n+1];
			int* p = new int[n+1];

			t[0] = -1, p[0] = -1;
			int c = 1;
			for (int i = 0; i < n; i++) {
				while (c > 0 && t[c-1] >= heights[i]) c--;
				l[i] = p[c-1] + 1;
				t[c] = heights[i];
				p[c++] = i;
			}

			p[0] = n, c = 1;
			for (int i = n-1; i >= 0; i--) {
				while (c > 0 && t[c-1] >= heights[i]) c--;
				r[i] = p[c-1] - 1;
				t[c] = heights[i];
				p[c++] = i;
			}

			int ans = 0;
			for (int i = 0; i < n; i++)
				ans = max(ans, (r[i] - l[i] + 1) * heights[i]);

			delete[] l;
			delete[] r;
			delete[] t;
			delete[] p;

			return ans;
		}
};
