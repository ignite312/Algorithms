#include<bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
vector<int> adj[N+5];
int n, m;

void dfs(int vertex, vector<bool> &visited) {
    visited[vertex] = true;
    for (auto child : adj[vertex]) {
        if (!visited[child]) {
            dfs(child, visited);
        }
    }
}
bool isConnected() {
    vector<bool> visited(n+1, false);
    dfs(1, visited);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            return false;
    }
    return true;
}
int countOddDegree() {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 != 0) {
            ++count;
        }
    }
    return count;
}
bool hasEulerianCircuit() {
    if (!isConnected())
        return false;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() % 2 != 0)
            return false;
    }
    return true;
}
bool hasEulerianPath() {
    if (!isConnected()) {
        return false;

    }
    int oddDegreeCount = countOddDegree();
    return oddDegreeCount == 0 || oddDegreeCount == 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  while(tt--) {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(hasEulerianPath())cout << "Has Euler Path\n";
    if(hasEulerianCircuit())cout << "Has Euler Circuit" << "\n";
}
}
