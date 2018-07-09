#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 20000 + 5;
int pa[maxn], d[maxn];
int find(int x) {//路径压缩，同时维护d[i]：结点i到树根的距离
	if (pa[x] != x) {
		int root = find(pa[x]);
		d[x] += d[pa[x]];
		return pa[x] = root;
	}
	else return x;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, u, v;
		char cmd[9];
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			pa[i] = i;//每个结点单独是一棵树
			d[i] = 0;
		}
		while (scanf("%s", cmd) && cmd[0] != 'O') {
			if (cmd[0] == 'E') {
				scanf("%d", &u);
				find(u);
				printf("%d\n", d[u]);
			}
			if (cmd[0] == 'I') {
				scanf("%d%d", &u, &v);
				pa[u] = v;
				d[u] = abs(u - v) % 1000;
			}
		}
	}
	return 0;
}
