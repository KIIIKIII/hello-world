# include <cstdio>
# include <string>
# include <cstring>
# include <iostream>
using namespace std;

int sum[5050];

struct point {
	int x, y;
};
struct Line {
	point a, b;
}line[5500];
int foud(point x, point p1, point p2) {
	return (x.x - p2.x)*(p1.y - p2.y) - (p1.x - p2.x)*(x.y - p2.y);
}

int main() {
	int n, m, x1, y1, x2, y2;
	while (~scanf("%d", &n) && n) {
		scanf("%d%d%d%d%d", &m, &x1, &y1, &x2, &y2);
		int i;
		for (i = 0; i<n; i++) {
			scanf("%d%d", &line[i].a.x, &line[i].b.x);
			line[i].a.y = y1;
			line[i].b.y = y2;
		}
		point a;
		memset(sum, 0, sizeof(sum));
		for (i = 0; i<m; i++) {
			scanf("%d%d", &a.x, &a.y);
			int l = 0, r = n - 1, mid;
			while (l<r) {
				mid = (l + r) >> 1;
				if (foud(a, line[mid].a, line[mid].b)>0)   
					l = mid + 1;
				else 
					r = mid;
			}
			if (foud(a, line[l].a, line[l].b)<0)  
				sum[l]++;
			else 
				sum[l + 1]++;
		}
		for (i = 0; i <= n; i++) 
			printf("%d: %d\n", i, sum[i]);
		printf("\n");
	}
	return 0;
}
