#pragma once//员工管理系统
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;
const int INT = 100;

class unit {
public:
	unit() {}
	~unit() {}
	void input() {
		cout << "请输入原单位：";
		scanf_s("%5s", unit1, 5);
		cout << endl << "请输入新单位：";
		scanf_s("%5s", unit2, 5);
		cout << endl << "请输入原值：";
		cin >> x;
		cout << endl;
	}
	void output() {
		cout << "新单位下的值为：";
		cout << y << endl;
	}
	double x;
	double y;
	char unit1[INT];
	char unit2[INT];
};

char wei[INT][5] = {"ug", "mg", "g", "kg", "t", "lb", "gr", "oz", "斤", "两", "q", "ct", "dr", "担", "钱"};
double w[INT] = {1000000, 1000, 1, 0.001, 0.000001, 0.0022046, 15.4323584, 0.035274, 0.002, 0.02, 0.00001, 5, 0.5643834, 0.00002, 0.2};
class weight :public unit {
public:
	void convert() {
		int flag1 = 0, flag2 = 0;
		if (isalnum(unit1[0])) {
			for (int i = 0; i < strlen(unit1); i++) {
				unit1[i] = tolower(unit1[i]);
			}
		}
		for (int i = 0; i < INT; i++) {
			if (strcmp(unit1, wei[i]) == 0) {
				flag1 = i;
				break;
			}
		}
		if (isalnum(unit2[0])) {
			for (int i = 0; i < strlen(unit2); i++) {
				unit2[i] = tolower(unit2[i]);
			}
		}
		for (int i = 0; i < INT; i++) {
			if (strcmp(unit2, wei[i]) == 0) {
				flag2 = i;
				break;
			}
		}
		y = x / w[flag1] * w[flag2];
	}
};

char pre[INT][5] = {"pa", "mmhg", "bar", "kpa", "psi", "atm", "mpa", "psf", "hpa", "inhg", "mbar"};
double p[INT] = {1, 0.0075006, 0.00001, 0.001, 0.000145, 9.8692e-6, 1e-6, 0.0208854, 0.01, 0.0002953, 0.01};
class pressure :public unit {
public:
	void convert() {
		int flag1 = 0, flag2 = 0;
		if (isalnum(unit1[0])) {
			for (int i = 0; i < strlen(unit1); i++) {
				unit1[i] = tolower(unit1[i]);
			}
		}
		for (int i = 0; i < INT; i++) {
			if (strcmp(unit1, pre[i]) == 0) {
				flag1 = i;
				break;
			}
		}
		if (isalnum(unit2[0])) {
			for (int i = 0; i < strlen(unit2); i++) {
				unit2[i] = tolower(unit2[i]);
			}
		}
		for (int i = 0; i < INT; i++) {
			if (strcmp(unit2, pre[i]) == 0) {
				flag2 = i;
				break;
			}
		}
		y = x / p[flag1] * p[flag2];
	}
};

char len[INT][5] = {"m", "cm", "km", "mm", "dm", "um", "nm", "pm", "ly", "au", "in", "mi", "ft", "尺", "yd", "nmi", "fm", "fur", "里", "丈", "寸", "分", "厘", "毫"};
double l[INT] = {1, 100, 0.001, 1000, 10, 1e6, 1e9, 1e12, 1.057e-16, 6.6846e-12, 39.3700787, 0.0006214, 3.2808399, 3, 1.0936133, 0.00054, 0.5468066, 0.004971, 0.002, 0.3, 30, 300, 3000, 30000};
class length :public unit {
public:
	void convert() {
		int flag1 = 0, flag2 = 0;
		if (isalnum(unit1[0])) {
			for (int i = 0; i < strlen(unit1); i++) {
				unit1[i] = tolower(unit1[i]);
			}
		}
		for (int i = 0; i < INT; i++) {
			if (strcmp(unit1, len[i]) == 0) {
				flag1 = i;
				break;
			}
		}
		if (isalnum(unit2[0])) {
			for (int i = 0; i < strlen(unit2); i++) {
				unit2[i] = tolower(unit2[i]);
			}
		}
		for (int i = 0; i < INT; i++) {
			if (strcmp(unit2, len[i]) == 0) {
				flag2 = i;
				break;
			}
		}
		y = x / l[flag1] * l[flag2];
	}
};