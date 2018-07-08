#include <iostream>

int N, M;
int arr[100000];
int dp[100000];
int num1, num2;

void solve();

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
        if (i == 0)
            dp[0] = arr[0];
        else 
            dp[i] = dp[i-1] + arr[i];
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &num1, &num2);
        solve();
    }
}

void solve() {
    if (num1 == 1)
        printf("%d\n", dp[num2-1]);
    else
        printf("%d\n", dp[num2-1] - dp[num1-2]);
}