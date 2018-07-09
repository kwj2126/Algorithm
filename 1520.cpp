#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
int arr[500][500];
int dp[500][500];
int move_x[] = {1, -1, 0, 0};
int move_y[] = {0, 0, 1, -1};

class Tile {
public:
    int value;
    int x, y;
    Tile(int x, int y, int value) {
        this->x = x;
        this->y = y;
        this->value = value;
    }
};

bool operator <(const Tile &a, const Tile &b) {  // 내림차순
    return a.value > b.value;
}

vector<Tile> v;

void solve();

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf(" %d", &arr[j][i]);
            v.push_back(Tile(j, i, arr[j][i]));
        }
    }

    solve();
}

void solve() {
    sort(v.begin(), v.end());
    dp[0][0] = 1;
    for (int i = 0; i < v.size(); ++i) {
        int dp_sum = 0;
        for (int j = 0; j < 4; ++j) {
            int x = v[i].x + move_x[j];
            int y = v[i].y + move_y[j];

            if (x < N && x >= 0 && y < M && y >= 0) {
                if (arr[v[i].x][v[i].y] < arr[x][y])
                    dp_sum += dp[x][y];
            }
        }
        dp[v[i].x][v[i].y] += dp_sum;
    }

    printf("%d\n", dp[N-1][M-1]);
}