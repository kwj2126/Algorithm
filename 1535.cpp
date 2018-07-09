#include <iostream>
using namespace std;

int N;
int L[20];
int J[20];
int dp[20][101];  // [x][y] = x번째 사람까지 중에 y의 체력으로 얻을 수 있는 최댓값 

void solve();
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &L[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &J[i]);
    }
    solve();
}

void solve() {
    int max_value = 0;
    for (int i = 0; i <= 100; ++i) {
        if (i <= L[0])
            dp[0][i] = 0;
        else {
            dp[0][i] = J[0];
            if (max_value < J[0])
                max_value = J[0];
        }
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j <= 100; ++j) {
            if (j-L[i] > 0)
                dp[i][j] = max(dp[i-1][j-L[i]] + J[i], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
            
            if (dp[i][j] > max_value)
                max_value = dp[i][j];
        }
    }
    printf("%d\n", max_value);
}