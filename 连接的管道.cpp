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
const int maxn = 1000 + 5;
const int maxd = 5000000 + 5;
const int INF = 0x3f3f3f3f3f;
const int dir[2][2] = { 0, 1, 1, 0 };
int mat[maxn][maxn], fa[maxd];

struct Node {
	int u, v, d;
	friend bool operator < (Node p, Node q) { return p.d < q.d; }
}edge[maxd];

int find(int u) {
	return fa[u] != u ? fa[u] = find(fa[u]) : u;
}

int main() {
	int T, Case = 1;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int cnt = 0;
		for (int i = 0; i <= n * m; i++) 
			fa[i] = i;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &mat[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				for (int d = 0; d < 2; d++) {
					int x = i + dir[d][0];
					int y = j + dir[d][1];
					if (x >= 0 && x < n && y >= 0 && y < m) {
						edge[cnt].u = i * m + j;
						edge[cnt].v = x * m + y;
						edge[cnt].d = abs(mat[x][y] - mat[i][j]);
						cnt++;
					}
				}
			}
		sort(edge, edge + cnt);
		int ans = 0;
		for (int i = 0; i < cnt; i++) {
			int x = find(edge[i].u);
			int y = find(edge[i].v);
			if (x != y) {
				ans += edge[i].d;
				fa[x] = y;
			}
		}
		printf("Case #%d:\n%d\n", Case++, ans);
	}
	return 0;
}
