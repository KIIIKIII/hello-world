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
const int MAX = 1e5 + 5;
const int N = 100 + 5;
const int INF = 0x3f3f3f3f3f;

int n, m;
ll damage[MAX];

int main() {
	while (true) {
		scanf("%d", &n);
		if (!n)break;
		scanf("%d", &m);
		memset(damage, 0, sizeof(damage));
		while (m--) {
			int l, r, d;
			scanf("%d%d%d", &l, &r, &d);
			damage[r + 1] -= d;
			damage[l] += d;
		}
		for (int i = 2; i <= n; i++)
			damage[i] += damage[i - 1];
		for (int i = n - 1; i > 0; i--)
			damage[i] += damage[i + 1];
		int k, ans = 0;
		scanf("%d", &k);
		while (k--) {
			ll h, x;
			scanf("%lld%lld", &h, &x);
			if (h > damage[x])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
