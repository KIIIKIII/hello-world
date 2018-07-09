#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000 + 5;
const int mod = 10056;
long long c[MAX][MAX] = { 0 }, ans[MAX] = { 0 };//c[i][j]表示i个马，分j次到达的方法
int main() {
	c[0][0] = 1;
	for (int i = 1; i < MAX; i++) {
		long long sum = 0;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod * j % mod;//第i马和前面的马搭伙到达+第i马单独到达
			sum = (sum % mod + c[i][j]) % mod;
		}
		ans[i] = sum;
	}
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %lld\n", t, ans[n]);
	}

	return 0;
}
