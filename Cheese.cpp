#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int x;
	int y;
}P;

char graph[1000][1000];
P aim[10];
P s, g;
int N, W, H;
int vis[1000][1000];
int dx[] = { 1, 0, -1 ,0 }, dy[] = { 0, 1, 0, -1 };

int bfs(P s, P g) {
	queue<P> que;
	P n;
	for (int i = 0; i<H; i++)
		for (int j = 0; j<W; j++)
			vis[i][j] = -1;

	que.push(s);
	vis[s.x][s.y] = 0;

	while (que.size()) {

		P p = que.front();
		que.pop();
		if (p.x == g.x&&p.y == g.y)
			break;

		for (int i = 0; i<4; i++) {
			n.x = p.x + dx[i];
			n.y = p.y + dy[i];
			if (0 <= n.x && n.x < H && 0 <= n.y && n.y < W && graph[n.x][n.y] != 'X' && vis[n.x][n.y] == -1) {
				que.push(n);
				vis[n.x][n.y] = vis[p.x][p.y] + 1;
			}
		}
	}
	return vis[g.x][g.y];
}
int main() {
	int i, j, t, step = 0;
	cin >> H >> W >> N;

	for (i = 0; i < H; i++)
		for (j = 0; j<W; j++) {
			cin >> graph[i][j];
			if (graph[i][j] <= '9'&&graph[i][j] >= '1') {
				t = graph[i][j] - '0';
				aim[t].x = i;
				aim[t].y = j;
			}
			else if (graph[i][j] == 'S') {
				s.x = i;
				s.y = j;
				graph[i][j] = '.';
			} 
		}

	for (i = 1; i <= N; i++) {
		g.x = aim[i].x;
		g.y = aim[i].y;
		step += bfs(s, g);
		s.x = g.x;
		s.y = g.y;
		graph[g.x][g.y] = '.';
	}

	cout << step << endl;
}
