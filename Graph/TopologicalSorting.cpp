#include<bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
vector<int> G[N+5], ans;
bool vis[N+5];
int n, m;

void dfs(int v) {
    vis[v] = true;
    for(int u : G[v]) 
    	if(!vis[u])
            dfs(u);
    ans.push_back(v);
}
void topologicalSort() {
    for(int i = 1; i <= n; ++i)
    	if(!vis[i])
        	dfs(i);
    reverse(ans.begin(), ans.end());
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    topologicalSort();
    for(auto ele : ans)cout << ele << " ";
}
// 5 6
// 1 2
// 2 5
// 1 4
// 2 4
// 4 3
// 1 3
