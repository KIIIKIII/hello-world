#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 50 + 5;
int k[MAX] = { 0 }, s[MAX][MAX] = { 0 }, a[MAX] = { 0 };
int main() {
	int n, v, sum = 0;
	scanf("%d%d", &n, &v);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k[i]);
		int flag = 1;
		for (int j = 0; j < k[i]; j++) {
			scanf("%d", &s[i][j]);
			if (flag && v > s[i][j]) {
				a[i] = 1;
				sum++;
				flag = 0;
			}
		}
	}
	printf("%d\n", sum);
	if (sum) {
		for (int i = 0; i < n; i++)
			if (a[i])
				printf("%d ", i + 1);
		printf("\n");
	}

	return 0;
}
