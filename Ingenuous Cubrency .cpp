#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 10000;
int n;
long long tri[22];
long long d[22][maxn + 1];
int main() {
	for (int i = 1; i <= 21; i++) {
		tri[i] = pow(i, 3); 
	}
	d[0][0] = 1;
	for (int i = 1; i <= 21; i++) {
		for (int j = 0; j <= maxn; j++) {
			if (j >= tri[i]) d[i][j] += d[i][j - tri[i]];
			d[i][j] += d[i - 1][j];
		}
	}
	while (~scanf("%d", &n)) {
		printf("%lld\n", d[21][n]);
	}
	return 0;
}
