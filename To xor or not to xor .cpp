/**
*
* @authors Your Name (you@example.org)
* @date    2018-08-04 09:40:00
* @version $Id$
*/
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
const int INF = 0x3f3f3f3f3f;
const int N = 100 + 5;
int n;
bool vis[N];
int a[N][N];

int main() {
	while (~scanf("%d", &n)) {
		ll ans = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			ll x, k = 0;
			scanf("%lld", &x);
			while (x) {
				a[k++][i] = x % 2;
				x /= 2;
			}
		}
		for (int i = 0; i <= 63; i++)
			a[i][n] = 1;
		for (int k = 63; k >= 0; k--) {
			ans <<= 1;
			int col = 0;
			for (; col < n; col++)
				if (a[k][col] && !vis[col]) {
					vis[col] = 1;
					ans |= 1;
					break;
				}
			if (col == n) {
				if (!a[k][n])
					ans |= 1;
			}
			else {
				for (int i = k - 1; i >= 0; i--)
					if (a[i][col])
						for (int j = 0; j <= n; j++)
							a[i][j] ^= a[k][j];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
