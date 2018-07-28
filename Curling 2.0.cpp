#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 20 + 5;
int a[MAX][MAX] = { 0 }, w, h;
int sx, sy, ans;
int dir[4][2] = { -1,0,1,0,0,-1,0,1 };

bool check(int x, int y) {
	if (x >= 0 && x < h && y >= 0 && y < w)
		return true;
	return false;
}

void dfs(int step, int x, int y) {
	int nx, ny;
	if (step >= 10)
		return;
	step++;
	for (int i = 0; i < 4; i++) {
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if (check(nx, ny) && a[nx][ny] != 1) {
			while (check(nx, ny) && a[nx][ny] != 1 && a[nx][ny] != 3) {
				nx += dir[i][0];
				ny += dir[i][1];
			}
			if (a[nx][ny] == 3) {
				if (ans > step)
					ans = step;
				return;
			}
			else if (a[nx][ny] == 1) {
				a[nx][ny] = 0;
				dfs(step, nx - dir[i][0], ny - dir[i][1]);
				a[nx][ny] = 1;
			}
		}
	}
	return;
}

int main() {
	while (true) {
		scanf("%d%d", &w, &h);
		if (!w && !h) break;
		memset(a, 0, sizeof(a));
		ans = 11;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &a[i][j]);
				if (a[i][j] == 2) {
					sx = i;
					sy = j;
				}
			}
		}
		dfs(0, sx, sy);
		if (ans < 11)
			printf("%d\n", ans);
		else 
			printf("-1\n");
	}

	return 0;
}
