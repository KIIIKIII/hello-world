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
const int MAX = 1e6 + 5;
const int N = 100 + 5;
const int INF = 0x3f3f3f3f3f;

int a[MAX], b[MAX];
int main() {
	int num, n, m, t = 0;
	for (int i = 2; i * i < MAX; i++) 
		if (!a[i]) 
			for (int j = i * i; j < MAX; j += i) 
				a[j] = 1;
	for (int i = 2; i < MAX; i++) {
		if (!a[i]) {
			int l = 0;
			int h = i;
			while (h) {
				l += h % 10;
				h /= 10;
			}
			if (!a[l])
				t++;
		}
		b[i] = t;
	}

	scanf("%d", &num);
	for (int k = 1; k <= num; k++) {
		scanf("%d%d", &n, &m);
		printf("Case #%d: %d\n", k, b[m] - b[n - 1]);
	}
	return 0;
}
