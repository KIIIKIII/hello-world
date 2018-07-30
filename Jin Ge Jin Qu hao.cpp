#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 50 + 5, J = 678;
int a[MAX];
int f[MAX][180 * MAX + J], s[MAX][180 * MAX + J];

void solve(int n, int t) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			f[i][j] = f[i - 1][j];
			s[i][j] = s[i - 1][j];
			if (j > a[i]) {
				if (f[i][j] < f[i - 1][j - a[i]] + 1) {
					f[i][j] = f[i - 1][j - a[i]] + 1;
					s[i][j] = s[i - 1][j - a[i]] + a[i];
				}
				if (f[i][j] == f[i - 1][j - a[i]] + 1) {
					s[i][j] = max(s[i][j], s[i - 1][j - a[i]] + a[i]);
				}
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++) {
		int n, t;
		scanf("%d%d", &n, &t);
		memset(a, 0, sizeof(a));
		memset(s, 0, sizeof(s));
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		solve(n, t);
		printf("Case %d: %d %d\n", kase, f[n][t] + 1, s[n][t] + J);
	}

	return 0;
}
