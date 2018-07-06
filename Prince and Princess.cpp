#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 250 * 250 + 5;
const int INF = 1000000000;
int a[MAX] = { 0 }, b[MAX] = { 0 };
int g[MAX] = { 0 };
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, p, q;
		scanf("%d%d%d", &n, &p, &q);
		for (int i = 0; i <= p; i++) scanf("%d", &a[i]);
		for (int i = 0; i <= q; i++) scanf("%d", &b[i]);
		for (int i = 0; i <= q; i++) {
			int flag = 0;
			for (int j = 0; j <= p; j++) {
				if (b[i] == a[j]) {
					b[i] = j + 1;
					flag = 1;
					break;
				}
			}
			if (!flag) b[i] = 0;
		}
		for (int i = 1; i <= q + 1; i++) g[i] = INF;
		int ans = 0;
		for (int i = 0; i <= q; i++) {
			long long k = lower_bound(g + 1, g + q + 1, b[i]) - g;
			g[k] = b[i];
			if (k > ans) ans = k;
		}
		printf("Case %d: %d\n", t, ans);
	}

	return 0;
}
