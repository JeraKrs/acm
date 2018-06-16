class Solution {
	public:
		bool isInterleave(string s1, string s2, string s3) {
			int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
			if (n1 + n2 != n3) return false;

			set<pair<int,int>> g;
			g.insert(make_pair(0, 0));

			for (int i = 0; i < n3; i++) {
				set<pair<int,int>> t;
				for (set<pair<int,int>>::iterator iter = g.begin(); iter != g.end(); iter++) {
					int x = iter->first;
					int y = iter->second;

					if (x < n1 && s1[x] == s3[i])
						t.insert(make_pair(x+1, y));
					if (y < n2 && s2[y] == s3[i])
						t.insert(make_pair(x, y+1));
				}
				g = t;
			}
			return g.size();
		}
};
