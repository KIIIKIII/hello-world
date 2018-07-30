#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int LL;
const LL INF = 4557430888798830399LL;

int getID(char c) {
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 1;
	else return c - 'a' + 27;
}

struct Edge {
	int to, next;
}edge[6000];

int Adj[60], Size = 0;

void Init() {
	memset(Adj, -1, sizeof(Adj)); Size = 0;
}

void AddEdge(int u, int v) {
	edge[Size].to = v;
	edge[Size].next = Adj[u];
	Adj[u] = Size++;
}

int n, S, E;
LL dist[60], toll;
bool used[60];

LL get_toll(int E, LL toll) {
	if (E >= 27) {
		return toll + 1LL;
	}
	else {
		LL t = toll / 19LL;
		if (toll % 19LL) t++;
		return toll + t;
	}
}

void Dijkstra() {
	memset(dist, 63, sizeof(dist));
	memset(used, false, sizeof(used));
	dist[E] = toll;
	for (int j = 1; j <= 60; j++) {
		int mark = -1;
		LL mindist = INF;
		for (int i = 1; i <= 52; i++) {
			if (used[i]) continue;
			if (dist[i] < mindist) {
				mark = i; mindist = dist[i];
			}
		}
		if (mark == -1) break;
		used[mark] = true;
		LL temp = get_toll(mark, dist[mark]);
		for (int i = Adj[mark]; ~i; i = edge[i].next) {
			int v = edge[i].to;
			if (used[v]) continue;
			if (dist[v] > temp)
				dist[v] = temp;
		}
	}
}

vector<int> road;
LL GetDown(int E, LL toll) {
	if (E >= 27) {
		return 1;
	}
	else {
		LL t = toll / 20LL;
		if (toll % 20LL) t++;
		return t;
	}
}

void Dfs(int u, int fa) {
	road.push_back(u);
	int temp = 9999;
	for (int i = Adj[u]; ~i; i = edge[i].next) {
		int v = edge[i].to;
		if (v == fa) continue;
		if (dist[u] - GetDown(v, dist[u]) == dist[v])
			temp = min(temp, v);
	}
	if (temp != 9999)
		Dfs(temp, u);
}

int main() {
	int cas = 1;
	while (scanf("%d", &n) != EOF && ~n) {
		Init();
		char opp[2][30];
		for (int i = 0; i < n; i++) {
			scanf("%s%s", opp[0], opp[1]);
			int u = getID(opp[0][0]);
			int v = getID(opp[1][0]);
			AddEdge(u, v);
			AddEdge(v, u);
		}
		scanf("%lld%s%s", &toll, opp[0], opp[1]);
		S = getID(opp[0][0]); E = getID(opp[1][0]);
		Dijkstra();
		printf("Case %d:\n%lld\n", cas++, dist[S]);
		road.clear();
		Dfs(S, S);
		for (int i = 0, sz = road.size(); i < sz; i++) {
			if (i) printf("-");
			char xxx;
			if (road[i] <= 26)
				xxx = 'A' + road[i] - 1;
			else {
				road[i] -= 27;
				xxx = 'a' + road[i];
			}
			printf("%c", xxx);
		}
		putchar(10);
	}
	return 0;
}
