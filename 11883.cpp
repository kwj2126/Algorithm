// author	KIM WAN JUN
// file		11883.cpp
// problem	https://www.acmicpc.net/problem/11883
// date		2017.11.08.

#include <iostream>

int T, N;

void solve();

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d", &N);
		solve();
	}
	return 0;
}

void solve() {
	int num_3 = 0, num_5 = 0, num_8 = 0;
	int tmp = N / 8;
	bool can_make = 1;

	switch (N % 8) {
		case 0:
			num_8 = tmp;
			break;
		case 1:
			if (N == 1)
				can_make = 0;
			num_3 = 3;
			num_8 = tmp - 1;
			break;
		case 2:
			if (N == 2)
				can_make = 0;
			num_5 = 2;
			num_8 = tmp - 1;
			break;
		case 3:
			num_3 = 1;
			num_8 = tmp;
			break;
		case 4:
			if (N == 4)
				can_make = 0;
			if (N == 12) {
				num_3 = 4;
				num_8 = tmp - 1;
			}
			else {
				num_5 = 4;
				num_8 = tmp - 2;
			}
			break;
		case 5:
			num_5 = 1;
			num_8 = tmp;
			break;
		case 6: 
			num_3 = 2;
			num_8 = tmp;
			break;
		case 7:
			if (N == 7)
				can_make = 0;
			num_5 = 3;
			num_8 = tmp - 1;
			break;
	}

	if (!can_make) {
		printf("-1\n");
		return;
	}

	for (int i = 0; i < num_3; ++i) {
		printf("3");
	}
	for (int i = 0; i < num_5; ++i) {
		printf("5");
	}
	for (int i = 0; i < num_8; ++i) {
		printf("8");
	}
	printf("\n");
}
