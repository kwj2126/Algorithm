#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int dp[1000];
int N;

void solve();

int main() {
    scanf("%d", &N);
    for (int i = 0 ; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    solve();
}

void solve() {
    int dp_idx = 0;
    dp[0] = arr[0];

    for (int i = 1; i < N; ++i) {
        if (arr[i] > dp[dp_idx]) 
            dp[++dp_idx] = arr[i];
        else {
            int lower_idx = lower_bound(dp, dp + dp_idx, arr[i]) - dp;
            dp[lower_idx] = arr[i];
        }
    }

    printf("%d\n", dp_idx+1);
}