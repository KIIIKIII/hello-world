#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 3000 + 5;
int d[MAX] = { 0 }, w[MAX] = { 0 };
int main() {
	int n, v, last = 0;
	long long sum = 0;
	scanf("%d%d", &n, &v);
	for (int i = 0; i < n; i++) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		if (last < t1) last = t1;
		if (d[t1]) 
			d[t1] += t2;
		else
			d[t1] = t2;
	}
	for (int t = 1; t <= last + 1; t++) {
		w[t] = v;
		if (d[t - 1]) {
			sum += min(w[t], d[t - 1]);
			w[t] = (w[t] - d[t - 1] > 0) ? (w[t] - d[t - 1]) : 0;
			d[t - 1] = (d[t - 1] - v > 0) ? (d[t - 1] - v) : 0;
		}
		if (w[t] && d[t]) {
			sum += min(w[t], d[t]);
			int temp = w[t];
			w[t] = (w[t] - d[t] > 0) ? (w[t] - d[t]) : 0;
			d[t] = (d[t] - temp > 0) ? (d[t] - temp) : 0;
		}
	}
	printf("%lld\n", sum);
	return 0;
}
