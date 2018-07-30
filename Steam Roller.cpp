#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
const int MAX = 100 + 5;
const int INF = 2000000000;
using namespace std;
const int UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3;

const int inv[] = { 2, 3, 0, 1 };
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int maxr = 100;
const int maxc = 100;

int grid[maxr][maxc][4];
int n, id[maxr][maxc][4][2];

int ID(int r, int c, int dir, int doubled) {
	int &x = id[r][c][dir][doubled];
	if (!x)x = ++n;
	return x;
}

int R, C;
bool cango(int r, int c, int dir) {
	if (r < 0 || r >= R || c < 0 || c >= C) return false;
	return grid[r][c][dir] > 0;
}

struct Edge {
	int from, to;
	double dist;
};

struct HeapNode {
	int d, u;
	bool operator < (const HeapNode&rhs) const {
		return d > rhs.d;
	}
};

struct Dijkstra {
	int n, m;
	vector<Edge>edges;
	vector<int>G[MAX];
	bool done[MAX];
	int d[MAX];
	int p[MAX];

	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, double dist) {
		edges.push_back({ from, to, dist });
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(int s) {
		priority_queue<HeapNode>Q;
		memset(done, 0, sizeof(done));
		for (int i = 0; i < n; i++) {
			d[s] = 0;
			d[i] = INF;
		}
		Q.push({ 0, s });
		while (!Q.empty()) {
			HeapNode x = Q.top();
			Q.pop();
			int u = x.u;
			if (done[u]) continue;
			done[u] = true;
			for (int i = 0; i < G[u].size(); i++) {
				Edge &e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist) {
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push({ d[e.to], e.to });
				}
			}
		}
	}
};

Dijkstra solver;

int readint() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int r1, c1, r2, c2, kase = 0;
	while (scanf("%d%d%d%d%d%d", &R, &C, &r1, &c1, &r2, &c2) == 6 && R) {
		r1--; c1--; r2--; c2--;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C - 1; c++)
				grid[r][c][RIGHT] = grid[r][c + 1][LEFT] = readint();
			if (r != R - 1) for (int c = 0; c < C; c++)
				grid[r][c][DOWN] = grid[r + 1][c][UP] = readint();
		}
		solver.init(R * C * 8 + 1);

		n = 0;
		memset(id, 0, sizeof(id));

		for (int dir = 0; dir < 4; dir++) if (cango(r1, c1, dir))
			solver.AddEdge(0, ID(r1 + dr[dir], c1 + dc[dir], dir, 1), grid[r1][c1][dir] * 2);
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				for (int dir = 0; dir < 4; dir++) if (cango(r, c, inv[dir]))
					for (int newdir = 0; newdir < 4; newdir++) if (cango(r, c, newdir))
						for (int doubled = 0; doubled < 2; doubled++) {
							int newr = r + dr[newdir];
							int newc = c + dc[newdir];
							int v = grid[r][c][newdir], newdoubled = 0;
							if (dir != newdir) {
								if (!doubled) v += grid[r][c][inv[dir]];
								newdoubled = 1; v += grid[r][c][newdir];
							}
							solver.AddEdge(ID(r, c, dir, doubled), ID(newr, newc, newdir, newdoubled), v);
						}
		solver.dijkstra(0);

		int ans = INF;
		for (int dir = 0; dir < 4; dir++)
			if (cango(r2, c2, inv[dir]))
				for (int doubled = 0; doubled < 2; doubled++) {
					int v = solver.d[ID(r2, c2, dir, doubled)];
					if (!doubled) v += grid[r2][c2][inv[dir]];
					ans = min(ans, v);
				}
		printf("Case %d: ", ++kase);
		if (ans == INF) printf("Impossible\n");
		else printf("%d\n", ans);

	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//int main() {
//	int r1, c1, r2, c2, kase = 0;
//	while (scanf("%d%d%d%d%d%d", &R, &C, &r1, &c1, &r2, &c2) == 6 && R) {
//		r1--; c1--; r2--; c2--;
//		for (int r = 0; r < R; r++) {
//			for (int c = 0; c < C - 1; c++)
//				grid[r][c][RIGHT] = grid[r][c + 1][LEFT] = readint();
//			if (r != R - 1) for (int c = 0; c < C; c++)
//				grid[r][c][DOWN] = grid[r + 1][c][UP] = readint();
//		}
//		solver.init(R * C * 5 + 1);
//
//		n = 0;
//		memset(id, 0, sizeof(id));
//
//		for (int dir = 0; dir < 4; dir++) if (cango(r1, c1, dir)) {
//			solver.AddEdge(0, ID(r1 + dr[dir], c1 + dc[dir], dir), grid[r1][c1][dir] * 2);
//			solver.AddEdge(0, ID(r1 + dr[dir], c1 + dc[dir], 4), grid[r1][c1][dir] * 2);
//		}
//		for (int r = 0; r < R; r++)
//			for (int c = 0; c < C; c++) {
//				for (int dir = 0; dir < 4; dir++) if (cango(r, c, inv[dir])) {
//					solver.AddEdge(ID(r, c, dir), ID(r, c, 4), grid[r][c][inv[dir]]);
//					if (cango(r, c, dir))
//						solver.AddEdge(ID(r, c, dir), ID(r + dr[dir], c + dc[dir], dir), grid[r][c][dir]);
//				}
//				for (int dir = 0; dir < 4; dir++) if (cango(r, c, dir)) {
//					solver.AddEdge(ID(r, c, 4), ID(r + dr[dir], c + dc[dir], dir), grid[r][c][dir] * 2);
//					solver.AddEdge(ID(r, c, 4), ID(r + dr[dir], c + dc[dir], 4), grid[r][c][dir] * 2);
//				}
//			}
//
//		solver.dijkstra(0);
//
//		int ans = solver.d[ID(r2, c2, 4)];
//		printf("Case %d: ", ++kase);
//		if (ans == INF) printf("Impossible\n");
//		else printf("%d\n", ans);
//	}
//
//	return 0;
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
 
