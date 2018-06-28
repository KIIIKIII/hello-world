#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int a[1000001] = { 0 };
int main() {
	int n, count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'I') {
			int x;
			cin >> x;
			a[count++] = x;
		}
		if (c == 'Q') {
			int Min = a[0];
			for (int j = 0; j < count; j++) {
				if (a[j] < Min) {
					Min = a[j];
				}
			}
			cout << Min << endl;
		}
		if (c == 'D') {
			int Min = a[0], Minj = 0;
			for (int j = 0; j < count; j++) {
				if (a[j] < Min) {
					Min = a[j];
					Minj = j;
				}
			}
			for (int j = Minj; j < count; j++) {
				swap(a[j], a[j + 1]);
			}
			count--;
		}
	}

	return 0;
}
