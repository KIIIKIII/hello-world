#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10000 + 5;

int f[MAX] = { 0 };
int main() {
	while (true) {
		int n, k, m;
		scanf("%d%d%d", &n, &k, &m);
		if (n == 0 && k == 0 && m == 0) break;
		f[1] = 0;
		for (int i = 2; i <= n; i++)
			f[i] = (f[i - 1] + k) % i;
		int ans = (f[n] + m - k + 1) % n;
		if (ans <= 0) ans += n;
		printf("%d\n", ans);
	}

	return 0;
}
