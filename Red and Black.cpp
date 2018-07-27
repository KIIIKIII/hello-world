#include<cstdio>

const int MAX = 20 + 5;
char a[MAX][MAX];
int m, n, cnt;
void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return;
	if (a[x][y] == '#')
		return;
	else {
		cnt++;
		a[x][y] = '#';
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
	}
}
int main() {
	int x, y;
	while (scanf("%d%d", &m, &n), m | n) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			getchar();
			for (int j = 0; j < m; j++)
				scanf("%c", &a[i][j]);
		}
		for (int i = 0; i < n; i++) {
			int k = 0;
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '@') {
					x = i; y = j;
					break;
				}
			}
		}
		dfs(x, y);
		printf("%d\n", cnt);
	}
}
