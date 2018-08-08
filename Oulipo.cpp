/**
*
* @authors Your Name (you@example.org)
* @date    2018-08-04 09:40:00
* @version $Id$
*/
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
const int N = 10000 + 5;
const int M = 1000000 + 5;
const int INF = 0x3f3f3f3f3f;

int nex[M];
void getnext(char *p) {
	int i = -1, j = 0, p1 = strlen(p);
	nex[0] = -1;
	while (j < p1) {
		if (i == -1 || p[i] == p[j]) {
			j++;
			i++;
			if (p[i] != p[j])
				nex[j] = i;
			else
				nex[j] = nex[i];
		}
		else
			i = nex[i];
	}
}

int kmp(char *p, char *s) {
	int count = 0, p1 = strlen(s), p2 = strlen(p);
	getnext(p);
	int i = 0, j = 0;
	while (i < p1) {
		if (j == -1 || s[i] == p[j]) {
			i++;
			j++;
		}
		else
			j = nex[j];
		if (j == p2) {
			count++;
			j = nex[j];
		}
	}
	return count;
}

int main() {
	char p[N], s[M];
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", p);
		scanf("%s", s);
		printf("%d\n", kmp(p, s));
	}

	return 0;
}
