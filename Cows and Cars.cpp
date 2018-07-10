#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;

int main() {
	double cow, car, show;
	while (~scanf("%lf", &cow)) {
		scanf("%lf%lf", &car, &show);
		double ans = 0;
		ans = (cow * car / ((cow + car) * (cow + car - show - 1))) + (car / (cow + car)) * ((car - 1) / (cow + car - show - 1));
		printf("%.5lf\n", ans);
	}

	return 0;
}
