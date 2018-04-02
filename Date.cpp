#pragma once
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

class Date {
public:
	Date(int y, int m, int d);
	~Date();
	bool leap();
	void nextDay();
	void previousDay();
	bool equal(Date other);
	void show();
private:
	int year;
	int month;
	int day;
};

#include "date.h"

int list[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

bool Date::leap() {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
	return false;
}

void Date::nextDay() {
	list[2] += leap();
	if (day < list[month]) {
		day++;
	}
	else if (month < 12) {
		month++;
		day = 1;
	}
	else {
		year++;
		month = 1;
		day = 1;
	}
	list[2] -= leap();
}
void Date::previousDay() {
	list[2] += leap();
	if (day > 1) {
		day--;
	}
	else if (month > 1) {
		month--;
		day = list[month];
	}
	else {
		year--;
		month = 12;
		day = 31;
	}
	list[2] -= leap();
}
bool Date::equal(Date other) {
	if (other.year == year && other.month == month && other.day == day) return 1;
	return 0;
}
void Date::show() {
	printf("%d-%d-%d\n", year, month, day);
}
Date::~Date() {
}

int main() {
	Date today(2018, 3, 20);
	Date day(2018, 3, 20);
	day.show();
	for (int i = 0; i < 30; i++)
		day.nextDay();
	day.show();
	for (int i = 0; i < 30; i++)
		day.previousDay();
	day.show();
	if (day.equal(today))
		printf("Very Good!\n");
	else
		printf("Very Bad!\n");
	return 0;
}
