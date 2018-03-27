#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.
例如113就是一个超级素数.求[100,9999]之内:
(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
int sum_bit(int num) {
	int q = num / 1000; //千位
	int w = num % 1000 / 100; //百位
	int e = num % 100 / 10; //十位
	int r = num % 10; //个位
	return q + w + e + r;
}

int multi_bit(int num) {
	int q = num / 1000; //千位
	int w = num % 1000 / 100; //百位
	int e = num % 100 / 10; //十位
	int r = num % 10; //个位
	return q * w * e * r;
}

int square_sum_bit(int num) {
	int q = num / 1000; //千位
	int w = num % 1000 / 100; //百位
	int e = num % 100 / 10; //十位
	int r = num % 10; //个位
	return q * q + w * w + e * e + r * r;
}

bool isprime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	int num;
	cin >> num;
	if (isprime(num) && isprime(sum_bit(num)) && isprime(multi_bit(num)) && isprime(square_sum_bit(num)))
		cout << num << " is super prime." << endl;
	else cout << num << " is not super prime." << endl;
	return 0;
}
