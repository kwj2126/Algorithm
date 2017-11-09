// author	KIM WAN JUN
// file		2293.cpp
// problem	https://www.acmicpc.net/problem/2293
// date		2017.11.09.

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
		if (coin[i] > k)
			continue;
		make_k[coin[i]] += 1;
		for (int j = coin[i] + 1; j <= k; ++j) {
			if (j - coin[i] < 0)
				continue;
			make_k[j] += make_k[j-coin[i]];
		}
	}

	printf("%d\n", make_k[k]);
}