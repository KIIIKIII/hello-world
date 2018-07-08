#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 200 + 5;
const int INF = 0x3f3f3f3f3f;
int a[MAX] = { 0 }, p[MAX >> 1][MAX >> 1] = { 0 };
int dp[MAX][MAX >> 1] = { 0 };//dp[i][j]表示说长度为i且最后一个数为j的情况需要修改最少几次
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n1, n2;
		scanf("%d%d", &n1, &n2);
		memset(p, 0, sizeof(p));
		memset(a, 0, sizeof(a));
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < (MAX >> 1); j++) {
				dp[i][j] = INF;
			}
		}
		for (int i = 1; i <= n1; i++) dp[0][i] = 0;//边界
		for (int i = 1; i <= n2; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			p[x][y] = 1; p[y][x] = 1;
		}
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int ans = n;
		for (int t = 1; t <= n; t++) {//长度为t
			for (int i = 1; i <= n1; i++) {//前i个数
				for (int j = 1; j <= n1; j++) {
					if (i == j || p[i][j])//有路时，原路径对则上一个dp+0，不对则+1
						dp[t][i] = min(dp[t][i], dp[t - 1][j] + (i == a[t] ? 0 : 1));
				}
			}
		}
		for (int i = 1; i <= n1; i++) {
			ans = min(dp[n][i], ans);
		}
		printf("%d\n", ans);
	}

	return 0;
}
