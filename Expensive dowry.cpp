#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX = 100 + 5;
const int INF = 0x3f3f3f3f3f;

int M, N;//M为等级差，N为物品数目   
int price[MAX][MAX];   //物品i在有第t号替代品情况下的优惠价pricr[t][i],当t=0时说明i无替代品，此时为原价
int lv[MAX];   //第i号物品主人的等级lv[i]
int x[MAX];//第i号物品的替代品总数x[i]   
int dist[MAX];//最初的源点0到任意点i的最初距离（权值），相当于每个物品的原价   
bool vist[MAX];   //记录点i是否已被访问

bool check(int node, int j) {
	return !vist[j] && price[node][j] > 0 && dist[j] > dist[node] + price[node][j];
}

int dijkstra() {
	for (int i = 1; i <= N; i++)
		dist[i] = price[0][i];  //假设最初的源点就是0点，初始化最初源点到各点的权值dist[i]
	for (int i = 1; i <= N; i++) {  //由于1点是目标点，因此最坏的打算是进行n次寻找源点到其他点的最短路，并合并这两点（不再访问相当于合并了）
		int node = 0;//记录与当前源点距离最短的点   
		int sd = INF;//最短距离
		for (int j = 1; j <= N; j++) {
			if (!vist[j] && sd > dist[j]) {  //在未访问的点中，寻找最短的一条
				sd = dist[j];
				node = j;   //记录该点
			}
		}
		if (!node) break;  //若node没有变化，说明所有点都被访问，最短路寻找完毕
		vist[node] = true;   //记录node点已被访问
		for (int j = 1; j <= N; j++)
			if (check(node, j))   //把未访问但与node（新源点）连通的点进行松弛
				dist[j] = dist[node] + price[node][j];
	}
	return dist[1];   //返回当前次交易后目标点1在等级lv[i]约束下的最短距离
}

int main() {
	memset(dist, INF, sizeof(dist));
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d%d", &price[0][i], &lv[i], &x[i]);//price[0][i]物品i无替代品时的原价
		for (int j = 1; j <= x[i]; j++) {
			int t, u;   //t替代品编号，u优惠价(临时变量)
			scanf("%d%d", &t, &u);
			price[t][i] = u;   //物品i在有第t号替代品情况下的优惠价，即点t到点i的权值
		}
	}
	int minprice = INF;    //最低价格(初始化为无限大)
	for (int i = 1; i <= N; i++) { /*在等级限制下，寻找允许被当前点访问的点*/
		for (int j = 1; j <= N; j++)  //遍历其他各点
			if (lv[j] > lv[i] || lv[i] - lv[j] > M)   //当其它物品j的等级比当前物品高(保证单向性)，或者两者等级之差超出限制M时
				vist[j] = true;    //物品j则强制定义为“已访问”状态，不参与后续操作
			else
				vist[j] = false;   //否则物品j定义为“未访问”状态，参与后续操作
		minprice = min(minprice, dijkstra());
	}
	printf("%d\n", minprice);
	return 0;
}
