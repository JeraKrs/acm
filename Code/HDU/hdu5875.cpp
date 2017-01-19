/************************** 
* Author: Jerakrs
* Time: 2016.10.01
* Problem:	给定一个数组，每次查询区间[l, r]，
*			输出A[l] % A[l+1] % ... % A[r]
* Solve:	按左区间大小顺序遍历询问，维护优先队列，
*			每次取出val最大的询问，如果还在询问区间内就执行取模操作
* Complexity: o( nlog(m) )，每个查询值最多被取模30次左右
***************************/

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;

int N, M, A[maxn], R[maxn];

struct Item {
	int val, end, id;
	Item(int val = 0, int end = 0, int id = 0): val(val), end(end), id(id) {}
	friend bool operator < (const Item& a, const Item& b) {
		return a.val < b.val;
	}
};

struct Query{
	int id, l, r;
	Query(int id = 0, int l = 0, int r = 0):id(id), l(l), r(r) {}
	friend bool operator < (const Query& a, const Query& b) {
		return a.l < b.l;
	}
}Q[maxn];

void init () {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		Q[i].id = i;
		scanf("%d%d", &Q[i].l, &Q[i].r);
	}
}

void solve() {
	int mv = 0;
	sort(Q, Q + M);

	priority_queue<Item> que;


	for (int i = 1; i <= N; i++) {
		while (!que.empty() && que.top().val >= A[i]) {
			Item tmp = que.top();
			que.pop();

			if (tmp.end < i) {
				R[tmp.id] = tmp.val;
				continue;
			}

			tmp.val %= A[i];
			que.push(tmp);
		}

		while (mv < M && Q[mv].l == i) {
			que.push(Item(A[i], Q[mv].r, Q[mv].id));
			mv++;
		}
	}

	while (!que.empty()) {
		Item tmp = que.top();
		que.pop();
		R[tmp.id] = tmp.val;
	}
}

int main () {
	int cas;
	scanf("%d", &cas);
	while (cas--) {
		init();
		solve();
		for (int i = 0; i < M; i++)
			printf("%d\n", R[i]);
	}
	return 0;
}
