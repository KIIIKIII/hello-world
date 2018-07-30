#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;

struct Edge {
	int from, to, dist;
};

struct HeapNode {
	int d, u;
	bool operator<(const HeapNode &rhs) const {
		return d > rhs.d;
	}
};

struct Dijkstra {
	int n, m;
	vector<Edge> edges;
	vector<int> G[MAXN];
	bool done[MAXN];
	ll d[MAXN];
	int p[MAXN];

	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist) {
		edges.push_back({ from, to, dist });
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	void dijkstra(int s, int curEdge) {
		priority_queue<HeapNode> Q;
		for (int i = 0; i < n; i++)
			d[i] = INF;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		memset(p, -1, sizeof(p));
		Q.push({ 0, s });
		while (!Q.empty()) {
			HeapNode x = Q.top();
			Q.pop();
			int u = x.u;
			if (done[u])
				continue;
			done[u] = true;
			for (int i = 0; i < G[u].size(); i++) {
				Edge &e = edges[G[u][i]];
				if (G[u][i] == curEdge / 2 * 2 || G[u][i] == curEdge / 2 * 2 + 1)
					continue;
				if (d[e.to] > d[u] + e.dist) {
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push({ d[e.to], e.to });
				}
			}
		}
	}
}arr;

int pre[MAXN];
int n, m, L;
ll s[MAXN][MAXN], A[MAXN];

int main() {
	while (scanf("%d%d%d", &n, &m, &L) != EOF) {
		int u, v, w;
		arr.init(n);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			u--, v--;
			arr.AddEdge(u, v, w);
		}
		ll ans = 0;
		memset(s, -1, sizeof(s));
		for (int i = 0; i < n; i++) {
			arr.dijkstra(i, -100);
			ll sum = 0;
			for (int j = 0; j < n; j++) {
				if (arr.d[j] == INF)
					arr.d[j] = L;
				sum += arr.d[j];
				pre[j] = arr.p[j];
			}
			A[i] = sum;
			ans += sum;
			for (int j = 0; j < n; j++) {
				if (j == i || pre[j] == -1)
					continue;
				ll tmp = 0;
				arr.dijkstra(i, pre[j]);
				for (int k = 0; k < n; k++) {
					if (arr.d[k] == INF)
						arr.d[k] = L;
					tmp += arr.d[k];
				}
				s[pre[j] / 2][i] = tmp;
			}
		}
		ll Max = 0;
		for (int i = 0; i < m; i++) {
			ll sum = 0;
			for (int j = 0; j < n; j++)
				if (s[i][j] == -1)
					sum += A[j];
				else sum += s[i][j];
				Max = max(Max, sum);
		}
		printf("%lld %lld\n", ans, Max);
	}
	return 0;
}
