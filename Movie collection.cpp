#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 200000 + 6;
int tree[maxn], num[maxn];
int lowbit(int x) {
	return x & -x;
}
void update(int x, int v) {
	for (int i = x; i < maxn; i += lowbit(i))
		tree[i] += v;
}
int query(int x) {
	int ret(0);
	for (int i = x; i > 0; i -= lowbit(i))
		ret += tree[i];
	return ret;
}
int main() {
	int ncase, n, i, j, q, cur, x;
	scanf("%d", &ncase);
	while (ncase--) {
		scanf("%d%d", &n, &q);
		memset(tree, 0, sizeof(tree));
		for (i = 1; i <= n; i++) {
			num[i] = n - i + 1;
			update(i, 1);
		}
		cur = n;
		for (i = 1; i <= q; i++) {
			scanf("%d", &x);
			printf("%d", n - query(num[x]));
			if (i != q)
				printf(" ");
			update(num[x], -1);
			num[x] = ++cur;
			update(num[x], 1);

		}
		printf("\n");
	}
	return 0;
}
