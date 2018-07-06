#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 300 + 5;
int s[MAX][MAX] = { 0 };
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int l = n * m / k, a = n * m % k + l;
	int flag = 1, i = 1, j = 1;
	for (int count = 0; count < k; count++) {
		l = n * m / k;
		printf("%d ", (flag ? a : l));
		if (flag) {
			printf("%d %d ", i, j);
			flag ? a-- : l--;
		}
		while (flag ? (a > 0) : (l > 0)) {
			if (j < m && i % 2) {
				j++;
				printf("%d %d ", i, j);
				flag ? a-- : l--;
				if (!(flag ? (a > 0) : (l > 0))) break;
			}
			if (j > 1 && !(i % 2)) {
				j--;
				printf("%d %d ", i, j);
				flag ? a-- : l--;
				if (!(flag ? (a > 0) : (l > 0))) break;
			}
			if (j == m || j == 1) {
				i++;
				printf("%d %d ", i, j);
				flag ? a-- : l--;
				if (!(flag ? (a > 0) : (l > 0))) break;
			}
		}
		printf("\n");
		flag = 0;
	}
	return 0;
}
