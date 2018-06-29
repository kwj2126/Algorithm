#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int N, M, num;

int binary_search(int left, int right, int num);
void solve();

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &M);
    sort(arr, arr+N);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &num);
        solve();
    }
}       

void solve() {
    printf("%d\n", binary_search(0, N-1, num));

}


int binary_search(int left, int right, int num) {
    int mid = (left + right) / 2;
    if (left <= right) {
        if (arr[mid] == num)
            return 1;
        else if (arr[mid] < num)
            return binary_search(mid+1, right, num);
        else
            return binary_search(left, mid-1, num);
    }
    return 0;
}
