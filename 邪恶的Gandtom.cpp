#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int N = 25;
const int V = 30000;
long long int weight[N + 1];
long long int value[N + 1];

long long int f[N + 1][V + 1] = { { 0 } };

long long int Knapsack(int m, int n){
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= m; i++){
		for (int j = 0; j <= n; j++){
			f[i][j] = f[i - 1][j];
			if (j >= weight[i]) {
				f[i][j] = max(f[i - 1][j], f[i][j - weight[i]] + value[i] * weight[i]);
			}
		}
	}
	return f[m][n];
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> weight[i] >> value[i];
	}
	cout << Knapsack(m, n) << endl;
	return 0;
}
