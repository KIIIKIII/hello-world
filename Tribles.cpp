#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 1000 + 5;
double p[maxn], f[maxn];//f[i]表示一只麻球i天死亡的概率
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ) {
		int n, k, m;
		double ans = 0;
		scanf("%d%d%d", &n, &k, &m);
		for (int i = 0; i < n; i++)
			scanf("%lf", &p[i]);
		memset(f, 0, sizeof(f));
		f[0] = 0; f[1] = p[0];
		for (int i = 2; i <= m; i++) {
			for (int j = 0; j < n; j++) {
				f[i] += p[j] * pow(f[i - 1], j);// f[i] = p0 + p1 * f(i - 1) + p2 * f(i - 1)^2 + p3 * f(i - 1)^3....pn-1 * f(i - 1)^n-1
			}
		}
		printf("Case #%d: %.7lf\n", ++t, pow(f[m], k));
	}

	return 0;
}
