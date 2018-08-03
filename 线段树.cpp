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
const int N = 50 + 5, M = 200 + 5, INF = 0x3f3f3f3f3f;


int minv[N]; //minv[o]表示结点o所对应的区间中所有元素的最小值
int maxv[N];
int sumv[N];
int addv[N];
int setv[N];

int ql, qr; //查询[ql, qr]中的最小值
int query(int o, int L, int R) {
	int M = L + (R - L) / 2, ans = INF;
	if (ql <= L && R <= qr)
		return minv[o];//当前结点完全包含在查询区域内
	if (ql <= M)
		ans = min(ans, query(o * 2, L, M));//往左走
	if (M < qr)
		ans = min(ans, query(o * 2 + 1, M + 1, R));//往右走
	return ans;
}

int p, v;//修改：A[p] = v;
void update(int o, int L, int R) {
	int M = L + (R - L) / 2;
	if (L == R) 
		minv[o] = v;//叶结点，直接更新minv
	else {//L < R
		//先递归更新左子树或右子树
		if (p <= M)
			update(o * 2, L, M);
		else
			update(o * 2 + 1, M + 1, R);
		//然后计算本结点的minv
		minv[o] = min(minv[o * 2], minv[o * 2 + 1]);
	}
}

//维护结点o，它对应区间[L, R]
void maintain(int o, int L, int R) {
	int lc = o * 2, rc = o * 2 + 1;
	sumv[o] = minv[o] = maxv[o] = 0;
	if (R > L) {//考虑左右子树
		sumv[o] = sumv[lc] + sumv[rc];
		minv[o] = min(minv[lc], minv[rc]);
		maxv[o] = max(maxv[lc], maxv[rc]);
	}
	minv[o] += addv[o];
	maxv[o] += addv[o];
	sumv[o] += addv[o] * (R - L + 1);
	//考虑add操作
}

int y1, y2;
void update2(int o, int L, int R) {
	int lc = o * 2, rc = o * 2 + 1;
	if (y1 <= L && y2 >= R) {//递归边界
		addv[o] += v;//累加边界的add值
	}
	else {
		int M = L + (R - L) / 2;
		if (y1 <= M)
			update2(lc, L, M);
		if (y2 > M)
			update2(rc, M + 1, R);
	}
	maintain(o, L, R);//递归结束前重新计算本结点的附加信息
}

int _min, _max, _sum;//全局变量，目前位置的最小值、最大值和累加和
void query(int o, int L, int R, int add) {
	if (y1 <= L && y2 >= R) {//递归边界：用边界区间的附加信息更新答案
		_sum += sumv[o] + add * (R - L + 1);
		_min = min(_min, minv[o] + add);
		_max = max(_max, maxv[o] + add);
	}
	else {//递归统计，累加参数add
		int M = L + (R - L) / 2;
		if (y1 <= M)
			query(o * 2, L, M, add + addv[o]);
		if (y2 > M)
			query(o * 2 + 1, M + 1, R, add + addv[o]);
	}
}

//标记传递
void pushdown(int o) {
	int lc = o * 2, rc = o * 2 + 1;
	if (setv[o] >= 0) {//本结点有标记才传递。此处-1代表没有标记
		setv[lc] = setv[rc] = setv[o];
		setv[o] = -1;//清除本结点标记
	}
}

void update3(int o, int L, int R) {
	int lc = o * 2, rc = o * 2 + 1;
	if (y1 <= L && y2 >= R) {//标记修改
		setv[o] = v;
	}
	else {
		pushdown(o);
		int M = L + (R - L) / 2;
		if (y1 <= M)
			update3(lc, L, M);
		else
			maintain(lc, L, M);
		if (y2 > M)
			update3(rc, M + 1, R);
		else 
			maintain(rc, M + 1, R);
	}
	maintain(o, L, R);
}

void query2(int o, int L, int R) {
	if (setv[o] >= 0) {//递归边界1：有set标记
		_sum += setv[o] * (min(R, y2) - max(L, y1) + 1);
		_min = min(_min, setv[o]);
		_max = max(_max, setv[o]);
	}
	else if (y1 <= L && y2 >= R) {//递归边界2：边界区间
		_sum += sumv[o];//此边界区间没有被任何set操作影响
		_min = min(_min, minv[o]);
		_max = max(_max, maxv[o]);
	}
	else {//递归统计
		int M = L + (R - L) / 2;
		if (y1 <= M)
			query2(o * 2, L, M);
		if (y2 > M)
			query2(o * 2 + 1, M + 1, R);
	}
}
