#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

class node {
public:
	int from;
	int to;
	int value;
};

const int N = 1100;
const int Max = 0xfffffff;
queue<int>q;
vector<node> g[N];
int visit[N], dis[N], map[N][N], f[N];
int n, m;

void spfa(int flag) {
	while (!q.empty()) q.pop();
	memset(visit, 0, sizeof(visit));
	if (flag) memset(f, -1, sizeof(f));
	for (int i = 0; i <= n; i++) dis[i] = Max;
	q.push(1);
	visit[1] = 1;
	dis[1] = 0;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i = 0; i < g[curr].size(); i++) {
			int k = g[curr][i].to;
			int y = dis[curr] + g[curr][i].value;
			if (dis[k] > y) {
				dis[k] = y;
				if (flag) f[k] = curr;
				if (!visit[k]) {
					visit[k] = 1;
					q.push(k);
				}
			}
		}
		visit[curr] = 0;
	}
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < N; i++) g[i].clear();
		for (int i = 1; i <= m; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			node e;
			e.from = x; e.to = y; e.value = z;
			g[e.from].push_back(e);
			e.from = y; e.to = x;
			g[e.from].push_back(e);
		}
		spfa(1);
		int j = n;
		int mmax = -1;
		while (f[j] > 0) {
			int x, y, v;
			for (int i = 0; i < g[j].size(); i++)
				if (g[j][i].to == f[j]) {
					v = g[j][i].value;
					g[j][i].value = Max / 10;
					x = i;
					break;
				}
			for (int i = 0; i < g[f[j]].size(); i++)
				if (g[f[j]][i].to == j) {
					g[f[j]][i].value = Max / 10;
					y = i;
					break;
				}
			spfa(0);
			g[j][x].value = v;
			g[f[j]][y].value = v;
			j = f[j];
			if (dis[n] > mmax && dis[n] != Max) mmax = dis[n];
		}
		printf("%d\n", mmax);
	}
	return 0;
}
