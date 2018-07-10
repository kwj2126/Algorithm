#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int T;
int n, m, t;
int s, g, h;
int a, b, d;
int tmp;

typedef pair<int, int> P;  // <dist, node>
priority_queue<P> PQ;
const int INF = INT_MAX;
const int MAX_V = 2000;
vector<P> adj[MAX_V];
vector<int> BT[MAX_V];
int dist[MAX_V];
int goal[100];

void solve();
void reset();
int back_track(int node, int t1, int t2, int prt);
int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        reset();
        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);  // s : 출발지 / g & h : 지나는 경로
        s--; g--; h--;
        for (int j = 0; j < m; ++j) {
            scanf("%d %d %d", &a, &b, &d);
            adj[a-1].push_back(P(d, b-1));
            adj[b-1].push_back(P(d, a-1));
        }
        for (int j = 0; j < t; ++j) {
            scanf("%d", &tmp);
            goal[j] = tmp - 1;
        }
        solve();
    }
}

void reset() {
    for (int i = 0; i < MAX_V; ++i) {
        dist[i] = INF;
        adj[i].clear();
        BT[i].clear();
    }
}
void solve() {
    dist[s] = 0;
    PQ.push(P(0, s));
    while(!PQ.empty()) {
        int distance = -PQ.top().first;
        int node = PQ.top().second;
        PQ.pop();

        if (distance > dist[node]) continue;
        for (auto node_to_next : adj[node]) {
            int distance_from_now_to_next = node_to_next.first;
            int node_next = node_to_next.second;
            int distance_until_next = distance + distance_from_now_to_next;
            if (distance_until_next > dist[node_next]) {
                continue;
            }
            if (distance_until_next == dist[node_next]) {
                BT[node_next].push_back(node);
            } else {
                BT[node_next].clear();
                BT[node_next].push_back(node);
            }
            dist[node_next] = distance_until_next;
            PQ.push(P(-distance_until_next, node_next));

        }

    }

    sort(goal, goal + t);
    for (int i = 0 ; i < t; ++i) {
        back_track(goal[i], g, h, goal[i]);
    }
    printf("\n");
}

int back_track(int node, int t1, int t2, int prt) {
    for (int i = 0; i < BT[node].size(); ++i) {
        if ((node == t1 && BT[node][i] == t2) or (node == t2 && BT[node][i] == t1)) {
            printf("%d ", prt+1);
            return 1;
        }

        if (back_track(BT[node][i], t1, t2, prt) == 1)
            return 1;
    }
    return 0;
}








