#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int a[20005];
//b[i]表示i左边比i小的个数，d[i]表示i右边比i小的个数
int b[20005], d[20005];
int C[100005];
int T, n;
inline int lowbit(int x) {
	return x & -x;
}
int Sum(int x) {
	int ret = 0;
	while (x > 0) {
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}
int Add(int x, int m) {
	while (x <= 100000) {
		C[x] += m;
		x += lowbit(x);
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		memset(C, 0, sizeof(C));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) {
			Add(a[i], 1);
			b[i] = Sum(a[i] - 1);
		}
		memset(C, 0, sizeof(C));
		for (int i = n; i >= 1; i--) {
			Add(a[i], 1);
			d[i] = Sum(a[i] - 1);
		}
		long long  int ans = 0;
		for (int i = 2; i < n; i++) {
			ans += b[i] * (n - i - d[i]) + (i - 1 - b[i]) * d[i];
		}
		printf("%lld\n", ans);
	}
}
