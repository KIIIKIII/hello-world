#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;
int x[maxn], //x[i]为第i个垃圾的x坐标
  y[maxn]; //y[i]为第i个垃圾的y坐标
int dist[maxn], //dist[i]表示从第1个垃圾开始，依次经过垃圾2、3……最终到达垃圾i的总距离
  weight[maxn], //weight[i]为从第1个垃圾到第i个垃圾的总重量
  origin[maxn]; //origin[i]为垃圾i到原点的距离
int q[maxn],  //滑动窗口单调队列
  d[maxn]; //d[i]为从原点出发、将前i个垃圾清理完并放进垃圾桶的最小距离

int f(int i) {//简化方程
	return d[i] - dist[i + 1] + origin[i + 1];
}
int main() {
	int T, c, n, w, 
    front, rear;//滑动窗口前后界
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &c, &n);
		dist[0] = weight[0] = x[0] = y[0] = 0;//原点初始化
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &x[i], &y[i], &w);
			origin[i] = abs(x[i]) + abs(y[i]);//i到原点的曼哈顿距离
			dist[i] = dist[i - 1] + abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);//Σorigin[](1~i)
			weight[i] = weight[i - 1] + w;////Σw(1~i)
		}
		front = rear = 1;//滑动窗口初始化
		for (int i = 1; i <= n; i++) {//每个元素依次判断
			while (front <= rear && weight[i] - weight[q[front]] > c)//加入元素i的话，总重过大，窗口左侧右移至合适总重
				front++;
			d[i] = f(q[front]) + dist[i] + origin[i];//窗口之前的元素已经取完。则此时最优解。
			while (front <= rear && f(i) <= f(q[rear]))//维护滑动窗口中的最小值
				rear--;
			q[++rear] = i;//加入元素i
		}
		printf("%d\n", d[n]);
		if (T > 0) printf("\n");
	}

	return 0;
}
