// author	KIM WAN JUN
// file		2294.cpp
// problem	https://www.acmicpc.net/problem/2294
// date		2017.11.10.

#include <iostream>

int n, k;
int coin[100];
int make_k[10001];

void solve();

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &coin[i]);
	}
	solve();

	return 0;
}

void solve() {
	for (int i = 0; i < n; ++i) {
		if (coin[i] > k || coin[i] < 0)
			continue;
		make_k[coin[i]] = 1;
	}

	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < n; ++j) {
			if (coin[j] > k)
				continue;
			if (i - coin[j] <= 0)
				continue;
			if (make_k[i-coin[j]] == 0)
				continue;
			if (make_k[i] == 0 && make_k[i-coin[j]] != 0)
				make_k[i] = make_k[i-coin[j]] + 1;
			if (make_k[i-coin[j]] + 1 < make_k[i])
				make_k[i] = make_k[i-coin[j]] + 1;
		}
	}
	if (make_k[k] == 0)
		printf("-1\n");
	else
		printf("%d\n", make_k[k]);
}