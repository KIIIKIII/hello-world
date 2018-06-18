#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

inline int leap(int year) {//判断是否是闰年
	return (!(year % 400) || (!(year % 4) && year % 100));
}

int fresh(int year) {//计算这一年的第一天是星期几
	int count = 2;
	for (int i = 1850; i < year; i++) {
		count = count + 365 + leap(i);
	}
	//if (year > 1850) count += 1;
	count %= 7;
	if (count) return count;
	else return 7;
}

int first(int month, int list[], int fresh) {//计算这一年指定月的第一天是星期几

	for (int i = 1; i < month; i++) {
		fresh += list[i];
	}
	//if (month > 1) fresh += 1;
	fresh %= 7;
	if (fresh) return fresh;
	else return 7;
}

int date(int first, int month, int b, int c, int list[]) {//判断该月第b个星期c是否存在，若是则返回日期
	if (b > 6) return 0;
	int dat = first > c ? 8 - first + c : c - first + 1;
	dat = dat + 7 * (b - 1);
	if (dat <= list[month]) return dat;
	else return 0;
}

int main() {
	int a, b, c, y1, y2;
	cin >> a >> b >> c >> y1 >> y2;
	int list[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = y1; i <= y2; i++) {
		list[2] += leap(i);
		int fre = fresh(i);
		int fir = first(a, list, fre);
		int dat = date(fir, a, b, c, list);
		if (!dat) {
			printf("none\n");
			list[2] -= leap(i);
			continue;
		}
		else {
			printf("%04d/%02d/%02d\n", i, a, dat);
			list[2] -= leap(i);
		}
	}

	return 0;
}
