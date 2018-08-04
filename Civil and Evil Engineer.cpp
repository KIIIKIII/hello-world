/**
*
* @authors Your Name (you@example.org)
* @date    2018-08-04 09:40:00
* @version $Id$
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 1000 + 5;
const int M = 10000 + 5;
const int INF = 0x3f3f3f3f3f;

class Edge {
public:
	int from, to, w;
	Edge(int a = 0, int b = 0):to(a), w(b){ }
}edge[N];

vector<Edge>vec[N];
int cost[N];
bool vis[N];
int n;
void addedge(int u, int v, int w) {
	vec[u].push_back(Edge(v, w));
	vec[v].push_back(Edge(u, w));
}

int prim(int u) {
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
		cost[i] = INF;
	}
	int sum = 0;
	cost[u] = 0;
	while (true) {
		int v = -1;
		for (int i = 0; i <= n; i++)
			if (vis[i] == false && (v == -1 || cost[i] < cost[v]))
				v = i;
		if (v == -1)
			break;
		vis[v] = true;
		sum = sum + cost[v];
		for (int i = 0; i < vec[v].size(); i++)
			if (vis[vec[v][i].to] == false)
				cost[vec[v][i].to] = min(cost[vec[v][i].to], vec[v][i].w);
	}
	return sum;
}

int prim2(int u) {
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
		cost[i] = 0;
	}
	int sum = 0;
	cost[u] = 0;
	while (true) {
		int v = INF;
		for (int i = 0; i <= n; i++)
			if (vis[i] == false && (v == INF || cost[i] > cost[v]))
				v = i;
		if (v == INF)
			break;
		vis[v] = true;
		sum = sum + cost[v];
		for (int i = 0; i < vec[v].size(); i++)
			if (vis[vec[v][i].to] == false)
				cost[vec[v][i].to] = max(cost[vec[v][i].to], vec[v][i].w);
	}
	return sum;
}

void init() {
	for (int i = 0; i <= n; i++)
		vec[i].resize(0);
}

int main() {
	int t;
	scanf("%d", &t);
	int cas = 1;
	while (t--) {
		scanf("%d", &n);
		init();
		int u, v, w;
		while (scanf("%d%d%d", &u, &v, &w) && u + v + w)
			addedge(u, v, w);
		int mincost = prim(0);
		int maxcost = prim2(0);
		int tot = mincost + maxcost;
		printf("Case %d: ", cas++);
		if (!(tot & 1))
			printf("%d\n", tot / 2);
		else
			printf("%d/2\n", tot);

	}
	return 0;
}
