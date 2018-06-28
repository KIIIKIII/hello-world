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
int main() {
	int n, m;
	cin >> n >> m;
	makeSet(n);
	for (int i = 0; i < m; i++) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		switch (c) {
		case 'U':
			unionSet(x, y);
			break;
		case 'Q':
			if (find(x) == find(y))
				cout << 'Y' << endl;
			else
				cout << 'N' << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}
