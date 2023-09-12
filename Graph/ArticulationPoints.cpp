#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
vector<int> G[N + 5];
int disc[N + 5], low[N + 5], visited[N + 5], isAP[N + 5];

void ArticulationPoints(int vertex, int &time, int parent) {
    int children = 0;
    visited[vertex] = 1;
    disc[vertex] = low[vertex] = ++time;
    for (auto child : G[vertex]) {
        if (!visited[child]) {
            children++;
            ArticulationPoints(child, time, vertex);
            low[vertex] = min(low[vertex], low[child]);
            if (parent != -1 && low[child] >= disc[vertex]) isAP[vertex] = 1;
        }else if (child != parent) low[vertex] = min(low[vertex], disc[child]);
    }
    if (parent == -1 && children > 1) isAP[vertex] = 1;
}
void solve(int n) {
    int time = 0;
    for (int i = 0; i < n; i++)visited[i] = isAP[i] = disc[i] = low[i] = 0;
    for (int i = 0; i < n; i++)if(!visited[i])ArticulationPoints(i, time, -1);
    for (int i = 0; i < n; i++)if(isAP[i])cout << i << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        solve(n);
    }
    return 0;
}
// 5 6
// 0 1
// 1 2
// 0 2
// 2 3
// 3 4
// 2 4
// https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
