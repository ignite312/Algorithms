#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
vector<pair<int, int>> br;
vector<int> adj[N+5];
int low[N+5], disc[N+5], Time = 0;

void dfsBR(int vertex, int parent) {
  low[vertex] = disc[vertex] = ++Time;
  for (auto child : adj[vertex]) {
    if (child == parent) continue;
    if (!disc[child]) {
      dfsBR(child, vertex);
      if (disc[vertex] < low[child])// The condition that different from "Articulation Point"
        br.push_back({vertex, child});
      low[vertex] = min(low[vertex], low[child]);
    } else
      low[vertex] = min(low[vertex], disc[child]);
  }
}
void BR(int n) {
  for (int i = 1; i <= n; i++)
    if (!disc[i])
      dfsBR(i, -1);
  for(auto ele : br)cout << ele.first << " " << ele.second << "\n";
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
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        BR(n);
    }
    return 0;
}
// 6 7
// 0 1
// 1 2
// 0 2
// 2 3
// 3 4
// 2 4
// 4 5
// https://codeforces.com/blog/entry/71146
