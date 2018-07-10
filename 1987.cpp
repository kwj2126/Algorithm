#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct tile {
    int arr[26];
    int x, y;
    int length;
} tile;

int R, C;
int map[20][20];
int move_x[] = {1, -1, 0, 0};
int move_y[] = {0, 0, 1, -1};

void solve();

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char ch;
            scanf(" %c", &ch);  // 띄어쓰기 할것
            map[j][i] = ch - 'A';
        }
    }

    // for (int i = 0; i < R; ++i) {
    //     for (int j = 0; j < C; ++j) {
    //         printf("%d ", map[j][i]);
    //     }
    //     printf("\n");
    // }
    solve();
}

void solve() {
    int max_length = 1;

    stack<tile> Q;
    tile T; T.x = 0; T.y = 0; T.length = 1;
    for (int i = 0; i < 26; ++i) {
        T.arr[i] = 0;
    }
    T.arr[map[0][0]] = 1;
    Q.push(T);

    while (!Q.empty()) {
        tile V = Q.top();
        Q.pop();

        if (V.length > max_length)
            max_length = V.length;
        // printf("%d\n", max_length);

        for (int i = 0; i < 4; ++i) {
            int x = V.x + move_x[i];
            int y = V.y + move_y[i];

            if (x < C && x >= 0 && y < R && y >= 0) {
                if (V.arr[map[x][y]] == 0) {
                    tile N; N.x = x; N.y = y; N.length = V.length + 1;
                    for (int i = 0; i < 26; ++i) {
                        N.arr[i] = V.arr[i];
                    }
                    N.arr[map[x][y]] = 1;
                    Q.push(N);
                }
            }
        }
    }

    printf("%d\n", max_length);
}









