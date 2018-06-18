#include <cstdio>
#include <cstring>

long long int a[2001] = { 0 };
long long int m[2001][2001] = { 0 }; 

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		scanf("%lld", &a[i]);
	
	for (int i = 1; i <= n; i++) m[i][i] = 0;
	for (int r = 2; r <= n; r++) 
		for (int i = 1; i <= n - r + 1; i++) {
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + a[i - 1] * a[i] * a[j];
			for (int k = i + 1; k < j; k++) {
				int t = m[i][k] + m[k + 1][j] + a[i - 1] * a[k] * a[j];
				if (t < m[i][j]) {
					m[i][j] = t;
				}
			}
		}

	printf("%lld\n", m[1][n]);

	return 0;
}
