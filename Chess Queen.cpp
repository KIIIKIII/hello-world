#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000000 + 5;
const int INF = 0x3f3f3f3f3f;

int main() {
	while (true) {
		unsigned long long int n, m;
		scanf("%lld%lld", &n, &m);
		if (!n && !m) break;
		if (n > m) swap(n, m);
		printf("%lld\n", n * m * (n + m - 2) + 2 * n * (n - 1) * (3 * m - n - 1) / 3);
	}

	return 0;
}
