#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int mod = 1000007;
const int MAX = 500 + 5;
int c[MAX][MAX] = { 0 };
int main() {
	c[0][0] = 1;
	for (int i = 0; i < MAX; i++) {
		c[i][0] = c[i][i] = 1;//边界条件
		for (int j = 1; j < i; j++) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;//计算c
		}
	}
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int m, n, k, sum = 0;
		scanf("%d%d%d", &m, &n, &k);
		for (int s = 0; s < 16; s++) {//枚举所有16种搭配方式
			int b = 0, p = n, q = m;//b统计集合个数，p和q是可以放置的行列数
			if (s & 1) {//第一行没有石头，可以放石头的行数p-1
				p--;
				b++;
			}
			if (s & 2) {//最后一行没有石头，可以放石头的行数p-1
				p--;
				b++;
			}
			if (s & 4) {//第一列没有石头，可以放石头的列数q-1
				q--;
				b++;
			}
			if (s & 8) {//最后一列没有石头，可以放石头的列数q-1
				q--;
				b++;
			}
			if (b & 1)
				sum = (sum + mod - c[p * q][k]) % mod;//奇数个条件做减法
			else
				sum = (sum + c[p * q][k]) % mod;//偶数个条件做加法
		}
		printf("Case %d: %d\n", t, sum);
	}

	return 0;
}
