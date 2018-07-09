#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
int dp[100001];

void solve();

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &arr[i]);
    }
    solve();
}

void solve() {
    int dp_idx = 1;

    dp[1] = arr[1];
    for (int i = 2; i <= N; ++i) {
        if (dp[dp_idx] < arr[i])
            dp[++dp_idx] = arr[i];
        else {
            int lower_idx = lower_bound(dp + 1, dp + dp_idx + 1, arr[i]) - dp;
            dp[lower_idx] = arr[i];
        }
    }
    printf("%d\n", N - dp_idx);
}