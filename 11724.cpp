#include <iostream>
#include <queue>
using namespace std;

int N, M, u, v;
int graph[1000][1000];
int visit[1000];

void solve();
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &u, &v);
        graph[u-1][v-1] = 1;
        graph[v-1][u-1] = 1;
    }
    solve();
}

void solve() {
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (visit[i] == 0) {
            queue<int> Q;
            Q.push(i);
            visit[i] = 1;
            count++;
            while (!Q.empty()) {
                int node = Q.front();
                Q.pop();

                for (int j = 0; j < N; ++j) {
                    if (graph[node][j] == 1 && visit[j] == 0) {
                        Q.push(j);
                        visit[j] = 1;
                    }
                }
            }
        }
    }
    printf("%d\n", count);
}