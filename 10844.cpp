// author	KIM WAN JUN
// file		10844.cpp
// problem	https://www.acmicpc.net/problem/10844
// date		2017.11.08.

#include <iostream>

#define DIV 1000000000

int N;
int arr[100][10];

void solve();

int main() {
	scanf("%d", &N);
	solve();

	return 0;
}

void solve() {
	int ans = 0;

	arr[0][0] = 0;
	for (int i = 1; i < 10; ++i) {
		arr[0][i] = 1;
	}

	for (int i = 1; i < N; ++i) {
		arr[i][0] = arr[i-1][1];
		arr[i][9] = arr[i-1][8];
		for (int j = 1; j < 9; ++j) {
			arr[i][j] = arr[i-1][j+1] + arr[i-1][j-1];
			arr[i][j] %= DIV;
		}
	}

	for (int i = 0; i < 10; ++i) {
		ans += arr[N-1][i];
		ans %= DIV;
	}

	printf("%d", ans);
}