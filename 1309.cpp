// author	KIM WAN JUN
// file		1309.cpp
// problem	https://www.acmicpc.net/problem/1309
// date		2017.11.10.

#include <iostream>

#define DIV 9901

int N;
int arr[100001][2];

void solve();

int main() {
	scanf("%d", &N);
	solve();

	return 0;
}

void solve() {
	arr[1][0] = 1; // 끝 배치 x
	arr[1][1] = 2; // 끝 배치 o

	for (int i = 2; i <= N; ++i) {
		arr[i][0] = arr[i-1][0] + arr[i-1][1];
		arr[i][0] %= DIV;
		arr[i][1] = arr[i-1][0] * 2 + arr[i-1][1];
		arr[i][1] %= DIV;
	}

	printf("%d\n", (arr[N][0] + arr[N][1]) % DIV);
}