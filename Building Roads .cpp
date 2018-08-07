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

bool vis[N];
int n, m;
double map[N][N], dis[N];

struct point {
	double x, y;
}p[N];

double prim() {
	double sum = 0, temp = INF;
	int k;
	for (int i = 1; i <= n; i++)
		dis[i] = map[1][i];
	dis[1] = 0;
	vis[1] = true;
	for (int i = 1; i <= n; i++) {
		temp = INF;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && temp > dis[j]) {
				temp = dis[j];
				k = j;
			}
		if (temp == INF)
			break;
		vis[k] = true;
		sum += temp;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dis[j] > map[k][j])
				dis[j] = map[k][j];
	}
	return sum;
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		memset(vis, false, sizeof(vis));
		for (int i = 1; i < n; i++)
			for (int j = i; j <= n; j++)
				map[i][j] = map[j][i] = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2) + 0.0);
		while (m--) {
			int x, y;
			scanf("%d%d", &x, &y);
			map[x][y] = map[y][x] = 0;
		}
		double ans = prim();
		printf("%.2lf\n", ans);
	}

	return 0;
}
