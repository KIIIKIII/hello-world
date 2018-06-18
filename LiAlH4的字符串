#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

char a[10001] = { 0 };
int b[30] = { 0 }, c[30] = { 0 };
int maxn(int b[]) {
	int Max = b[0];
	int j = 0;
	for (int i = 0; i < 26; i++) {
		if (Max < b[i]) {
			Max = b[i];
			j = i;
		}
	}
	return j;
}
int main() {
	scanf("%s", a);
	for (unsigned i = 0; i < strlen(a); i++) {
		if (isupper(a[i])) a[i] = tolower(a[i]);
	}
	sort(a, a + strlen(a));
	int count = 0;
	for (unsigned i = 0; i < strlen(a); i++) {
		if (i == 0 || a[i] == a[i - 1]) b[count]++;
		else b[++count]++;
	}
	long long int sum = 0;
	for (int i = 0; i <= count; i++) {
		sum = sum + (26 - i) * b[maxn(b)];
		b[maxn(b)] = 0;
	}
	printf("%lld\n", sum);

	return 0;
}
