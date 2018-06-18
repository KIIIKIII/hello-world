#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int N = 100 + 5;
char a[N][N] = { 0 };

inline int is_can(int x, int y, char c) {
	if (a[x][y] != '-' && a[x][y] != '+' && a[x][y] != '|' && a[x][y] != c) return 1;
	return 0;
}

int main() {
	int m, n, q;
	cin >> m >> n >> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = '.';
		}
	}

	for (int i = 0; i < q; i++) {
		int f;
		cin >> f;
		if (!f) {
			int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);
			if (x1 == x2) {
				for (int j = y1; j <= y2; j++) {
					if (a[j][x1] == '-' || a[j][x1] == '+') a[j][x1] = '+';
					else a[j][x1] = '|';
				}
			}
			if (y1 == y2) {
				for (int j = x1; j <= x2; j++) {
					if (a[y1][j] == '|' || a[y1][j] == '+') a[y1][j] = '+';
					else a[y1][j] = '-';
				}
			}
		}
		if (f) {
			int x = 0, y = 0;
			char c = 0;
			cin >> x >> y >> c;
			a[y][x] = c;
			int flag = 1;


			///////////////////////////////////////////////////////////////////////////////////////
			int col, row;
			for (col = x; col < m; col++) {
				if (a[y][col] == '-' || a[y][col] == '|' || a[y][col] == '+') break;
				a[y][col] = c;
			}
			for (col = x; col >= 0; col--) {
				if (a[y][col] == '-' || a[y][col] == '|' || a[y][col] == '+') break;
				a[y][col] = c;
			}
			for (row = y; row < n; row++) {
				if (a[row][x] == '-' || a[row][x] == '|' || a[row][x] == '+') break;
				a[row][x] = c;
			}
			for (row = y; row >= 0; row--) {
				if (a[row][x] == '-' || a[row][x] == '|' || a[row][x] == '+') break;
				a[row][x] = c;
			}
			//////////////////////////////////////////////////////////////////////////////////////////			



			while (flag) {
				flag = 0;
				for (int p = 0; p < n; p++) {
					for (int q = 0; q < m; q++) {
						if (is_can(p, q, c)) {
							if (p + 1 < n && a[p + 1][q] == c) { a[p][q] = c; flag = 1; continue; }
							if (p - 1 >= 0 && a[p - 1][q] == c) { a[p][q] = c; flag = 1; continue; }
							if (q + 1 < m && a[p][q + 1] == c) { a[p][q] = c; flag = 1; continue; }
							if (q - 1 >= 0 && a[p][q - 1] == c) { a[p][q] = c; flag = 1; continue; }
						}
					}
				}
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}

	return 0;
}
