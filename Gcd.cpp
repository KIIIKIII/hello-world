#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e7 + 5;
typedef long long LL;

LL pri[MAXN], pri_num;
LL mu[MAXN];//莫比乌斯函数值
bool vis[MAXN];

void mobius(int N) {
	pri_num = 0;//素数个数
	memset(vis, false, sizeof(vis));
	vis[1] = true;
	mu[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) {
			pri[pri_num++] = i;
			mu[i] = -1;
		}
		for (int j = 0; j < pri_num && i * pri[j] < N; j++) {
			vis[i * pri[j]] = true;//标记非素数
								 //eg:i=3,i%2,mu[3*2]=-mu[3]=1;----;i=6,i%5,mu[6*5]=-mu[6]=-1;
			if (i % pri[j])
				mu[i * pri[j]] = -mu[i];
			else {
				mu[i * pri[j]] = 0;
				break;
			}

		}
	}
}

int main() {
	LL n;
	mobius(MAXN);
	while (~scanf("%lld", &n)) {
		LL ans = (LL)0;
		for (LL i = 0; pri[i] <= n; i++) {
			for (LL j = 1; j <= n / pri[i]; j++)
				ans += (LL)(mu[j] * ((n / pri[i]) / j) * ((n / pri[i]) / j));
		}
		printf("%lld\n", ans);
	}
	return 0;
}

