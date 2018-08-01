#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
using namespace std;
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f3f;
int pos[N], dp[N][N];
int main() {
	int L, n;
	while (scanf("%d", &L) == 1 && L != 0) {
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) 
			scanf("%d", pos + i);
		pos[n + 1] = L;
		pos[0] = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 2; j <= n + 1; j++) {
				dp[i][j] = INF;
				for (int k = i; k < j; k++) 
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + pos[j] - pos[i]);
			}
		}
		printf("The minimum cutting is %d.\n", dp[0][n + 1]);
	}
	return 0;
}
