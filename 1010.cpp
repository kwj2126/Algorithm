// author	KIM WAN JUN
// file		1010.cpp
// problem	https://www.acmicpc.net/problem/1010
// date		2017.11.08.

#include <iostream>

int T, N, M;
int comb[30][30];

void solve();

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d %d", &N, &M);
		solve();
	}

	return 0;
}

void solve() {
	comb[0][0] = 1;

	for (int i = 1; i < M; ++i) {
		comb[i][0] = i + 1;
		for (int j = 1; j <= i; ++j) {
			if (j == N)
				break;

			comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
		}
	}

	printf("%d\n", comb[M-1][N-1]);
}