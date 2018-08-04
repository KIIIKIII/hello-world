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
const int N = 10000 + 5;
const int M = 10000 + 5;
const int INF = 0x3f3f3f3f3f;


class node {
public:
	int u, v, w;
	friend bool operator<(node a, node b) { return a.w < b.w; }
}eg[N];
int n, m, fa[N];

int Find(int x) {
	return x != fa[x] ? fa[x] = Find(fa[x]) : fa[x];
}
int num;
int Kruskal() {
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	sort(eg, eg + num);
	int ans = 0, cnt = 0, d = -1;
	for (int i = 0; i < num; i++) {
		int x = Find(eg[i].u);
		int y = Find(eg[i].v);
		if (x == y) {
			d = i;
			continue;
		}
		else {
			fa[x] = y;
			ans += eg[i].w;
			cnt++;
		}
	}
	if (d != -1) {
		num--;
		eg[d] = eg[num];
	}
	if (cnt == n - 1) 
		return ans;
	return -1;
}
int main() {
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		printf("Case %d:\n", cas++);
		num = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &eg[num].u, &eg[num].v, &eg[num].w);
			num++;
			printf("%d\n", Kruskal());
		}
	}
	return 0;
}
