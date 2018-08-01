#include <iostream>
#include <cstring>
using namespace std;
const int N = 105;
const int INF = 0x3f3f3f3f3f3f;
int G[N][N], d[N][N], r[N][N];
int m, n;

int f[3][2];
int main() {
	f[0][0] = -1; f[0][1] = 1; f[1][0] = 0; f[1][1] = 1; f[2][0] = 1; f[2][1] = 1;
	while (~scanf("%d%d", &m, &n)) {
		int ans = INF, t = 0;
		memset(G, 0, sizeof(G));
		memset(d, INF, sizeof(d));
		memset(r, INF, sizeof(r));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &G[i][j]);
		for (int i = 1; i <= m; i++) {
			d[i][n] = G[i][n];
			r[i][n] = 0;
		}
		for (int i = n - 1; i >= 1; i--) {
			for (int j = 1; j <= m; j++) {
				for (int k = 0; k < 3; k++) {
					int tx = j + f[k][0], ty = i + f[k][1];
					tx = (tx < 1 ? m : tx); tx = (tx > m ? 1 : tx);
					if ((d[tx][ty] + G[j][i] < d[j][i]) || ((d[tx][ty] + G[j][i]) == d[j][i] && tx < r[j][i])) {
						d[j][i] = d[tx][ty] + G[j][i];
						r[j][i] = tx;
					}
				}
			}
		}

		for (int i = 1; i <= m; i++)
			if (d[i][1] < ans) { ans = d[i][1]; t = i; }
		printf("%d", t);
		for (int i = 1; i <= n - 1; i++) {
			printf(" %d", r[t][i]);
			t = r[t][i];
		}
		printf("\n%d\n", ans);
	}
	return 0;
}
