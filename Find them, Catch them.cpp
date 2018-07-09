#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int MAXN = 100000 + 5;
int fa[MAXN];
int gang[MAXN];
int n, k;

void init() {//初始化建立集合fa
	for (int i = 0; i <= n; i++) {
		fa[i] = i;
		gang[i] = 0;
	}
}
int find(int t) {
	if (fa[t] == t)
		return fa[t];
	int temp = fa[t];
	fa[t] = find(temp);
	gang[t] = (gang[t] + gang[temp]) % 2;
	return fa[t];
}
void union_set(int a, int b) {//将a和b合并进同一集合
	int roota = find(a);
	int rootb = find(b);
	if (roota != rootb) {
		fa[rootb] = roota;
		gang[rootb] = (gang[a] + 1 - gang[b]) % 2;
	}
}
int solve(int a, int b) {
	int roota = find(a);
	int rootb = find(b);
	if (roota != rootb) {
		return 1;
	}
	else {
		if (gang[a] != gang[b])
			return 2;
		else
			return 3;
	}
}
int main() {
	int casen;
	scanf("%d", &casen);
	while (casen--) {
		scanf("%d%d", &n, &k);
		init();
		char op;
		int a, b;
		for (int i = 0; i < k; i++) {
			cin >> op;
			scanf("%d%d", &a, &b);
			if (op == 'D') {
				union_set(a, b);
			}
			else {
				int ret = solve(a, b);
				if (ret == 1)
					printf("Not sure yet.\n");
				else if (ret == 2)
					printf("In different gangs.\n");
				else
					printf("In the same gang.\n");
			}
		}
	}
}
