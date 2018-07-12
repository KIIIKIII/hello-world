#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000 + 5;

int n, q;
int a[N];
int val[N], cnt[N], num[N], lef[N], righ[N];
int d[N][50], len;

void RMQ_init() {
	int i, j, k;
	for (i = 1; i <= len; i++)
		d[i][0] = cnt[i];
	for (j = 1; (1 << j) <= len + 1; j++)
		for (i = 1; i + (1 << j) - 1 <= len; i++)
			d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
}

int RMQ(int l, int r) {
	int k = 0;
	while ((1 << (k + 1)) <= r - l + 1) k++;
	return max(d[l][k], d[r - (1 << k) + 1][k]);
}

int main() {
	int i, j, k, l, r;
	while (~scanf("%d", &n), n) {
		scanf("%d", &q);
		len = 1;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &a[1]);
		val[len] = a[1];
		cnt[len] = 1;

		num[1] = len;
		lef[0] = 1;
		for (i = 2; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] == a[i - 1]) {
				cnt[len]++;
				num[i] = len;
			}
			else {
				righ[len] = i - 1;
				len++;
				val[len] = a[i];
				cnt[len] = 1;
				num[i] = len;
				lef[len] = i;
			}
		}
		RMQ_init();
		while (q--)
		{
			scanf("%d%d", &l, &r);
			if (num[l] == num[r])
			{
				printf("%d\n", r - l + 1);
			}
			else {
				int ans = 0;
				if (num[l] + 1 <= num[r] - 1)
					ans = RMQ(num[l] + 1, num[r] - 1);
				ans = max(ans, max(righ[num[l]] - l + 1, r - lef[num[r]] + 1));
				printf("%d\n", ans);
			}
		}
	}

	return 0;
}
