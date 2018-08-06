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
const int MAX = 20000 + 5;
const int N = 100 + 5;
const int INF = 0x3f3f3f3f3f;

int dir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
int len[N][N], a[N][N];
int m, n;
int dp(int x, int y) {
	int ms = 0;
	if (len[x][y] != 0)
		return len[x][y];
	for (int k = 0; k < 4; k++) {
		if (dir[k][0] + x < 0 || dir[k][1] + y < 0 || dir[k][0] + x > m - 1 || dir[k][1] + y > n - 1)
			continue;
		if (a[dir[k][0] + x][dir[k][1] + y] < a[x][y])
			ms = max(ms, dp(dir[k][0] + x, dir[k][1] + y));
	}
	len[x][y] = ms + 1;
	return len[x][y];
}

int main() {
	int Max;
	while (~scanf("%d%d", &m, &n)) {
		memset(a, 0, sizeof(a));
		memset(len, 0, sizeof(len));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &a[i][j]);
		Max = -1;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				Max = max(Max, dp(i, j));
		printf("%d\n", Max);
	}
	return 0;
}
