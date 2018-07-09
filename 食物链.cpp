#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 50000 + 5;
struct node {
	int pre;
	int relation;
};
node p[N];
int find(int x) {//查找根结点 
	int temp;
	if (x == p[x].pre)
		return x;
	temp = p[x].pre; //路径压缩
	p[x].pre = find(temp);
	p[x].relation = (p[x].relation + p[temp].relation) % 3; //关系域更新
	return p[x].pre; //根结点
}

int main() {
	int n, k;
	int ope, a, b;
	int root1, root2;
	int sum = 0; 
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		p[i].pre = i;
		p[i].relation = 0;
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &ope, &a, &b);
		if (a > n || b > n) {
			sum++;
			continue;
		}
		if (ope == 2 && a == b) {
			sum++;
			continue;
		}
		root1 = find(a);
		root2 = find(b);
		if (root1 != root2) {
			p[root2].pre = root1;
			p[root2].relation = (3 + (ope - 1) + p[a].relation - p[b].relation) % 3;
		}
		else {
			if (ope == 1 && p[a].relation != p[b].relation) {
				sum++;
				continue;
			}
			if (ope == 2 && ((3 - p[a].relation + p[b].relation) % 3 != ope - 1)) {
				sum++;
				continue;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}
