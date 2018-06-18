#pragma once

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

class Prime {
public:
	Prime();
	Prime(int n);
	int sum_bit(int num);
	int multi_bit(int num);
	int square_sum_bit(int num);
	bool isprime(int num);
	void print(int num);
	~Prime();
private:
	int num;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Prime.h"



Prime::Prime() {
}

Prime::Prime(int n) {
	int num = n;
}

int Prime::sum_bit(int num) {
	int q = num / 1000; //千位
	int w = num % 1000 / 100; //百位
	int e = num % 100 / 10; //十位
	int r = num % 10; //个位
	return q + w + e + r;
	return 0;
}

int Prime::multi_bit(int num)
{
	int q = num / 1000; //千位
	int w = num % 1000 / 100; //百位
	int e = num % 100 / 10; //十位
	int r = num % 10; //个位
	return q * w * e * r;
}

int Prime::square_sum_bit(int num) {
	int q = num / 1000; //千位
	int w = num % 1000 / 100; //百位
	int e = num % 100 / 10; //十位
	int r = num % 10; //个位
	return q * q + w * w + e * e + r * r;
}

bool Prime::isprime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void Prime::print(int num) {
	if (isprime(num) && isprime(sum_bit(num)) && isprime(multi_bit(num)) && isprime(square_sum_bit(num)))
		cout << num << " is super prime." << endl;
	else cout << num << " is not super prime." << endl;
}

Prime::~Prime() {

}

int main() {
	int n;
	cin >> n;
	Prime prime(n);
	prime.print(n);

	return 0;
}
