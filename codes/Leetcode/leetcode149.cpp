/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
	public:
		int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

		int maxPoints(vector<Point>& points) {
			map<pair<int,int>, int> g;
			int n = points.size(), ans = 0;

			for (int i = 0; i < n; i++) {
				int overlap = 0, tmp = 0;
				g.clear();

				for (int j = i + 1; j < n; j++) {
					int dy = points[j].y - points[i].y;
					int dx = points[j].x - points[i].x;

					if (dy == 0 && dx == 0) {
						overlap++;
						continue;
					}

					int d = gcd(dy, dx); dy /= d, dx /= d;

					if (dy < 0) dy *= -1, dx *= -1;

					pair<int,int> k = make_pair(dy, dx);
					if (g.count(k)) g[k]++;
					else g[k] = 1;

					tmp = max(tmp, g[k]);
				}
				ans = max(ans, tmp + overlap + 1);
			}
			return ans;
		}
};
