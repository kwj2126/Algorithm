// author	KIM WAN JUN
// file		1912.cpp
// problem	https://www.acmicpc.net/problem/1912
// date		2017.11.08.

#include <iostream>

int n;
int arr[100000];
int max[100000];

void solve();

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	solve();

	return 0;
}

void solve() {
	int ans = arr[0];

	max[0] = arr[0];
	for (int i = 1; i < n; ++i) {
		if (max[i-1] > 0)
			max[i] = max[i-1] + arr[i];
		else
			max[i] = arr[i];

		if (ans < max[i])
			ans = max[i];
	}

	printf("%d", ans);
}