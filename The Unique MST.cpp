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
const int MAXN = 100 + 5;

bool vis[MAXN];
int lowc[MAXN];
int pre[MAXN];
int Max[MAXN][MAXN];
bool used[MAXN][MAXN];
int cost[MAXN][MAXN];

int Prim(int cost[][MAXN], int n) {
	int ans = 0;
	memset(vis, false, sizeof(vis));
	memset(Max, 0, sizeof(Max));
	memset(used, false, sizeof(used));
	vis[0] = true;
	pre[0] = -1;
	for (int i = 1; i < n; i++) {
		lowc[i] = cost[0][i];
		pre[i] = 0;
	}
	lowc[0] = 0;
	for (int i = 1; i < n; i++) {
		int minc = INF;
		int p = -1;
		for (int j = 0; j < n; j++)
			if (!vis[j] && minc > lowc[j]) {
				minc = lowc[j];
				p = j;
			}
		if (minc == INF)return -1;
		ans += minc;
		vis[p] = true;
		used[p][pre[p]] = used[pre[p]][p] = true;
		for (int j = 0; j < n; j++) {
			if (vis[j])Max[j][p] = Max[p][j] = max(Max[j][pre[p]], lowc[p]);
			if (!vis[j] && lowc[j] > cost[p][j])
			{
				lowc[j] = cost[p][j];
				pre[j] = p;
			}
		}
	}
	return ans;
}
int ans;
int smst(int cost[][MAXN], int n) {
	int Min = INF;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (cost[i][j] != INF && !used[i][j])
				Min = min(Min, ans + cost[i][j] - Max[i][j]);
	if (Min == INF) return -1;
	return Min;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int u, v, w;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (i == j)cost[i][j] = 0;
				else cost[i][j] = INF;
			}
		while (m--) {
			scanf("%d%d%d", &u, &v, &w);
			u--; v--;
			cost[u][v] = cost[v][u] = w;
		}
		ans = Prim(cost, n);
		if (ans == -1 || ans == smst(cost, n))
			printf("Not Unique!\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}