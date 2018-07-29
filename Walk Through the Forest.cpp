#include<iostream>
#include<cstdio>
#include<string.h>
const int N = 1010;
const int INF = 2000000000;
using namespace std;

int map[N][N], lowcost[N], visited[N], d[N], p[N];


void dijkstra(int s, int n){
	memset(visited, false, sizeof(visited));
	int i, j, k, min;
	for (i = 1; i <= n; i++){
		lowcost[i] = map[s][i];
	}
	d[s] = 0;
	visited[s] = true;
	for (i = 1; i<n; i++){
		min = INF;
		for (j = 1; j <= n; j++){
			if (!visited[j] && min>lowcost[j]){
				min = lowcost[j];
				k = j;
			}
		}
		d[k] = min;
		visited[k] = true;
		for (j = 1; j <= n; j++){
			if (!visited[j] && lowcost[j]>map[k][j] + d[k])
				lowcost[j] = map[k][j] + d[k];
		}
	}
}

int DFS(int s, int n){
	if (p[s]) return p[s];
	if (s == 2)  return 1;
	int i, sum = 0;
	for (i = 1; i <= n; i++){
		if (map[s][i]<INF&&d[s]>d[i]){
			if (p[i]) sum = sum + p[i];
			else sum = sum + DFS(i, n);
		}
	}
	sum = sum + p[s];
	p[s] = sum;
	return p[s];
}

int main(){
	int i, j, n, m, u, v, w;
	while (cin >> n && n){
		cin >> m;
		memset(p, 0, sizeof(p));
		for (i = 1; i <= n; i++){
			for (j = 1; j <= n; j++){
				map[i][j] = (i == j ? 0 : INF);
			}
		}
		for (i = 0; i<m; i++){
			scanf("%d%d%d", &u, &v, &w);
			map[u][v] = map[v][u] = w;
		}
		dijkstra(2, n);
		cout << DFS(1, n) << endl;
	}
	return 0;
}
