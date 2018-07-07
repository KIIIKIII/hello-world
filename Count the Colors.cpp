#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 8005;
int n, col[MAXN << 2], vis[MAXN << 2], ans[MAXN << 2];
//记录染色、数颜色数目、记录答案

void update(int rt, int left, int right, int l, int r, int data) {
	//根、最左、最右、此处染色最左、此处染色最右，颜色
	if (l <= left && right <= r) {//染色范围大于根
		col[rt] = data;
		return;
	}
	if (col[rt] == data) return;//根已经染好此色
	if (col[rt] != -1) {//根已经染了其他色
		col[rt << 1] = col[rt << 1 | 1] = col[rt];//生成左右儿子染上根色
		col[rt] = -1;//根设置为未染色
	}
	int m = (left + right) / 2;//给儿子染新色
	if (l <= m)update(rt << 1, left, m, l, r, data);
	if (r > m)update(rt << 1 | 1, m + 1, right, l, r, data);
}
void query(int rt, int left, int right) {
	if (col[rt] >= 0) {//根已经染色，直接统计根部
		for (int i = left; i <= right; ++i)
			vis[i] = col[rt];//统计
		return;
	}
	if (left != right && col[rt] == -1) {//根未染色
		int m = (left + right) / 2;//向儿子统计
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
		for (int i = 1; i < MAXN; ) {//统计答案
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
