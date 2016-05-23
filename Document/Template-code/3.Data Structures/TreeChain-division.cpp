
const int maxn = 1e5+5;
int N, E, first[maxn], jump[maxn * 2], link[maxn * 2], val[maxn];
int id, idx[maxn], dep[maxn], top[maxn], far[maxn], son[maxn], cnt[maxn];

inline void add_Edge (int u, int v) {
    link[E] = v;
    jump[E] = first[u];
    first[u] = E++;
}

void dfs (int u, int pre, int d) {
    far[u] = pre;
    dep[u] = d;
    cnt[u] = 1;
    son[u] = 0;

    for (int i = first[u]; i + 1; i = jump[i]) {
        int v = link[i];
        if (v == pre)
            continue;
        dfs(v, u, d + 1);
        cnt[u] += cnt[v];
        if (cnt[son[u]] < cnt[v])
            son[u] = v;
    }
}

void dfs(int u, int rot) {
    top[u] = rot;
    idx[u] = ++id;
    if (son[u])
        dfs(son[u], rot);
    for (int i = first[u]; i + 1; i = jump[i]) {
        int v = link[i];
        if (v == far[u] || v == son[u])
            continue;
        dfs(v, v);
    }
}

void init () {
    int u, v;
    id = E = 0;
    memset(first, -1, sizeof(first));

	/*** input edge ***/

    dfs(1, 0, 0);
    dfs(1, 1);
}

void modify (int u, int v, int w) {
    int p = top[u], q = top[v];
    while (p != q) {
        if (dep[p] < dep[q]) {
            swap(p, q);
            swap(u, v);
        }
		/*** modify idx[p] ~ idx[u] ***/
        u = far[p];
        p = top[u];
    }

    if (dep[u] > dep[v])
		swap(u, v);
	/*** 点权 modify idx[u] ~ idx[v] ***/
	/*** 边权 modify idx[son[u]] ~ idx[v] ***/
}

int query (int u, int v) {
    int p = top[u], q = top[v], ret = 0;
    while (p != q) {
        if (dep[p] < dep[q]) {
            swap(p, q);
            swap(u, v);
        }
		/*** query idx[p] ~ idx[u] ***/
        u = far[p];
        p = top[u];
    }

    if (dep[u] > dep[v])
		swap(u, v);
	/*** 点权 query idx[u] ~ idx[v] ***/
	/*** 边权 query idx[son[u]] ~ idx[v] ***/
	return ret;
}