const int INF = 0x0fffffff;
 
const int MAXN = 111;
 
struct Edge
{
    int t_x,t_y,val,next;
    int dir;
} edge[MAXN*MAXN*2*2];
 
int tot,head[MAXN][MAXN];
 
void init()
{
    memset(head,-1,sizeof(head));
    tot = 0;
}
 
void add_edge(int s_x,int s_y,int t_x,int t_y,int val,int dir)
{
    edge[tot].dir = dir;
    edge[tot].t_x = t_x;
    edge[tot].t_y = t_y;
    edge[tot].val = val;
    edge[tot].next = head[s_x][s_y];
    head[s_x][s_y] = tot++;
}
 
struct Node
{
    int x,y;
    int val;
    int last_dir,last_edge_val,doubled;
    Node(int a,int b,int c,int d,int e,int f)
    {
        x = a;y = b;val = c;last_dir = d;last_edge_val = e;doubled = f;
    }
    bool operator < (const Node& tmp) const
    {
        return val > tmp.val;
    }
};
 
int done[MAXN][MAXN][11][11];
int d[MAXN][MAXN][11][11];
 
int ans;
 
void dij(int r,int c,int r1,int c1,int r2,int c2)
{
    priority_queue<Node> q;
    memset(done,0,sizeof(done));
    for(int i = 0;i < r;i++)
        for(int j = 0;j < c;j++)
            for(int dir = 0;dir < 4;dir++)
                for(int k = 0;k < 2;k++)
                    d[i][j][dir][k] = INF;
    d[r1][c1][4][1] = 0;
    q.push(Node(r1,c1,0,4,0,1));
    while(!q.empty())
    {
        Node cur = q.top();
        q.pop();
        if(cur.x == r2 && cur.y == c2)
        {
            int tmp;
            if(cur.doubled)
                tmp = cur.val;
            else tmp = cur.val+cur.last_edge_val;
            ans = min(ans,tmp);
        }
        if(done[cur.x][cur.y][cur.last_dir][cur.doubled]) continue;
        done[cur.x][cur.y][cur.last_dir][cur.doubled] = 1;
        for(int e = head[cur.x][cur.y];e != -1;e = edge[e].next)
        {
 
            int xx = edge[e].t_x;
            int yy = edge[e].t_y;
 
            int val = edge[e].val;
            int dir = edge[e].dir;
            int old_dif = 0;
            if(!cur.doubled)
            {
                if(dir != cur.last_dir)
                    old_dif = 1;
            }
            int new_dif = 1;
            int next_doubled = 0;
            if(cur.last_dir != dir)
            {
                new_dif = 2;
                next_doubled = 1;
            }
 
            int tmp = d[cur.x][cur.y][cur.last_dir][cur.doubled]+new_dif*val+old_dif*cur.last_edge_val;
 
            if(d[xx][yy][dir][next_doubled] > tmp)
            {
                //printf("%d,%d,%d,%d,tmp = %d\n",cur.x,cur.y,xx,yy,tmp);
                d[xx][yy][dir][next_doubled] = tmp;
                q.push(Node(xx,yy,tmp,dir,val,next_doubled));
            }
        }
    }
}
 
int main()
{
    int cas = 0;
    int r,c,r1,c1,r2,c2;
    while(~scanf("%d%d%d%d%d%d",&r,&c,&r1,&c1,&r2,&c2))
    {
        if(r+c == 0) break;
        r1--;c1--;r2--;c2--;
        init();
        for(int i = 0;i < 2*r-1;i++)
        {
            int val;
            if(i&1)
            {
                for(int j = 0;j < c;j++)
                {
                    scanf("%d",&val);
                    if(val == 0) continue;
                    add_edge(i/2+1,j,i/2,j,val,3);
                    add_edge(i/2,j,i/2+1,j,val,1);
                }
            }
            else
            {
                for(int j = 0;j < c-1;j++)
                {
                    scanf("%d",&val);
                    if(val == 0) continue;
                    add_edge(i/2,j,i/2,j+1,val,0);
                    add_edge(i/2,j+1,i/2,j,val,2);
                }
            }
        }
        ans = INF;
        dij(r,c,r1,c1,r2,c2);
        printf("Case %d: ",++cas);
 
        if(ans >= INF) puts("Impossible");
        else printf("%d\n",ans);
    }
    return 0;
}
