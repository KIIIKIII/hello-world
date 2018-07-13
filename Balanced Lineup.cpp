#include<iostream>
#include<cstring>
#include<cstdio>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;

const int N = 50005;
int FMAX[N][20], FMIN[N][20];

void RMQ(int n) {
	for (int j = 1; j != 20; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (i + (1 << j) - 1 <= n) {
				FMAX[i][j] = max(FMAX[i][j - 1], FMAX[i + (1 << (j - 1))][j - 1]);
				FMIN[i][j] = min(FMIN[i][j - 1], FMIN[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
}

int main() {
	int num, query;
	int a, b;
	while (scanf("%d %d", &num, &query) != EOF) {
		for (int i = 1; i <= num; ++i) {
			scanf("%d", &FMAX[i][0]);
			FMIN[i][0] = FMAX[i][0];
		}
		RMQ(num);
		while (query--) {
			scanf("%d%d", &a, &b);
			int k = (int)(log(b - a + 1.0) / log(2.0));
			int maxsum = max(FMAX[a][k], FMAX[b - (1 << k) + 1][k]);
			int minsum = min(FMIN[a][k], FMIN[b - (1 << k) + 1][k]);
			printf("%d\n", maxsum - minsum);
		}
	}
	return 0;
}
