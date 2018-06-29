#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long N, M;
int arr[1000000];

void solve();
long long sum_tree(long long length);

int main() {
    scanf("%lld %lld", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);
    solve();
}

void solve() {
    long long min_length = 1;
    long long max_length = INT_MAX;

    while (min_length <= max_length) {
        long long mid = (min_length + max_length) / 2;
        long long trees = sum_tree(mid);
        // if (max_length - min_length == 1) {
        //     if (trees >= sum_tree(min_length)) {
        //         if (trees >= sum_tree(max_length))
        //             printf("%lld\n", max_length);
        //         else
        //             printf("%lld\n", min_length);
        //     }
        //     else {
        //         printf("%lld\n", max_length);
        //     }
        //     break;
        // }

        if (trees < M)
            max_length = mid-1;
        if (trees > M) 
            min_length = mid+1;
        if (trees == M) {
            printf("%lld\n", mid);
            return;
        }


    }
    printf("%lld\n", max_length);
}

long long sum_tree(long long length) {
    long long tree = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i] - length > 0)
            tree += arr[i] - length;
    }
    return tree;
}