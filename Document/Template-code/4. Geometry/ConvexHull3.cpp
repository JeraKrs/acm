struct Face {
	int v[3];
	Face (int a = 0, int b = 0, int c = 0) { v[0] = a, v[1] = b, v[2] = c;}
	Vector3 normal (Point3 *p) const { return getCross(p[v[1]] - p[v[0]], p[v[2]]-p[v[0]]); }
	int cansee (Point3 *p, int i) const {
		return getDot(p[i]-p[v[0]], normal(p)) > 0 ? 1 : 0;
	}
};

int vis[1005][1005];
double rand01() { return rand() / (double) RAND_MAX; }
double randeps() { return (rand01() - 0.5) * eps; }
Point3 addNoise(Point3 p) { return Point3(p.x+randeps(), p.y+randeps(), p.z+randeps()); }

vector<Face> CH3D (Point3 *o, int n, Point3* p) {
	for (int i = 0; i < n; i++) p[i] = addNoise(o[i]);

	memset(vis, -1, sizeof(vis));
	vector<Face> cur;
	cur.push_back(Face(0, 1, 2));
	cur.push_back(Face(2, 1, 0));

	for (int i = 3; i < n; i++) {
		vector<Face> net;
		for (int j = 0; j < cur.size(); j++) {
			Face& f = cur[j];
			int res = f.cansee(p, i);
			if (!res) net.push_back(f);
			for (int k = 0; k < 3; k++) vis[f.v[k]][f.v[(k+1)%3]] = res;
		}

		for (int j = 0; j < cur.size(); j++) {
			for (int k = 0; k < 3; k++) {
				int a = cur[j].v[k], b = cur[j].v[(k+1)%3];
				if (vis[a][b] != vis[b][a] && vis[a][b])
					net.push_back(Face(a, b, i));
			}
		}
		cur = net;
	}
	return cur;
}
