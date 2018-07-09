#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

const int MAX = 1000 + 5;
int a[MAX] = { 0 };
int find(int x) {
	return x != a[x] ? a[x] = find(a[x]) : x;
}
void unionset(int x, int y) {
	int rootx = find(x);
	int rooty = find(y);
	if (rootx == rooty) return;
	a[rootx] = rooty;//////////////////////////////////////////////////////////////////////////////////////
}
int main() {
	int n, m;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		for (int i = 0; i < MAX; i++) a[i] = i;
		scanf("%d", &m);
		int ans = 0;
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			unionset(x, y);
		}
		for (int i = 1; i < n; i++) {
			if (find(i) != find(i + 1)) {
				unionset(i, i + 1);
				ans++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
