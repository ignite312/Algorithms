#include<bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
vector<int> G[N+5], RG[N+5], order, comp;
vector<vector<int>> components;
vector<bool> vis;
int n, m;

void dfs(int vertex) {
    vis[vertex] = true;
    for(int child : G[vertex]) 
    	if(!vis[child])
            dfs(child);
    order.push_back(vertex);
}
void dfs2(int vertex) {
    vis[vertex] = true;
    comp.push_back(vertex);
    for(auto child : RG[vertex])
        if(!vis[child])
            dfs2(child);
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        RG[v].push_back(u);
    }
    vis.assign(n+1, false);
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    reverse(order.begin(), order.end());

    vis.assign(n+1, false);
    for(auto ele : order) {
        if(!vis[ele])dfs2(ele);
        if(comp.size())components.push_back(comp);
        comp.clear();
    }
    for(auto ele : components) {
        for(auto i : ele) {
            cout << i << " ";
        }cout << "\n";
    }
}
// 7 8
// 1 2
// 2 4
// 4 7
// 2 3
// 3 1
// 4 5
// 5 6
// 6 4
