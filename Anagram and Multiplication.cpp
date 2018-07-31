#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 10 + 5;
int n, m;
int num[N], arr[N], vis[N];

bool judge(int x) {
	for (int i = 1; i <= m; i++) arr[i] = i;
	do {
		int flag2 = 1;
		for (int i = 2; i <= m; i++) {//从2一直乘到m
			memset(vis, 0, sizeof(vis));
			vis[i] = 1;
			int temp = x * i / n;
			for (int j = 2; j <= m; j++) {
				int temp2 = (num[arr[j]] * i + temp) % n;//判断序列是否可行
				temp = (num[arr[j]] * i + temp) / n;
				int flag = 0;
				for (int k = 1; k <= m; k++) {//找是否存在
					if (temp2 == num[k] && !vis[k]) {
						flag = 1;
						vis[k] = 1;
					}
				}
				if (!flag) {
					flag2 = 0;
					break;
				}
			}
			if (!flag2) break;
		}
		if (flag2) return true;
	} while (next_permutation(arr + 2, arr + m + 1));
	return false;
}

int main() {
	while (scanf("%d%d", &m, &n) != EOF && n && m) {
		int flag = 0;
		for (int i = 1; i<n; i++) {
			for (int j = 1; j <= m; j++) {
				num[j] = (i*j) % n;//个位数的2-m倍是必须要出现的
			}
			if (judge(i)) {
				flag = 1;
				for (int j = m; j >= 2; j--) printf("%d ", num[arr[j]]);
				printf("%d\n", i);
			}
		}
		if (!flag) printf("Not found.\n");
	}
	return 0;
}
