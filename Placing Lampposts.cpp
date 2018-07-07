#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1000 + 5;
const int M = 2000;
vector<int> adj[MAX];
int vis[MAX][2], d[MAX][2];

int dp(int i, int j, int f) {
	//DFS+dp   f是i的父节点
	if (vis[i][j]) return d[i][j];
	vis[i][j] = 1;
	int &ans = d[i][j];

	//放灯总是合法决策
	ans = M;
	for (int k = 0; k < adj[i].size(); k++) {
		if (adj[i][k] != f) //父结点之外相邻节点是子结点
			ans += dp(adj[i][k], 1, i); //父结点为i
	}
	if (!j && f >= 0) ans++; //i不是根，父结点未放灯

	if (j || f < 0) { //i是根或其父结点已放灯，i才可以不放灯
		int sum = 0;
		for (int k = 0; k < adj[i].size(); k++) {
			if (adj[i][k] != f)
				sum += dp(adj[i][k], 0, i);
		}
		if (f >= 0) sum++; //i不是根
		ans = min(ans, sum);
	}
	return ans;
}
int main() {
	int T = 0;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) adj[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);//无向图
		}
		memset(vis, 0, sizeof(vis));
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!vis[i][0]) //新树
				ans += dp(i, 0, -1);//i是根，父结点不存在，为-1
		}
		printf("%d %d %d\n", ans / M, m - ans % M, ans % M);//从x计算三个整数
	}

	return 0;
}
