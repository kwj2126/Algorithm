// author	KIM WAN JUN
// file		2156.cpp
// problem	https://www.acmicpc.net/problem/2156
// date		2017.11.08.

#include <iostream>

int n;
int arr[10000];
int max[10000];

void solve();
int max_value(int a, int b, int c);

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	solve();
	return 0;
}

void solve() {
	max[0] = arr[0];
	max[1] = arr[0] + arr[1];
	max[2] = max_value(arr[0] + arr[1], arr[0] + arr[2], arr[1] + arr[2]);

	for (int i = 3; i < n; ++i) {
		max[i] = max_value(max[i-1], max[i-2] + arr[i], max[i-3] + arr[i] + arr[i-1]);
	}

	printf("%d\n", max[n-1]);
}

int max_value(int a, int b, int c) {
	int max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return max;
}