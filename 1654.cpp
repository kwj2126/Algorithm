#include <iostream>
#include <climits>
using namespace std;

long long K, N, max_num=0;
long long arr_k[10000];

void solve();
long long counter(long long length);

int main() {
    scanf("%lld %lld", &K, &N);
    for (long long i = 0; i < K; ++i) {
        scanf("%lld", &arr_k[i]);
    }
    solve();
}

void solve() {
    long long min_num = 0;
    long long max_num = INT_MAX;
    while (1) {
        long long mid = (min_num + max_num) / 2;
        long long count = counter(mid);
        if (count >= N) {
            min_num = mid;
        } else {
            max_num = mid;
        }

        if (max_num == min_num) {
            printf("%lld\n", max_num);
            break;
        }
        if (max_num - 1 == min_num) {
            if (max_num >= 2) {
                if (counter(max_num) == N)
                    printf("%lld\n", max_num);
                else
                    printf("%lld\n", min_num);
            } else {
                printf("1\n");
            }
            break;
        }
    }
}

long long counter(long long length) {
    long long count = 0;
    for (long long i = 0; i < K; ++i) {
        count += arr_k[i] / length;
    }
    return count;
}