#include<cstdio>
#include<cstring>
#include<queue>
const int INF = 999999;
const int MAXN = 520;
const int MAXM = 2520;
using namespace std;
struct edge
{
	int to;
	int val;
	int next;
}e[MAXM];

struct node
{
	int from;
	int val;
	node(int f, int v) { from = f; val = v; }
	bool operator < (const node& b)const
	{
		return val > b.val;
	}
};

int head[MAXN], len;
int dis_s[MAXN], dis_r[MAXN], path_s[MAXN], path_r[MAXN];

void add(int from, int to, int val)
{
	e[len].to = to;
	e[len].val = val;
	e[len].next = head[from];
	head[from] = len++;
}

int n, s, en;
void dijkstra(int start, int dis[], int path[])
{
	bool vis[MAXN] = { 0 };
	dis[start] = 0;

	priority_queue<node> q;
	q.push(node(start, 0));
	int num = 0;
	while (!q.empty())
	{
		node temp = q.top();
		q.pop();

		if (vis[temp.from])
			continue;

		vis[temp.from] = true;

		if (num == n)
			break;
		for (int i = head[temp.from]; i != -1; i = e[i].next)
		{
			if (!vis[e[i].to] &&
				dis[temp.from] + e[i].val < dis[e[i].to])
			{
				dis[e[i].to] = dis[temp.from] + e[i].val;
				path[e[i].to] = temp.from;
				q.push(node(e[i].to, dis[e[i].to]));
			}
		}
	}
}

void print(int cur)
{
	if (path_s[cur] != -1)
		print(path_s[cur]);

	if (cur != en)
		printf("%d ", cur);
	else
		printf("%d\n", cur);
}
int main()
{
	bool not_first = false;
	while (~scanf("%d%d%d", &n, &s, &en))
	{
		if (not_first)
			printf("\n");
		not_first = true;


		len = 0;
		for (int i = 1; i <= n; i++)
		{
			dis_s[i] = dis_r[i] = INF;
			head[i] = path_r[i] = path_s[i] = -1;
		}

		int m;
		scanf("%d", &m);
		for (int i = 0; i<m; i++)
		{
			int from, to, val;
			scanf("%d%d%d", &from, &to, &val);
			add(from, to, val);
			add(to, from, val);
		}
		dijkstra(s, dis_s, path_s);
		dijkstra(en, dis_r, path_r);

		int k;
		scanf("%d", &k);
		int ans_from = -1, ans_to, ans_val, ans = dis_s[en];

		for (int i = 0; i<k; i++)
		{
			int from, to, val, temp;
			scanf("%d%d%d", &from, &to, &val);
			temp = dis_s[from] + dis_r[to] + val;
			if (temp < ans)
			{
				ans = temp;
				ans_from = from;
				ans_to = to;
				ans_val = val;
			}
			temp = dis_s[to] + dis_r[from] + val;
			if (temp < ans)
			{
				ans = temp;
				ans_from = to;
				ans_to = from;
				ans_val = val;
			}
		}
		if (ans_from == -1)
			print(en);
		else
		{
			print(ans_from);
			int cur = ans_to;
			while (cur != en)
			{
				printf("%d ", cur);
				cur = path_r[cur];
			}
			printf("%d\n", en);
		}
		if (ans_from == -1)
			printf("Ticket Not Used\n");
		else
			printf("%d\n", ans_from);
		printf("%d\n", ans);


	}

	return 0;
}
