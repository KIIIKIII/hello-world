#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

int list[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
struct Date {
	int year;
	int month;
	int day;
};

bool leap(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
	return false;
}

void next_day(struct Date &day) {
	list[2] += leap(day.year);
	if (day.day < list[day.month]) {
		day.day++;
	}
	else if (day.month < 12) {
		day.month++;
		day.day = 1;
	}
	else {
		day.year++;
		day.month = 1;
		day.day = 1;
	}
	list[2] -= leap(day.year);
}
void previous_day(struct Date &day) {
	list[2] += leap(day.year);
	if (day.day > 1) {
		day.day--;
	}
	else if (day.month > 1) {
		day.month--;
		day.day = list[day.month];
	}
	else {
		day.year--;
		day.month = 12;
		day.day = 31;
	}
	list[2] -= leap(day.year);
}
int equal(struct Date one, struct Date day) {
	if (one.year == day.year && one.month == day.month && one.day == day.day) return 1;
	return 0;
}

void show(struct Date day) {
	printf("%d-%d-%d\n", day.year, day.month, day.day);
}
int main() {
	struct Date today = { 2018,3,20 };
	struct Date day = { 2018,3,20 };
	show(day);
	for (int i = 0; i < 30; i++)
		next_day(day);
	show(day);
	for (int i = 0; i < 30; i++)
		previous_day(day);
	show(day);
	if (equal(today, day))
		printf("Very Good!\n");
	else
		printf("Very Bad!\n");
	return 0;
}
