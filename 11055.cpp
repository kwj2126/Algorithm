// author	KIM WAN JUN
// file		11055.cpp
// problem	https://www.acmicpc.net/problem/11055
// date		2017.11.22.

#include <iostream>

int A;
int arr[1000];
int max_sum[1000];

void solve();

int main() {
	scanf("%d", &A);
	for (int i = 0; i < A; ++i) {
		scanf("%d", &arr[i]);
	}
	solve();
 
	return 0;
}

void solve() {
	max_sum[0] = arr[0];
	int ans = arr[0];

	for (int i = 1; i < A; ++i) {
		int max = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j] && max_sum[j] > max)
				max = max_sum[j];
		}
		max_sum[i] = max + arr[i];
		if (max_sum[i] > ans)
			ans = max_sum[i];
	}

	printf("%d\n", ans);
}