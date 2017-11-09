// author	KIM WAN JUN
// file		11052.cpp
// problem	https://www.acmicpc.net/problem/11052
// date		2017.11.09.

#include <iostream>

int N;
int P[1000];
int max_sum[1000];

void solve();

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &P[i]);
	}
	solve();

	return 0;
}

void solve() {
	int tmp_max;
	max_sum[0] = P[0];

	for (int i = 1; i < N; ++i) {
		tmp_max = 0;
		
		for (int j = 0; j <= i; ++j) {
			if (tmp_max < max_sum[i-j-1] + P[j])
				tmp_max = max_sum[i-j-1] + P[j];
		}
		max_sum[i] = tmp_max;
	}

	printf("%d\n", max_sum[N-1]);
}	