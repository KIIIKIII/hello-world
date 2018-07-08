#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000 + 5;
const int INF = 0x3f3f3f3f;
char a[MAX] = { 0 };
int d[MAX] = { 0 };
bool Palindrome(int x, int y) {
	while (x <= y && a[x] == a[y])
		++x, --y;
	return x >= y;
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < MAX; i++) d[i] = INF;
		d[0] = 0; d[1] = 1;
		scanf("%s", a);
		for (int i = 1; i < strlen(a); i++) {
			for (int j = i; j >= 0; j--) {
				if (Palindrome(j, i)) d[i + 1] = min(d[i + 1], d[j] + 1);
			}
		}
		printf("%d\n", d[strlen(a)]);
	}

	return 0;
}
