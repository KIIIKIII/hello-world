#pragma once
#include "��.h"

int main() {
	while (true) {
		cout << "������Ҫת���ĵ�λ���ͣ�1.������λ 2.ѹ����λ 3.���ȵ�λ 0.����" << endl;
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
			cout << "�������" << endl;
			break;
		}
	}

	return 0;
}