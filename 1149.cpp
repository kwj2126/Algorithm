#include <iostream>

int N;
int arr[1000][3];
int dp[1000][3];

void solve();
int min_(int a, int b);

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    solve();
}

void solve() {
    for (int i = 0; i < 3; ++i) {
        dp[0][i] = arr[0][i];
    }

    for (int i = 1; i < N; ++i) {
        dp[i][0] = min_(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min_(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = min_(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }

    printf("%d\n", min_(dp[N-1][0], min_(dp[N-1][1], dp[N-1][2])));
}

int min_(int a, int b) {
    if (a > b)
        return b;
    else
        return a;
}