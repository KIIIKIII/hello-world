#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e3 + 5, INF = 0x3f3f3f3f3f3f;
typedef long long ll;
int sum[N], dp[N];
struct lamp {
	int v, k, c, l;
}a[N];

int cmp(lamp x, lamp y) {
	return x.v < y.v;
}

int main() {
	int n;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		int ans = 0;
		memset(a, 0, sizeof(a));
		memset(sum, 0, sizeof(sum));
		memset(dp, INF, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d%d", &a[i].v, &a[i].k, &a[i].c, &a[i].l);
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + a[i].l;
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				dp[i] = min(dp[i], dp[j] + a[i].k + a[i].c * (sum[i] - sum[j]));
			}
		}
		printf("%d\n", dp[n]);
	}

	return 0;
}
