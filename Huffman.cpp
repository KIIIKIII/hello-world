#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio> 
using namespace std;

int main() {
	int num, sum = 0, n;
	priority_queue<int, vector<int>, greater<int> > q;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &n);
		q.push(n);
	}
	while (q.size() != 1) {
		int temp = q.top();
		q.pop();
		temp += q.top();
		q.pop();
		q.push(temp);
		sum += temp;
	}
	printf("%d\n", sum);
	return 0;
}
