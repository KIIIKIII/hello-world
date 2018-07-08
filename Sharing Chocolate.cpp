#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 16;
const int MAXW = 100 + 5;
int a[MAXN] = { 0 },
	sum[1 << MAXN] = { 0 },
	f[1 << MAXN][MAXW] = { 0 }, 
	vis[1 << MAXN][MAXW] = { 0 };
int bitcount(int x) {
	return x == 0 ? 0 : bitcount(x >> 1) + (x & 1);
}
int dp(int s, int x) {
	if (vis[s][x]) return f[s][x];//记忆化
	vis[s][x] = 1;
	int &ans = f[s][x];
	if (bitcount(s) == 1) return ans = 1;//集合含有且只含有一个元素
	int y = sum[s] / x;//另一条边
	for (int s0 = (s - 1) & s; s0; s0 = (s0 - 1) & s) {//枚举s的所有子集
		int s1 = s - s0;
		if (sum[s0] % x == 0 && dp(s0, min(x, sum[s0] / x)) && dp(s1, min(x, sum[s1] / x)))
			return ans = 1;//可切x边  且补集可切
		if (sum[s0] % y == 0 && dp(s0, min(y, sum[s0] / y)) && dp(s1, min(y, sum[s1] / y)))
			return ans = 1;//可切y边  且补集可切
	}
	return ans = 0;
}
int main() {
	int T = 1;
	while (true) {
		int n, x, y;
		scanf("%d", &n);
		if (!n)break;
		scanf("%d%d", &x, &y);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		memset(sum, 0, sizeof(sum));
		for (int s = 0; s < (1 << n); s++) {
			for (int i = 0; i < n; i++) {
				if (s & (1 << i)) //若s含有i
					sum[s] += a[i];
			}
		}
		memset(vis, 0, sizeof(vis));
		int ALL = (1 << n) - 1;//全集
		int ans = 0;
		if (sum[ALL] != x * y || sum[ALL] % x != 0) ans = 0;//块数不够或者形状不对
		else ans = dp(ALL, min(x, y));
		printf("Case %d: %s\n", T++, ans ? "Yes" : "No");
	}

	return 0;
}
