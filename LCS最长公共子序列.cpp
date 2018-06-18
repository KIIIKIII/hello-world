#include <cstdio>
#include <cstring>

int a[1000005] = { 0 }, b[1000005] = { 0 };
int c[1005][1005] = { 0 }, d[1005][1005] = { 0 };
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);

	for (int i = 1; i <= n; i++) c[i][0] = 0;
	for (int i = 1; i <= n; i++) c[0][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				d[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				d[i][j] = 2;
			}
			else {
				c[i][j] = c[i][j - 1];
				d[i][j] = 3;
			}
		}
	printf("%d\n", c[n][n]);

	return 0;
}
