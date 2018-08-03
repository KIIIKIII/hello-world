#include<stdio.h>
const int N = 1e5 + 5;
int a[N];
int vag[N];
int find(int x) {
	return x != a[x] ? a[x] = find(a[x]) : a[x];
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			a[i] = i;
			vag[i] = 1;
		}
		for (int i = 1; i < n; i++) {
			int zx, zy, zz;
			scanf("%d%d%d", &zx, &zy, &zz);
			int dx = find(zx);
			int dy = find(zy);
			if (!zz) {
				a[dx] = dy;
				vag[dy] = vag[dy] + vag[dx];
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int ax = find(i);
			ans = ans ^ (vag[ax]);
		}
		printf("%d\n", ans);
	}
}
