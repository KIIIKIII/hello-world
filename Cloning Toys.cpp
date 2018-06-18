#include <cstdio>

int main() {
	long long int copy = 0, orig = 0;
	scanf("%lld%lld", &copy, &orig);
	if (orig - copy > 1 || orig <= 0 || copy < 0 || (orig == 1 && copy != 0)) {
		printf("No\n");
		return 0;
	}
	orig -= 1;
	copy -= orig;
	if (copy % 2 == 0 && copy >= 0) printf("Yes\n");
	else printf("No\n");

	return 0;
}
