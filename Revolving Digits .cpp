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
const int N = 2000000 + 5;
const int M = 1000 + 5;
const int INF = 0x3f3f3f3f3f;

char t[N], s[N];
int nex[N], next2[N], extend[N];
void kmp() {
	int lens = strlen(s);
	int lent = strlen(t);
	nex[0] = lent;
	int j = 0, p, l;
	while (j + 1 < lent && t[j] == t[j + 1])
		j++;
	nex[1] = j;
	int a = 1;
	for (int i = 2; i < lent; i++) {
		p = nex[a] + a - 1;
		l = nex[i - a];
		if (i + l < p + 1)
			nex[i] = l;
		else {
			j = max(0, p - i + 1);
			while (i + j < lent && t[i + j] == t[j])
				j++;
			nex[i] = j;
			a = i;
		}
	}
	j = 0;
	while (j < lens && s[j] == t[j])
		j++;
	extend[0] = j;
	a = 0;
	for (int i = 1; i < lens; i++) {
		p = extend[a] + a - 1;
		l = nex[i - a];
		if (l + i < p + 1)
			extend[i] = l;
		else {
			j = max(0, p - i + 1);
			while (i + j < lens && j < lent && s[i + j] == t[j])
				j++;
			extend[i] = j;
			a = i;
		}
	}
}

void getnext() {
	int len = strlen(t);
	next2[0] = -1;
	int j = 0, k = -1;
	while (j < len) {
		if (k == -1 || t[k] == t[j]) {
			k++;
			j++;
			next2[j] = k;
		}
		else
			k = next2[k];
	}
}

int main() {
	int T;
	scanf("%d", &T);
	int cas = 0;
	while (T--) {
		scanf("%s", t);
		strcpy(s, t);
		strcat(s, t);
		getnext();
		kmp();
		int lens = strlen(s);
		int lent = strlen(t);
		int ans1 = 0, ans2 = 0, ans3 = 0;
		for (int i = 0; i < lent; i++) {
			if (extend[i] >= lent)
				ans2++;
			else {
				if (s[i + extend[i]] < t[extend[i]])
					ans1++;
				else
					ans3++;
			}
		}
		int ret = 1;
		if (lent % (lent - next2[lent]) == 0)
			ret = lent / (lent - next2[lent]);
		printf("Case %d: %d %d %d\n", ++cas, ans1 / ret, ans2 / ret, ans3 / ret);

	}

	return 0;
}
