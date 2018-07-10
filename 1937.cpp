#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int map[500][500];
int dp[500][500];
int move_x[] = {1, -1, 0, 0};
int move_y[] = {0, 0, 1, -1};

void solve();

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

bool operator <(const Tile &a, const Tile &b) {  // 오름차순
    return a.value < b.value;
}

vector<Tile> v;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &map[i][j]);  // [세로][가로];
            v.push_back(Tile(j, i, map[i][j]));
        }
    }
    solve();
}

void solve() {
    int max_length = 1;
    sort(v.begin(), v.end());
    dp[v[0].y][v[0].x] = 1;
    for (int i = 1; i < v.size(); ++i) {
        int max_tmp = 0;
        for (int j = 0; j < 4; ++j) {
            int x = v[i].x + move_x[j];
            int y = v[i].y + move_y[j];

            if (x < n && y < n && x >= 0 && y >= 0) {
                if (map[v[i].y][v[i].x] > map[y][x] && max_tmp < dp[y][x])
                    max_tmp = dp[y][x];
            }
        }

        dp[v[i].y][v[i].x] = max_tmp + 1;
        if (max_length < max_tmp + 1)
            max_length = max_tmp + 1;
    }
    printf("%d\n", max_length);
}

