// author	KIM WAN JUN
// file		2163.cpp
// problem	https://www.acmicpc.net/problem/2163
// date		2017.11.09.

#include <iostream>

int N, M;

void solve();

int main() {
	scanf("%d %d", &N, &M);
	solve();

	return 0;
}

void solve() {
	printf("%d\n", N * M - 1);
}