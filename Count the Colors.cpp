#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 8005;
int n, col[MAXN << 2], vis[MAXN << 2], ans[MAXN << 2];

void update(int rt, int left, int right, int l, int r, int data) {
	if (l <= left && right <= r) {
		col[rt] = data;
		return;
	}
	if (col[rt] == data) return;
	if (col[rt] != -1) {
		if (col[rt] != -1) {
			col[rt << 1] = col[rt << 1 | 1] = col[rt];
			col[rt] = -1;
		}
	}
	int m = (left + right) / 2;
	if (l <= m)update(rt << 1, left, m, l, r, data);
	if (r > m)update(rt << 1 | 1, m + 1, right, l, r, data);
}
void query(int rt, int left, int right) {
	if (col[rt] >= 0) {
		for (int i = left; i <= right; ++i)
			vis[i] = col[rt];
		return;
	}
	if (left != right && col[rt] == -1) {
		int m = (left + right) / 2;
		query(rt << 1, left, m);
		query(rt << 1 | 1, m + 1, right);
	}
}

int main() {
	while (~scanf("%d", &n)) {
		memset(col, -1, sizeof(col));
		for (int i = 0; i < n; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (a >= b) continue;
			update(1, 1, MAXN, a + 1, b, c);
		}
		memset(vis, -1, sizeof(vis));
		query(1, 1, MAXN);
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i < MAXN; ) {
			int color = vis[i], j = i + 1;
			if (color == -1) { i++; continue; }
			while (vis[j] != -1 && vis[j] == color && j < MAXN) ++j;
			ans[color]++;
			i = j;
		}
		for (int i = 0; i < MAXN; i++) {
			if (ans[i]) printf("%d %d\n", i, ans[i]);
		}
		printf("\n");
	}
	return 0;
}
