#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int flag = 1;
int con = 0;

void summon(int ah[], int aa[]) {
	int position = 0;
	scanf("%d", &position);
	if (!ah[position] && ah[position - 1]) 
		scanf("%d%d", &aa[position], &ah[position]);
	else if (ah[position]){
		int i = position;
		for (; ah[i]; i++);
		for (; i != position; i--) {
			swap(ah[i], ah[i - 1]);
			swap(aa[i], aa[i - 1]);
		}
		scanf("%d%d", &aa[position], &ah[position]);
	}
	else {
		for (; !ah[position]; position--);
		scanf("%d%d", &aa[position], &ah[position]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int ah[10] = { 30 }, aa[10] = { 0 }, bh[10] = { 30 }, ba[10] = { 0 };

	for (int i = 0; i < n; i++) {
		char action[10] = { 0 };
		scanf("%s", action);
		if (strcmp(action, "end") == 0) {
			flag = !flag;
			continue;
		}
		if (strcmp(action, "summon") == 0) {
			summon(flag ? ah : bh, flag ? aa : ba);
			continue;
		}
		if (strcmp(action, "attack") == 0) {
			if (flag) {
				int attacker = 0, defender = 0;
				scanf("%d%d", &attacker, &defender);
				ah[attacker] -= ba[defender];
				bh[defender] -= aa[attacker];
				if (ah[attacker] <= 0) {
					ah[attacker] = 0; aa[attacker] = 0;
					for (int j = attacker + 1; ah[j]; j++) {
						swap(ah[j], ah[j - 1]);
						swap(aa[j], aa[j - 1]);
					}
				}
				if (bh[defender] <= 0 && defender) {
					bh[defender] = 0; ba[defender] = 0;
					for (int j = defender + 1; bh[j]; j++) {
						swap(bh[j], bh[j - 1]);
						swap(ba[j], ba[j - 1]);
					}
				}
				if (bh[defender] <= 0 && !defender) {
					//bh[defender] = 0;
					con = 1;
					break;
				}
			}
			if (!flag) {
				int attacker = 0, defender = 0;
				scanf("%d%d", &attacker, &defender);
				bh[attacker] -= aa[defender];
				ah[defender] -= ba[attacker];
				if (bh[attacker] <= 0) {
					bh[attacker] = 0; ba[attacker] = 0;
					for (int j = attacker + 1; bh[j]; j++) {
						swap(bh[j], bh[j - 1]);
						swap(ba[j], ba[j - 1]);
					}
				}
				if (ah[defender] <= 0 && defender) {
					ah[defender] = 0; aa[defender] = 0;
					for (int j = defender + 1; ah[j]; j++) {
						swap(ah[j], ah[j - 1]);
						swap(aa[j], aa[j - 1]);
					}
				}
				if (ah[defender] <= 0 && !defender) {
					//ah[defender] = 0;
					con = -1;
				}
			}
			continue;
		}
	}

	int i, j;
	for (i = 0; ah[i + 1]; i++);
	for (j = 0; bh[j + 1]; j++);
	printf("%d\n%d\n%d ", con, ah[0], i);
	for (int p = 0; p < i; p++) printf("%d ", ah[p + 1]);
	printf("\n%d\n%d ", bh[0], j);
	for (int q = 0; q < j; q++) printf("%d ", bh[q + 1]);
	printf("\n");

	return 0;
}
