#include <cstdio>
using namespace std;

long long int f(int n, int *a) {
	long long int sum = a[0], b = 0;
	for (int i = 0; i < n; i++) {
		if (b > 0) {
			b += a[i];
		}
		else b = a[i];
		if (b > sum) sum = b;
	}
	return sum;
}

int main() {
	int n, a[200005] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	long long int sum = f(n, a);
	printf("%lld\n", sum);

	return 0;
}
