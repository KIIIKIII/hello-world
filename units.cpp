#pragma once
#include "잚.h"

int main() {
	while (true) {
		cout << "헝渴흙狼瘻뺏돨데貫잚謹：1.路좆데貫 2.箕제데貫 3.낀똑데貫 0.써監" << endl;
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
			cout << "渴흙댄轎！" << endl;
			break;
		}
	}

	return 0;
}
