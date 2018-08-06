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
const int INF = 0x3f3f3f3f3f;
const int maxn = 100 + 5;
const int maxv = 10000 + 5;

int n, m, MST;
bool vis[maxn];
int father[maxn];
int dist[maxn];
int graph[maxn][maxn];
bool used[maxn][maxn];
int max_edge[maxn][maxn];

int prim() {
	int ans = 0;
	dist[1] = 0;
	vis[1] = true;
	father[1] = -1;
	for (int i = 2; i <= n; i++) {
		father[i] = 1;
		dist[i] = graph[1][i];
	}
	for (int i = 1; i < n; i++) {
		int v = -1;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && (v == -1 || dist[j] < dist[v])) 
				v = j;
		ans += dist[v];
		vis[v] = true;
		used[father[v]][v] = used[v][father[v]] = false;
		for (int j = 1; j <= n; j++)
			if (vis[j])
				max_edge[v][j] = max_edge[j][v] = max(max_edge[father[v]][j], dist[v]);
			else if (graph[v][j] < dist[j]) {
				dist[j] = graph[v][j];
				father[j] = v;
			}
	}
	return ans;
}

int second_prim() {
	int ans = INF;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (used[i][j]) ans = min(ans, MST + graph[i][j] - max_edge[i][j]);
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(max_edge, -1, sizeof(max_edge));
		memset(graph, INF, sizeof(graph));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			graph[a][b] = graph[b][a] = c;
			used[a][b] = used[b][a] = true;
		}
		MST = prim();
		if (MST == second_prim()) 
			printf("Not Unique!\n");
		else printf("%d\n", MST);
	}
	return 0;
}
