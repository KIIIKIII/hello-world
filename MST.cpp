#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXSIZE = 1000000;
int uset[MAXSIZE];
int ran[MAXSIZE];

void makeSet(int size) {
	for (int i = 0; i < size; i++)  uset[i] = i;
	for (int i = 0; i < size; i++)  ran[i] = 0;
}
int find(int x) {
	if (x != uset[x]) uset[x] = find(uset[x]);
	return uset[x];
}
void unionSet(int x, int y) {
	if ((x = find(x)) == (y = find(y))) return;
	if (ran[x] > ran[y]) uset[y] = x;
	else {
		uset[x] = y;
		if (ran[x] == ran[y]) ran[y]++;
	}
}

int u[1000000], v[1000000], c[1000000];
int main() {
	int n, m;
	cin >> n >> m;
	makeSet(n);
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> c[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m - i; j++) {
			if (c[i] > c[i + j]) {
				swap(c[i], c[i + j]);
				swap(u[i], u[i + j]);
				swap(v[i], v[i + j]);
			}
		}
	}
	long long ans = 0;
	int count = 0;
	for (int i = 0; count < n - 1; i++) {
		if (find(u[i]) != find(v[i])) {
			unionSet(u[i], v[i]);
			count++;
			ans += c[i];
		}
	}
	cout << ans << endl;

	return 0;
}
