#include <stdio.h>
#include <string.h>
#include <iostream>
typedef long long ll;
using namespace std;
const int Max = 100000;

class nodenode {
public:
	ll sum, val;
} node[Max << 2];

void Build(int l, int r, int tr) {
	node[tr].val = 0;
	if (l == r) {
		scanf("%I64d", &node[tr].sum);
		return;
	}
	int m = (l + r) >> 1;
	Build(l, m, tr << 1);
	Build(m + 1, r, tr << 1 | 1);
	node[tr].sum = node[tr << 1].sum + node[tr << 1 | 1].sum;
}
ll query(int L, int R, int l, int r, int tr) {
	if (L <= l && r <= R) {
		return node[tr].sum;
	}
	int m = (l + r) >> 1;
	if (node[tr].val) {
		node[tr << 1].val += node[tr].val;
		node[tr << 1 | 1].val += node[tr].val;
		node[tr << 1].sum += (ll)((r - l + 1) - ((r - l + 1) >> 1))*node[tr].val;
		node[tr << 1 | 1].sum += (ll)((r - l + 1) >> 1)*node[tr].val;
		node[tr].val = 0;
	}
	ll ans = 0;
	if (L <= m)ans += query(L, R, l, m, tr << 1);
	if (m<R)ans += query(L, R, m + 1, r, tr << 1 | 1);
	node[tr].sum = node[tr << 1].sum + node[tr << 1 | 1].sum;
	return ans;
}
void Update(int L, int R, int add, int l, int r, int tr) {
	if (L <= l && r <= R) {
		node[tr].sum += (ll)add*(r - l + 1);
		node[tr].val += add;
		return;
	}
	if (node[tr].val) {
		node[tr << 1].val += node[tr].val;
		node[tr << 1 | 1].val += node[tr].val;
		node[tr << 1].sum += (ll)((r - l + 1) - ((r - l + 1) >> 1))*node[tr].val;
		node[tr << 1 | 1].sum += (ll)((r - l + 1) >> 1)*node[tr].val;
		node[tr].val = 0;
	}
	int m = (l + r) >> 1;
	if (L <= m)Update(L, R, add, l, m, tr << 1);
	if (m<R)Update(L, R, add, m + 1, r, tr << 1 | 1);
	node[tr].sum = node[tr << 1].sum + node[tr << 1 | 1].sum;
}
int main() {
	int n, q, a, b;
	ll c;
	while (~scanf("%d%d", &n, &q)) {
		Build(1, n, 1);
		char s[3];
		while (q--) {
			scanf("%s", s);
			if (s[0] == 'Q') {
				cin >> a >> b;
				cout << query(a, b, 1, n, 1) << endl;
			}
			else if (s[0] == 'C') {
				cin >> a >> b >> c;
				Update(a, b, c, 1, n, 1);
			}
		}
	}
	return 0;
}
