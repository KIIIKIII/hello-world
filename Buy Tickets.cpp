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
const int N = 1000000 + 10;
const int M = 200 + 5;
const int INF = 0x3f3f3f3f3f;

int p[N], v[N], ans[N];
class node {
public:
	int l, r, num;
}t[N];

void build(int n, int l, int r) {
	t[n].l = l;
	t[n].r = r;
	t[n].num = r - l + 1;
	if (l == r) return;
	build(2 * n, l, (l + r) / 2);
	build(2 * n + 1, (l + r) / 2 + 1, r);
}

void update(int n, int p, int v) {
	int mid = (t[n].l + t[n].r) / 2;
	if (t[n].l == t[n].r) {
		t[n].num = 0;
		ans[t[n].l] = v;
		return;
	}
	if (t[2 * n].num >= p)
		update(2 * n, p, v);
	else
		update(2 * n + 1, p - t[2 * n].num, v);
	t[n].num = t[2 * n].num + t[2 * n + 1].num;
}

int main() {
	int n;
	while (~scanf("%d", &n)) {
		build(1, 1, n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &p[i], &v[i]);
		for (int i = n - 1; i >= 0; i--)
			update(1, p[i] + 1, v[i]);
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}

	return 0;
}
