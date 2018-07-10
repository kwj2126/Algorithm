#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

int N, M, S, D;
int U, V, P;
typedef pair<int, int> Node; // <dist, node>
vector<Node> adj[500];
vector<int> back_track[500];
int dist[500];
int INF = 1000000000;

void reset();
void solve();
void back_tracking(int node);
int main() {
    while (1) {
        reset();
        scanf("%d %d", &N, &M);
        if (N == 0)
            break;
        scanf("%d %d", &S, &D);
        for (int i = 0; i < M; ++i) {
            scanf("%d %d %d", &U, &V, &P);
            adj[U].push_back(Node(P, V));
        }
        solve();
    }
}

void reset() {
    for (int i = 0; i < 500; ++i) {
        adj[i].clear();
        back_track[i].clear();
        dist[i] = INF;
    }
}

void soft_reset() {
    for (int i = 0; i < 500; ++i) {
        dist[i] = INF;
    }
}

void solve() {
    priority_queue<Node> PQ;
    PQ.push(Node(0, S));
    dist[S] = 0;

    while (!PQ.empty()) {
        int distance_from_start = -PQ.top().first;
        int current_node = PQ.top().second;
        PQ.pop();

        if (distance_from_start > dist[current_node]) continue;
        for (auto node_to_next: adj[current_node]) {
            int next_distance = node_to_next.first;
            int next_node = node_to_next.second;

            if (next_distance + dist[current_node] > dist[next_node]) continue;
            if (next_distance + dist[current_node] == dist[next_node]) 
                back_track[next_node].push_back(current_node);
            else {
                back_track[next_node].clear();
                back_track[next_node].push_back(current_node);
            }

            dist[next_node] = next_distance + dist[current_node];
            PQ.push(Node(-dist[next_node], next_node));
        }
    }

    back_tracking(D);
    soft_reset();

    // priority_queue<Node> PQ;
    PQ.push(Node(0, S));
    dist[S] = 0;

    while (!PQ.empty()) {
        int distance_from_start = -PQ.top().first;
        int current_node = PQ.top().second;
        PQ.pop();

        if (distance_from_start > dist[current_node]) continue;
        for (auto node_to_next: adj[current_node]) {
            int next_distance = node_to_next.first;
            int next_node = node_to_next.second;

            if (next_distance + dist[current_node] > dist[next_node]) continue;
            if (next_distance + dist[current_node] == dist[next_node]) 
                back_track[next_node].push_back(current_node);
            else {
                back_track[next_node].clear();
                back_track[next_node].push_back(current_node);
            }

            dist[next_node] = next_distance + dist[current_node];
            PQ.push(Node(-dist[next_node], next_node));
        }
    }
    if (dist[D] >= INF)
        printf("-1\n");
    else
        printf("%d\n", dist[D]);

}


void back_tracking(int node) {
    for (int i = 0; i < back_track[node].size(); ++i) {
        int prev_node = back_track[node][i];
        for (int j = 0; j < adj[prev_node].size(); ++j) {
            if (adj[prev_node][j].second == node) {
                adj[prev_node][j].first = INF;
                break;
            }
        }
        back_tracking(prev_node);
    }
}





