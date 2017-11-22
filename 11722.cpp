// author	KIM WAN JUN
// file		11722.cpp
// problem	https://www.acmicpc.net/problem/11722
// date		2017.11.22.

#include <iostream>

int A;
int arr[1000];
int max_length[1000];

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
	max_length[0] = 1;
	int ans = 1;

	for (int i = 1; i < A; ++i) {
		int length = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[j] > arr[i] && max_length[j] > length)
				length = max_length[j];
		}
		max_length[i] = length + 1;
		
		if (max_length[i] > ans)
			ans = max_length[i];
	}

	printf("%d\n", ans);
}