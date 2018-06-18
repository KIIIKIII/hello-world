#include <cstdio>
#include <cstring>
#include <cctype>

const int N = 100 + 5;
int main() {
	char s[N] = { 0 }, a[N][N] = { 0 }, b[N][N] = { 0 };
	scanf("%s", s);
	int flag, n, ans[N] = { 0 }, count = 0;
	scanf("%d%d", &flag, &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
		strcpy(a[i], b[i]);
		if (flag) {
			if (strstr(a[i], s) != NULL) ans[count++] = i;
		}
		else if (!flag) {
			for (unsigned j = 0; j < strlen(s); j++)
				s[j] = tolower(s[j]);
			for (unsigned j = 0; j < strlen(a[i]); j++)
				a[i][j] = tolower(a[i][j]);
			if (strstr(a[i], s) != NULL) ans[count++] = i;
		}
	}
	for (int i = 0; i < count; i++) {
		printf("%s\n", b[ans[i]]);
	}


	return 0;
}
