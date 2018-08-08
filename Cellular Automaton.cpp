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
const int N = 500 + 5;
const int M = 10000 + 5;
const int INF = 0x3f3f3f3f3f;

int n, m, d, k;
ll ans[N], matrix[N], c[N];

void mul(ll a[], ll b[]) {
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			c[i] += a[j] * b[(i - j + n) % n];
	for (int i = 0; i < n; i++)
		b[i] = c[i] % m;
}

int main() {
	while(~scanf("%d%d%d%d", &n, &m, &d, &k)) {
		memset(ans, 0, sizeof(ans));
		memset(matrix, 0, sizeof(matrix));
		for (int i = 0; i < n; i++)
			scanf("%d", &ans[i]);
		matrix[0] = 1;
		for (int i = 1; i <= d; i++)
			matrix[i] = matrix[n - i] = 1;
		while(k) {
			if(k & 1)
				mul(matrix, ans);
			mul(matrix, matrix);
			k >>= 1;
		}
		for (int i = 0; i < n - 1; i++)
			printf("%lld ", ans[i]);
		printf("%lld\n", ans[n - 1]);
	}
	
	return 0;
}
