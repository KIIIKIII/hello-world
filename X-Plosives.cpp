#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100000 + 5;
int a[MAX] = { 0 };
int find(int x) {//并查集的查找操作，带路径压缩
	return a[x] != x ? a[x] = find(a[x]) : x;
}
int main() {
	int x, y;
	while (~scanf("%d", &x)) {
		for (int i = 0; i < MAX; i++)
			a[i] = i;
		int ans = 0;
		while(x != -1) {
			scanf("%d", &y);
			x = find(x);
			y = find(y);//x和y分别是两个集合的代表元素
			if (x == y) ans++;//x与y为同一个集合，拒绝
			else a[x] = y;//否则合并
			scanf("%d", &x);
		}
		printf("%d\n", ans);
	}

	return 0;
}
