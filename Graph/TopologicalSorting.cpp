#include<bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
vector<int> G[N+5], ans;
bool vis[N+5];

void dfs(int v) {
    vis[v] = true;
    for(int u : G[v]) 
        if(!vis[u])
            dfs(u);
    ans.push_back(v);
}
void topologicalSort(int n) {
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    reverse(ans.begin(), ans.end());
    for(auto ele : ans)cout << ele << " ";
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
        topologicalSort(n);
    }
    return 0;
}
