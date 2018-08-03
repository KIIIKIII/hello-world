#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 400000 + 10;
const int M = 10000 + 5;
const int INF = 0x3f3f3f3f3f;

int num[N];
int dp[N];
int cnt = 1;

int main() {
	int n, t = 1;
	cnt = 1;
	num[0] = 0;
	for (int i = 1; i < M; i++) {
		t = pow(i, 2);
		if (num[cnt - 1] + t >= N) break;
		num[cnt] = num[cnt - 1] + t;
		cnt++;
	}
	for (int i = 2; i < M; i++) {
		if (num[cnt - 1] > N) {
			cnt--;
			break;
		}
		num[cnt++] = pow(i, 3);
	}
	sort(num + 1, num + cnt);
	for (int i = 0; i <= N; i++) 
		dp[i] = INF;
	dp[0] = 0;
	for (int i = 0; i <= N; i++) 
		for (int j = 1; j < cnt; j++) 
			if (i >= num[j])
				dp[i] = min(dp[i], dp[i - num[j]] + 1);
	while (scanf("%d", &n) == 1 && n != -1)
		printf("%d\n", dp[n]);
	return 0;
}
