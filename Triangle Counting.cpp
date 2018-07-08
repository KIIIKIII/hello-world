#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000000 + 5;
long long f[MAX] = { 0 };
int main() {
	f[3] = 0;
	for (long long x = 4; x <= MAX; x++) {
		f[x] = f[x - 1] + ((x - 1) * (x - 2) / 2 - (x - 1) / 2) / 2;
	}
	while (true) {
		long long int n;
		scanf("%lld", &n);
		if (n < 3) break;
		printf("%lld\n", f[n]);
	}

	return 0;
}
