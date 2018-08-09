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
const int N = 200 + 5;
const int M = 1000000 + 5;
const int INF = 0x3f3f3f3f3f;

int flow[N][N], cap[N][N], p[N], c[N];
void BFS(int &maxflow, int n) {
	queue<int>q;
	maxflow = 0;
	bool finish = false;
	memset(flow, 0, sizeof(flow));
	while (!finish) {
		memset(p, 0, sizeof(p));
		memset(c, 0, sizeof(c));
		c[1] = INF; p[1] = -1;
		q.push(1);
		while (!q.empty()) {
			int pos = q.front();
			q.pop();
			for (int i = 1; i <= n; i++) {
				if (!c[i] && flow[pos][i] < cap[pos][i]) {
					c[i] = min(c[pos], cap[pos][i] - flow[pos][i]);
					p[i] = pos;
					q.push(i);
				}
			}
		}
		if (!c[n])
			finish = true;
		maxflow += c[n];
		int pos = n;
		while (!finish && pos != 1) {
			flow[p[pos]][pos] += c[n];
			flow[pos][p[pos]] -= c[n];
			pos = p[pos];
		}
	}
}

int main() {
	int n, m, maxflow, ca = 0, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &m, &n);
		memset(cap, 0, sizeof(cap));
		for (int i = 1; i <= n; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			cap[x][y] += z;
		}
		BFS(maxflow, m);
		printf("Case %d: %d\n", ++ca, maxflow);
	}

	return 0;
}
