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
const int N = 1e6 + 5;
const int M = 4000000 + 5;
const int INF = 0x3f3f3f3f3f;

char p[N];
int f[N];
int main() {
	int n, cas = 0;
	while (scanf("%d", &n) == 1 && n) {
		scanf("%s", p);
		f[0] = 0; f[1] = 0;
		for (int i = 1; i < n; i++) {
			int j = f[i];
			while (j && p[i] != p[j])
				j = f[j];
			f[i + 1] = (p[i] == p[j] ? j + 1 : 0);
		}
		printf("Test case #%d\n", ++cas);
		for (int i = 2; i <= n; i++)
			if (f[i] > 0 && i % (i - f[i]) == 0)
				printf("%d %d\n", i, i / (i - f[i]));
		printf("\n");
	}

	return 0;
}
