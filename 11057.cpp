// author	KIM WAN JUN
// file		11057.cpp
// problem	https://www.acmicpc.net/problem/11057
// date		2017.11.10.

#include <iostream>

#define DIV 10007

int N;
int arr[1001][10];

void solve();

int main() {
	scanf("%d", &N);
	solve();

	return 0;
}

void solve() {
	for (int i = 0; i < 10; ++i) {
		arr[1][i] = 1;
	}

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j < 10; ++j) {
			int sum = 0;
			for (int k = 0; k <= j; ++k) {
				sum += arr[i-1][k];
				sum %= DIV;
			}
			arr[i][j] = sum;
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; ++i) {
		ans += arr[N][i];
		ans %= DIV;
	}

	printf("%d\n", ans);
}