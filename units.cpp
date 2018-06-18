#pragma once
#include "units.h"

int main() {
	while (true) {
		cout << "请输入要转化的单位类型：1.重量单位 2.压力单位 3.长度单位 0.结束" << endl;
		int flag = 0;
		cin >> flag;
		if (!flag) break;
		switch (flag) {
		case 1: {
			weight W;
			W.input();
			W.convert();
			W.output();
			break;
		}
		case 2: {
			pressure P;
			P.input();
			P.convert();
			P.output();
			break;
		}
		case 3: {
			length L;
			L.input();
			L.convert();
			L.output();
			break;
		}
		default:
			cout << "输入错误！" << endl;
			break;
		}
	}

	return 0;
}
