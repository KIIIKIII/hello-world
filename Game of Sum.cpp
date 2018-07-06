#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAX = 100 + 5;

int a[MAX] = { 0 }, s[MAX] = { 0 };
int d[MAX][MAX] = { 0 };
int f[MAX][MAX] = { 0 }, g[MAX][MAX] = { 0 };
int main() {
	while (true) {
		memset(a, 0, sizeof(a));
		memset(d, 0, sizeof(d));
		int n;
		scanf("%d", &n);
		if (!n) break;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			s[i] = s[i - 1] + a[i];
			d[i][i] = f[i][i] = g[i][i] = a[i];
		}
		for (int L = 1; L < n; L++) {
			for (int i = 1; i + L <= n; i++) {
				int j = i + L;
				int m = 0;
				m = min(m, f[i + 1][j]);
				m = min(m, g[i][j - 1]);
				d[i][j] = s[j] - s[i - 1] - m;
				f[i][j] = min(d[i][j], f[i + 1][j]);
				g[i][j] = min(d[i][j], g[i][j - 1]);
			}
		}
		printf("%d\n", 2 * d[1][n] - s[n]);
	}

	return 0;
}
