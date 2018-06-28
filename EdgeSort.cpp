#include<stdio.h>
#include<iostream>
#include<algorithm>  
using namespace std;
struct Road
{
	int u;
	int v;
	int l;
	int t;
	int w;
	int c;
	int f;
};
Road road[10000];
bool cmp(const Road &r1, const Road &r2)
{
	if (r1.l != r2.l)
		return r1.l<r2.l;
	else if (r1.t != r2.t)
		return r1.t<r2.t;
	else if (r1.w != r2.w)
		return r1.w<r2.w;
	else if (r1.c != r2.c)
		return r1.c<r2.c;
	else
		return r1.f<r2.f;
}
int main()
{
	int num, n;
	scanf("%d", &num);
	for (int i = 0; i<num; i++)
		scanf("%d %d %d %d %d %d %d", &road[i].v, &road[i].u, &road[i].l, &road[i].t, &road[i].w, &road[i].c, &road[i].f);
	sort(road, road + num, cmp);
	scanf("%d", &num);
	for (int i = 0; i<num; i++)
	{
		scanf("%d", &n);
		n--;
		printf("%d %d %d %d %d %d %d\n", road[n].v, road[n].u, road[n].l, road[n].t, road[n].w, road[n].c, road[n].f);
	}
	return 0;
}
