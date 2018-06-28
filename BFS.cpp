#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;
const int MAX = 10000;
const int INF = 0x3f3f3f3f;

bool used[MAX];

struct node {
	int len;
}e[MAX][MAX], dis[MAX];//利用临街矩阵存图，两个权值用结构体来存储，也可以用pair类型

int n, m, s, t;
void Dijkstra(int a) {
	for (int i = 1; i <= n; i++) {//dis的初始化
		dis[i].len = INF;
	}
	memset(used, false, sizeof(used));
	dis[a].len = 0;//把起始点初始为0
	while (true) {
		int v = -1;
		for (int i = 1; i <= n; i++) {
			if (!used[i] && (v == -1 || (dis[i].len < dis[v].len) || (dis[i].len == dis[v].len)))
				v = i;
		}
		if (v == -1) break;//如果所有点都被使用过，就结束
		used[v] = true;
		for (int i = 1; i <= n; i++) {
			if (dis[i].len > dis[v].len + e[v][i].len) {
				dis[i].len = dis[v].len + e[v][i].len;
			}
			else if (dis[i].len == dis[v].len + e[v][i].len) {
				dis[i].len = dis[v].len + e[v][i].len;
			}
		}
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				e[i][j].len = 0;
			}
			else {
				e[i][j].len = INF;
			}
		}
	}
	int x, y;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		e[x][y].len = 1;
	}
	Dijkstra(s);
	printf("%d\n", dis[t].len);

	return 0;
}
